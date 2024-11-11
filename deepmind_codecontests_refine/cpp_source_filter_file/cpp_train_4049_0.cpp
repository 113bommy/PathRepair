#include<stdio.h>
int main(void)
{
	int n,t,i,k,h,x,w;
	w=0;
	while(1){
	scanf("%d",&n);
	if(n==0) break;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d %d",&k,&h);
		w+=h-k;
		}
	if(n=<w){
		printf("OK\n");
		}
	else{
		x=n-w;
		printf("%d\n",x);
		}
	w=0;	
	}
		return 0;
}