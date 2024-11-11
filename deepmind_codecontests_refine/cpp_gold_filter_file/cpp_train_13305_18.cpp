#include <iostream>
int main(){
	int a,b;
	std::cin>>a>>b;
	if(b%a==0)std::cout<<a+b;
	else std::cout<<b-a;
	return 0;
}
