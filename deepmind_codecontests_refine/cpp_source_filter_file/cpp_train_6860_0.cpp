#include<stdio.h>
int main(){
	int n[1006]={0},m[1006]={0},k=0,i,N,M;
	for(;;k=0){
		scanf("%d%d",&N,&M);
		if(M==0&&M==0)break;
		for(i=0;i<N;i++){scanf("%d",&n[i]);
		for(i=0;i<M;i++)scanf("%d",&m[i]);
		for(i=0;;i++){
			k+=m[i];
			k+=n[k];
			if(k>=N-1)break;
		}	
		printf("%d\n",i+1);
	}
	return 0;
}