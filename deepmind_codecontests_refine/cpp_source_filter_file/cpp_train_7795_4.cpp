#include <iostream>

int main(){
	int b1,b2,b3;
	std::cin>>b1>>b2>>b3;
	if(b1==b2 && b1==1 || b3==1)std::cout<<"Open"<<std:endl;
	else std::cout<<"Close"<<std::endl;
	return 0;
}