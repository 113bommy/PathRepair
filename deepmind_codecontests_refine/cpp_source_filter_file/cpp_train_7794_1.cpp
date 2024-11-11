#include <bits/stdc++.h>


#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)

using namespace std;

vector<int> ans, usd(22), g[22];

void dfs(int s){
	if(usd[s]) return;
	usd[s]=1;
	for(auto v: g[s]) if(!usd[v]) dfa(v);
	ans.push_back(s);

}


int main()
{
	
	int n,m;
	cin >> m >> n;
	rep(i,n){
		int x,y; cin >>x >>y;
		g[x-1].push_back(y-1);
	}
	rep(i,m) dfs(i);
	for(int i=ans.size()-1;i>=0;i--) printf("%d\n",ans[i]+1);
	return 0;
}