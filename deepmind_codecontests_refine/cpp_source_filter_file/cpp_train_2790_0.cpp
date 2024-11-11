#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N=2005;
int n,sz[N],dp[N],ans=1<<30;
char str[N];vector<int>E[N];
void dfs(int u,int f){
	sz[u]=str[u]-'0';dp[u]=0;
	for(int v:E[u])
		if(v!=f){
			dfs(v,u);sz[u]+=sz[v];
			dp[u]+=dp[v]+sz[v];
		}
}
int calc(int u,int f){
	int son=0;
	for(int v:E[u])
		if(v!=f&&dp[v]+sz[v]>dp[son]+sz[son])
			son=v;
	if(!son)return 0;
	int val=calc(son,u)+sz[son];
	if(dp[u]-dp[son]-sz[son]>=k)
		return dp[u]&1;
	else
		return val-(dp[u]-dp[son]-sz[son]);
}
int main(){
	scanf("%d%s",&n,str+1);
	for(int i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		E[x].push_back(y);E[y].push_back(x);
	}
	for(int i=1;i<=n;++i){
		dfs(i,0);
		if(!calc(i,0))ans=min(ans,dp[i]>>1);
	}
	printf("%d\n",ans==1<<30?-1:ans);
	return 0;
}
