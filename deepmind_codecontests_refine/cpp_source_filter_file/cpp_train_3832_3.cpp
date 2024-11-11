#include <iostream>
#include <vector>
using namespace std;
const int MAXN=100005;
int n;
vector<pair<int,int> > v[MAXN]; //不喜欢 :\
int color[MAXN];

void dfs(int no,int father)
{
	for (int i=0;i<v[no].size();i++){
		int u=v[no][i].first;
		int w=v[no][i].second%2;
		if (u!=father){
			color[u]=color[no]^w;
			dfs(u,no);
		}
	}
}

int main()
{
	cin>>n;
	for (int i=1;i<n;i++){
		int u,vv,c;
		cin>>u>>vv>>c;
		v[u].push_back({vv,c});
		v[vv].push_back({u,c});
	}

	dfs(1,-1);

	for (int i=1;i<=n;i++){
		cout<<color[i]<<endl;
	}
	return 0;
}
