#include<cstdio>
#include<cmath>
int main(){for(float a,l,x;~scanf("%f%f%f",&a,&l,&x);printf("%.9f\n",sqrt(l*l-a*a/4)*a/2+sqrt(x*x/4-l*l/4)*l))x+=l;}