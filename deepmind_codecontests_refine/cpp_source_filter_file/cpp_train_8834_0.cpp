#include <iostream>
#include <cstdio>
int main(){
	double i=1e+64,a=0,t;
	while(std::cin>>t){
		if(t<i)i=t;
		if(t>a)a=t;
	}
	printf("%f\n", maxi-mini);
}