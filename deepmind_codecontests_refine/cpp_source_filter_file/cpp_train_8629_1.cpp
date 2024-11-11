#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)

typedef long long ll;

ll dp[2000][2000];
int cake[2000];
int n;

ll dfs(int a, int b, bool f) {
	if (dp[a][b]) return dp[a][b];
	if (a == b) {
		if (f) return dp[a][b] = cake[a];
		else return dp[a][b] = 0;
	}
	
	ll res = 0;
	if (f) {
		res = max(dfs((a + 1) % n, b, !f) + cake[a], dfs(a, (b + n - 1) % n, !f) + cake[b]);
	}
	else {
		if (cake[a] < cake[b])
			res = dfs(a, (b + n - 1) % n, !f);
		else
			res = dfs((a + 1) % n, b, !f);
	}
	
	return dp[a][b] = res;
}

int main() {
	cin >> n;
	REP(i, n) scanf("%d", &cake[i]);.
	
	ll ans = 0;
	REP(i, n) ans = max(ans, dfs((i + 1) % n, (i + n - 1) % n, false) + cake[i]);
	cout << ans << endl;
	return 0;
}