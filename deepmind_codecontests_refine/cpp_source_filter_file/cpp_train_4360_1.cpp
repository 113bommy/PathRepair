#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

const max=104729;
char so[104730];

int main(){
	int i,j,n,s;
	
	memset(so,0,sizeof(so));
	
	so[0]=so[1]=1;
	
	for(i=2;i*i<=max;i++){
		for(j=2*i;j<=max;j+=i){
			so[j]=1;
		}
	}
	while(0<=scanf("%d",&n)){
		if(n==0)break;
		s=0;
		for(i=1;n;i++){
			if(so[i]==0){
				s+=i;
				--n;
			}
		}
		printf("%d\n",s);
	}
	return 0;
}