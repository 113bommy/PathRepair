#pragma GCC optimize("Ofast")
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int n,num[200005],ans[200005];
vector<int> g[200005],dp(200005,2147483647);
void DFS(int v,int p){
	auto x=lower_bound(dp.begin(),dp.begin()+n,num[v]);
	int y=*x;
	*x=num[v];
	ans[v]=lower_bound(dp.begin(),dp.begin()+n,2147483647)-dp.begin();
	for(auto z:g[v])
		if(z!=p)
			DFS(z,v);
	*x=y;
}
int main(){
	int i,from,to;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&num[i]);
	for(i=0;i<n-1;i++){
		scanf("%d%d",&from,&to);
		g[from].emplace_back(to);
		g[to].emplace_back(from); 
	}
	DFS(1,-1);
	for(i=1;i<=n;i++)
		printf("%d\n",ans[i]);
}