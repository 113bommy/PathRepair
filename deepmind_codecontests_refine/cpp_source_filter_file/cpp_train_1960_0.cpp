#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MOD=998244353;
const int maxn=4005;
int n,k;
int po[maxn],C[maxn][maxn];
inline void ini(){
	po[0]=1;
	for(register int i=1;i<maxn;i++)po[i]=(po[i-1]*2)%MOD;
	c[0][0]=1;
	for(register int i=1;i<maxn;i++){
		C[i][0]=1;
		for(register int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	}
}
int c(int n,int m){
	if(m<0||n<0)return 0;
	return C[n][m];
}
inline int calc(int x,int n,int k){
	int ans=0;
	int tot=max(0,x/2-max(0,x-1-k));
	for(register int i=0;i<=tot;i++){
		ans=(1LL*(po[i]*C[tot][i]%MOD)*c(n+k-2*tot-1,k-tot*2+i-1)+ans)%MOD;
	}
	return ans;
}
int main(){
	ini();
	scanf("%d%d",&k,&n);
	for(register int i=2;i<=2*k;i++){
		if(i&1){
			printf("%d\n",calc(i,n,k));
		}
		else {
			printf("%d\n",(calc(i-1,n,k-1)+calc(i-1,n-1,k-1))%MOD);
		}
	}
}