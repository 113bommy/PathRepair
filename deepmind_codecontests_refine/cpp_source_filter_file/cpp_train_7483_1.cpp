#include<stdio.h>
int main(void)
{
	int n,a,b,c,d,e,f,g,h,X[1000],Z[1000],W[1000],P[1000];
	while(1){
	scnaf("%d",&n);
	if(n==0)break;
	for(i=0;i<n;i++){
	scanf("%d %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g,&h);
		X[i]=(a*e)+(-1*f*b)+(-1*g*c)+(-1*h*d);
		Z[i]=(a*f)+(e*b)+(h*c)+(-1*g*d);
		W[i]=(a*g)+(-1*h*b)+(e*c)+(f*d);
		P[i]=(a*h)+(g*b)+(-1*f*c)+(d*e);
	 }
	for(i=0;i<n;i++){	
	printf("%d %d %d %d\n",X[i],Z[i],W[i],P[i]);
  }
  return 0;
} 