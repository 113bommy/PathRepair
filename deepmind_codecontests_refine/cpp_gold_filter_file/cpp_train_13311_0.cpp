#include <iostream>

int main(){
	int n,debt=100000;
	std::cin>>n;
	for(int i=0;i<n;i++){
		debt*=1.05;
		debt=debt%1000 ? debt/1000*1000+1000 : debt;
	}
	std::cout<<debt<<'\n';
	return 0;
}