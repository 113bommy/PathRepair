#include <bits/stdc++.h>
using namespace std;

static vector<long long> adj[100005];
static long long arr[100005];

long long dfs(long long u, long long p){
	if(adj[u].size() == 1) return arr[u];
	long long rope = 0;
	long long maxChildRope = 0;
	for(long long v : adj[u]){
		if(v == p) continue;
		long long childRope = dfs(v,u);
		rope += childRope;
		maxChildRope = max(maxChildRope, childRope);
	}

	long long connect = rope - arr[u];
	long long maxConnect = min(rope / 2, rope - childRope); 
	rope = rope - 2 * connect;
	if(connect < 0 || rope < 0 || connect > maxConnect){
		cout << "NO";
		exit(0);
	}
	return rope;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long n; cin >> n;
	for(long long i = 1;i <= n;i++) cin >> arr[i];
	for(long long i = 1;i < n;i++){
		long long a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	} 
	for(long long i = 1;i <= n;i++){
		if(adj[i].size() != 1){
			if(dfs(i,0) == 0) cout << "YES";
			else cout << "NO";
			return 0;
		}
	}
	if(arr[1] == arr[2]) cout << "YES";
	else cout << "NO";
}
