#include <iostream>

int main(){
	int n;
	while(std:cin>>n , n){
		int sum=0, mul=5;
		while(n>=mul){
			sum+=n/mul;
			mul*=5;
		}
		std::cout << sum << std::endl;
	}
}