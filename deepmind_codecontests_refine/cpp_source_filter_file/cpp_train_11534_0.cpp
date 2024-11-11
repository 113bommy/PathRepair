#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x){
	read("%d",&x);
}
void write(ll x){
	if (x>9) write(x/10);
	putchar(x%10+'0'); 
}
int n,a[200004],sub[200004];
vector<int>g[200004],v[200004];
ll ans[200004];
int ans1[200004],res[200004];
void dfs(int x,int par){
	sub[x]=1;
	for (int i=0;i<g[x].size();i++)if(g[x][i]!=par)
		dfs(g[x][i],x),sub[x]+=sub[g[x][i]];
}
void dfs1(int x,int par){
	if (v[a[x]].empty()) ans1[a[x]]-=sub[x];
	else res[v[a[x]][v[a[x]].size()-1]]-=sub[x];
	for (int i=0;i<g[x].size();i++) if (g[x][i]!=par){
		v[a[x]].push_back(g[x][i]);
		dfs1(g[x][i],x);
		ans[a[x]]+=1ll*res[g[x][i]]*(res[g[x][i]]+1)/2;
		v[a[x]].pop_back(); 
	}
}
int x,y;
ll A;
int main(){
	read(n),A=1ll*n*(n+1)/2;
	for (int i=1;i<=n;i++) read(a[i]),ans1[i]=n;
	for (int i=1;i<n;i++)read(x),read(y),g[x].push_back(y),g[y].push_back(x); 
	dfs(1,-1);
	for (int i=1;i<=n;i++) res[i]=sub[i];
	dfs1(1,-1);
	for (int i=1;i<=n;i++){
		ll res=A-ans[i]-1ll*ans1[i]*(ans1[i]+1)/2;
		write(res),puts("");
	}
}