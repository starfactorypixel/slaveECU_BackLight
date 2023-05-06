#include <PowerOutputs.h>



namespace Output
{

PowerOutputs<6> pout;

void OnShortCircuit(uint8_t num, uint16_t current)
{

}

inline void Setup()
{
	pout.AddPort( {GPIOB, GPIO_PIN_11, ADC_CHANNEL_6} );
	pout.AddPort( {GPIOB, GPIO_PIN_10, ADC_CHANNEL_5} );
	pout.AddPort( {GPIOB, GPIO_PIN_2, ADC_CHANNEL_4} );
	pout.AddPort( {GPIOB, GPIO_PIN_1, ADC_CHANNEL_3} );
	pout.AddPort( {GPIOB, GPIO_PIN_0, ADC_CHANNEL_2} );
	pout.AddPort( {GPIOA, GPIO_PIN_7, ADC_CHANNEL_1} );

	//pout.On(1);
	//pout.Off(1);
	//pout.RegShortCircuitEvent(OnShortCircuit);
	//pout.Current(1);
	
	return;
}

inline void Loop(uint32_t &current_time)
{
	pout.Processing(current_time);
	
	// Обновляем текущее время, чтобы все последующий вызовы текущего loop получили его актуальным.
	current_time = HAL_GetTick();
	
	return;
}

}
