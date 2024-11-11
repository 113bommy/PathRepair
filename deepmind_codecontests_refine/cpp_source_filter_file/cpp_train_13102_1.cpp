​
#include<bits/stdc++.h>
using namespace std;
long long n,x[111111],p[111111],y[111111],siz[111111],cir[111111],m,k,sum;
bool vis[111111];
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&x[i]),p[i]=i,y[i]=x[i]-x[i-1];
	scanf("%lld%lld",&m,&k);
	for(int i=1,a;i<=m;i++)scanf("%lld",&a),swap(p[a],p[a+1]);
	for(int i=1,c,pos,cnt=0;i<=n;i++)if(!vis[i]){
		++cnt,c=0,pos=i;
		while(!vis[pos])vis[pos]=1,cir[pos]=cnt,++c,pos=p[pos];
		siz[cnt]=c;
	}
	for(int i=1;i<=n;i++){
		int t=k%siz[cir[i]],pos=i;
		while(t--)pos=p[pos];
		printf("%lld.0\n",y[pos]+sum),sum+=y[pos];
	}
}

​