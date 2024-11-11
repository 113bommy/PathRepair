#include<stdio.h>
int main(){
	int n,k,a=1;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		if(a<k)
			a*=2
		else
			a+=k;
		}
	printf("%d",a);
	return 0;
	}
