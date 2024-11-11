#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main() 
{ 
	ll n, m,ans=0,a,b; cin >> n >> m;	
 	priority_queue<ll> que;
	vector<vector<int>> d(100010, vector<int>());
	for (int i = 0; i < n; i++) 
		cin >> a >> b , d[a].push_back(b);
	for (int i = 1; i < m+1; i++) 
    {
		for (int j = 0; j < d[i].size(); j++) 
			que.push(d[i][j]);
		if (!que.empty()) 
			ans += que.top() , que.pop();
	}
	cout << ans << endl;
	return 0;
}