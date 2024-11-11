#include <bits/stdc++.h>
//#define int long long
using namespace std;

int n,m,deg[100010],a[100010];
vector<int> v[100010];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n+m-1;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		//g[y].push_back(x);
		deg[y]++;
	}
	int root=-1;
	for(int i=1;i<=n;i++) if(deg[i]==0){
		root=i;
		break;
	}
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		for(int i=0;i<v[t].size();i++){
			int pos=v[t][i];
			deg[pos]--;
			if(deg[pos]==0){
				a[pos]=t;
				q.push(pos);
			}
		}
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<endl;
	return 0;
}