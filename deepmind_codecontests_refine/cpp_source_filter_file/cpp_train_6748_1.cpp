#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

int main(){
	int n,m;
	string s; cin>>n>>m>>s;
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		G[u].emplace_back(v);
		if(u!=v) G[v].emplace_back(u);
	}

	vector<vector<int>> deg(2,vector(n,0));
	rep(u,n) for(int v:G[u]) deg[s[v]-'A'][u]++;

	vector<bool> del(n);
	queue<int> Q;
	rep(u,n) if(deg[0][u]==0 || deg[1][u]==0) {
		del[u]=true;
		Q.emplace(u);
	}
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		for(int v:G[u]) if(!del[v]) {
			deg[s[u]-'A'][v]--;
			if(deg[0][v]==0 || deg[1][v]==0){
				del[v]=true;
				Q.emplace(v);
			}
		}
	}

	puts(count(del.begin(),del.end(),false)>0?"Yes":"No");

	return 0;
}
