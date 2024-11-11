#include <iostream>
int main(){
	double x0,y0,x1,y1,x,y,s=0;
	char c;
	std::cin>>x0>>c>>y0;
	x1=x0;y1=y0;
	while(std::cin>>x>>c>>y){
		s+=x1*y-y1*x;
		x1=x;y1=y;
	}
	s+=x1*y0-y1*x0;
	std::cout<<(s<0?-s:s)/2<<"\n";
}