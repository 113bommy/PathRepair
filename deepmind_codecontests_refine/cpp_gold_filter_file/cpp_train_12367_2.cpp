#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100010
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,a[N],b[N],pa[N],pb[N],pos[N],vis[N];
bool Solve(){
	for(int i=1;i<=n;++i){
		pa[i]=pb[i]=i;
	}
	sort(pa+1,pa+n+1,[&](int i,int j){return a[i]<a[j];});
	sort(pb+1,pb+n+1,[&](int i,int j){return b[i]<b[j];});
	for(int i=1;i<=n;++i){
		if(a[pa[i]]>b[pb[i]])return false;
	}
	for(int i=1;i<n;++i){
		if(a[pa[i+1]]<=b[pb[i]])return true;
	}
	for(int i=1;i<=n;++i){
		pos[pa[i]]=pb[i];
	}
	int cnt=0,u=n;
	while(!vis[u]){
		vis[u]=1;
		u=pos[u];
		++cnt;
	}
	return cnt<n;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		b[i]=read();
	}
	printf(Solve()?"Yes\n":"No\n");
	return 0;
}
