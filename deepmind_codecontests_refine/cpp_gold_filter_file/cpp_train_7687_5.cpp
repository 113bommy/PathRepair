#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 8;
vector <int> g[MAXN+1];
int n,m;
long long int res=0;
void dfs(int v, long long int mask){
	if(mask==((1LL<<n)-1)){
		res+=1;
	}
	else{
		for(int i=0; i<g[v].size(); i++){
			if(!((1LL<<g[v][i])&(mask))){
				dfs(g[v][i], mask|(1LL<<g[v][i]));
			}
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int u,v;
		cin>>u>>v;
		g[u-1].push_back(v-1);
		g[v-1].push_back(u-1);
	}

	dfs(0,1);

	cout<<res<<endl;
}