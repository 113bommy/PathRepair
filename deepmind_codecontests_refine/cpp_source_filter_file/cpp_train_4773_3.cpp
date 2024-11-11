#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int N;
vi g[200010];
int pr[200010];
int gr[200010];
int ot[200010];
set<int> st[200010];

int main() {
	cin >> N;

	rep(i, N) {
		int p;
		cin >> p;
		--p;
		g[p].pb(i);
		pr[i] = p; 
	}

	queue<int> que;

	memset(gr, -1, sizeof(gr));

	rep(i, N) {
		ot[i] = (int)g[i].size();
		if (ot[i] == 0) {
			que.push(i);
		}
	}

	while (!que.empty()) {
		int v = que.front(); que.pop();
		int x = 0;
		while (st[v].count(x)) ++x;
		gr[v] = x;
		
		if (--ot[pr[v]] == i) {
			que.push(pr[v]);
		}

		st[pr[v]].insert(x);
	}

	int rt;
	rep(i, N) {
		if (gr[i] == -1) {
			rt = i;
			break;
		}
	}

	vi cand;

	rep(i, N) {
		if (!st[rt].count(i)) {
			cand.pb(i);
			if (cand.size() == 2) {
				break;
			}
		}
	}

	bool ok = 0;

	rep(ii, 2) {
		gr[rt] = cand[ii]; 
		int v = rt;

		while (pr[v] != rt) {
			int x = 0;
			while (st[pr[v]].count(x) || gr[v] == x) ++x;
			gr[pr[v]] = x;
			v = pr[v];
		}

		int x = 0;

		set<int> ss;
		for (int to : g[rt]) {
			ss.insert(gr[to]);
		}

		while (ss.count(x)) ++x;
		if (gr[rt] == x) {
			ok = 1;
			break;
		}
	}

	puts(ok ? "POSSIBLE" : "IMPOSSIBLE");

	return 0;
}