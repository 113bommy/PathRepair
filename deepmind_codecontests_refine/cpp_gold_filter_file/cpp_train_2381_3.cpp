#include <iostream>
#include <cstdio>
using namespace std; 
int main()
{
double a,b,c,d,e,f;
while(cin>>a>>b>>c>>d>>e>>f)
{
printf("%.3f %.3f\n", (b*f - c*e)/(b*d - a*e)+0.0001, (a*f - c*d)/(a*e - b*d)+0.0001);
}
return 0;
}