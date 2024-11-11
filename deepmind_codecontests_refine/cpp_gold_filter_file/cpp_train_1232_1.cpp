#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i=0;i<n;i++)


int n;
int a,b;
long c;
int q;
int k;
int x,y;
long ans[100001];
bool used[100001];
vector<pair<int,long>>v[100001];


void dfs(int s,int p,long d){
    ans[s]=d;
	for(int i=0;i<(int)v[s].size();i++){
	    if(v[s][i].first!=p)dfs(v[s][i].first,s,d+v[s][i].second);
	}
}
int main(){
	cin>>n;
	rep(i,n-1){
		cin>>a>>b>>c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	cin>>q>>k;
	for(int i=1;i<=n;i++)ans[i]=10000000000000000;
	dfs(k,0,0)
	rep(i,q){
		cin>>x>>y;
		cout<<ans[x]+ans[y]<<endl;
	}
	return 0;
}
