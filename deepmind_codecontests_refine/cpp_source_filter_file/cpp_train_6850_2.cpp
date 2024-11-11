#include <bits/stdc++.h>
using namespace std;

int n,m,u,v,s,tt,i,j,used[300005]={0},co[300005]={0};
vector<int> d[300005];
queue<int> que;

int main() {
	// your code goes here
	cin >> n >> m;
	for(i=1;i<=m;i++){
		cin >> u >> v;
		d[u].push_back(n+v);
		d[n+u].push_back(2*n+v);
		d[2*n+u].push_back(v);
	}
	for(i=1;i<=3*n;i++){
			co[i]=100000000;
	}
	cin >> s >> tt;
	co[s]=0;
	dfs(s);
	used[s]=1;
	que.push(s);
	while(!que.empty()){
		u=que.front();
		que.pop();
		for(i=0;i<d[u].size();i++){
			used[d[u][i]]=1;
			if(co[d[u][i]]>co[u]+1){
				co[d[u][i]]=co[u]+1;
				que.push(d[u][i]);
			}
		}
	}
	if(used[tt]==0) cout << "-1" << endl;
	else if(co[tt]==100000000) cout << "-1" << endl;
	else cout << co[tt]/3 << endl;
	return 0;
}