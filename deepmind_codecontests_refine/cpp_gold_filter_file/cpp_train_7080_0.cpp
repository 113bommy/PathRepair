#include<iostream>
#include<math.h>
struct Point{
	double x;
	double y;
};
void gohho(int n,Point a,Point b){
	if(n==0)
	return;
	Point s,t,u;
	double yh=M_PI*60.0/180.0;
	s.x=(2.0*a.x+1.0*b.x)/3.0;
	s.y=(2.0*a.y+1.0*b.y)/3.0;
	t.x=(1.0*a.x+2.0*b.x)/3.0;
	t.y=(1.0*a.y+2.0*b.y)/3.0;
	u.x=(t.x-s.x)*cos(yh)-(t.y-s.y)*sin(yh)+s.x;
	u.y=(t.x-s.x)*sin(yh)+(t.y-s.y)*cos(yh)+s.y;
	gohho(n-1,a,s);
	std::cout<<s.x<<"  "<<s.y<<"\n";
	gohho(n-1,s,u);
	std::cout<<u.x<<"  "<<u.y<<"\n";
	gohho(n-1,u,t);
	std::cout<<t.x<<"  "<<t.y<<"\n";
gohho(n-1,t,b);
}
int main(){
	Point a,b;
	int n;
	std::cin>>n;
	a.x=0;
	a.y=0;
	b.x=100;
	b.y=0;
	std::cout<<a.x<<"  "<<a.y<<"\n";
	gohho(n,a,b);
	std::cout<<b.x<<"  "<<b.y<<"\n";
return 0;
}
