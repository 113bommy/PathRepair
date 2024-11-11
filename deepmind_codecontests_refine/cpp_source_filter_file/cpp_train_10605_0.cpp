#include<iostream>
double m(double a,double b){return a>b?a:b;}
main(){for(double a,b,c,d,e,f,g,h;std::cin>>a>>b>>c>>d>>e>>f>>g>>h;){if(((m(e,g)+m(-a,-c))*(m(a,c)+m(-e,-g))>=0)&&((m(f,h)+m(-b,-d))*(m(b,d)+m(-f,-))>=0))std::cout<<"YES\n";else std::cout<<"NO\n";}}