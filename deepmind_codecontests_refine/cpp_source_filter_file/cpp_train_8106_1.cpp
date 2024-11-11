#include <stdio.h>
#include <string.h>
void cpy(int src[],int dst[],int n){
	for(int i=0;i<n;i++) dst[i]=src[i];
}
void OFA(int S[],int n){
	int num[100];
	memset(num,0,sizeof(num));
	for(int i=0;i<n;i++) num[S[i]]++;
	for(int i=0;i<n;i++) S[i]=num[S[i]];
}

bool check(int S[],int tmp[],int n){
	for(int i=0;i<n;i++) if(S[i]!=tmp[i]) return false;
	return true;
}

int main(){
	int S[12],tmp[12],n,count;
	while(1){
		scanf("%d",&n);
		if(!n) break;
		count=-1;
		for(int i=0;i<n;i++) scanf("%d",&S[i]);
		cpy(S,tmp,n);
		do{
			cpy(tmp,S,n);
			OFA(tmp,n);
			//for(int i=0;i<n;i++) printf("%d ",tmp[i]);
			count++;
		}while(!check(S,tmp,n));
		printf("%d\n",count);
		for(int i=0;i<n-1;i++) printf("%d ",S[i]);
		printf("%d\n",S[i]);
	}
	return 0;
}