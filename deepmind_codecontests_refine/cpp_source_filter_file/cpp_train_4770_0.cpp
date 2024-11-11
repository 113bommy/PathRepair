#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,M,to[200005],next[200005],head[200005],cnt=1;
int f[200005],S[200005],L[200005],R[200005],p[200005],dp[200005];
inline void add(int u,int v) {
	to[cnt]=v;next[cnt]=head[u];head[u]=cnt++;
	to[cnt]=u;next[cnt]=head[v];head[v]=cnt++;
}
void dfs(int cur,int fa){
	int cnt=0;
	f[cur]++;
	for(int i=head[cur];i;i=next[i])
		if(to[i]!=fa){
			dfs(to[i],cur);
			f[cur]=f[cur]*f[to[i]]%M;
		}
	for(int i=head[cur];i;i=next[i])
		if(to[i]!=fa)
			p[++cnt]=to[i];
	f[cur]++;f[cur]%=M;
	L[0]=R[cnt+1]=1;
	for(int i=1;i<=cnt;i++)	L[i]=L[i-1]*f[p[i]]%M;
	for(int i=cnt;i>=1;i--)	R[i]=R[i+1]*f[p[i]]%M;
	for(int i=1;i<=cnt;i++)	S[p[i]]=L[i-1]*R[i+1]%M;
}
void dfs2(int cur,int fa){
	if(cur==1) dp[cur]=1;
	else	dp[cur]=(S[cur]*dp[fa]+1)%M;
	for(int i=head[cur];i;i=next[i])
		if(to[i]!=fa) dfs2(to[i],cur);
}
signed main(){
	cin>>n>>M;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		add(u,v);
	}
	dfs(1,1);
	dfs2(1,1);
	for(int i=1;i<=n;i++)	cout<<dp[i]*(f[i]+M-1)%M<<endl;
    return 0;
}