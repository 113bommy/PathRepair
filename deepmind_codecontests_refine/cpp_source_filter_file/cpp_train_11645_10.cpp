#include <iostream>

int main()
{
	long N, A, B;
	std::cin >> N >> A >> B;
	std::cout <<  std::max( 0, ( A + B * ( N - 1 ) ) - ( A * ( N - 1 ) + B ) + 1 ) << std::endl;

	return 0;
}