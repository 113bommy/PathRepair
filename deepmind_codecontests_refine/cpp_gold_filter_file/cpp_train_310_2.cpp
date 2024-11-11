#include<stdio.h>
#include<math.h>
int prime(int a){
	int i,c=0;
	for(i=1;i<=sqrt(a);i++){
		if(a%i==0 && i!=1){
			c=1;
		}
	}
	if(c==1){
		return 0;
	}else{
		return 1;
	}
}
int main(void){
	int n,co=0;
	while(scanf("%d",&n)==1){
		if(prime(n)==1){
			co++;
		}
	}
	printf("%d\n",co);
}