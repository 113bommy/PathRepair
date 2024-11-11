#include<stdio.h>
int main(){
	int a,x,Max=-1000000,min=1000000;
	long long int sum=0;
	scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d",&x);
		sum = sum + x;
		if(Max<x[i]){
			Max = x;
		}
		if(min>x){
			min = x;
		}
	}
	printf("%d %d %lld\n",min,Max,sum);
	return 0;
}