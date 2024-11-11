#include <bits/stdc++.h>
using namespace std;

const int M = 2e5 + 100;
vector<int> e[M];
int a[M], ans[M];
multiset<int> st;

void dfs(int u, int pre) {
	st.insert(a[u]);
	int era = -1;
	auto it = st.lower_bound(a[u]);
	if (++it != st.end()) {
		era = *it;
		st.erase(it);
	}
	ans[u] = st.size();
	for (auto v : e[u]) {
		if (v != pre) {
			dfs(v, u);
		}
	}
	if (era != -1) st.insert(era);
	st.erase(s.find(a[u]));
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		--u, --v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(0, -1);
	for (int i = 0; i < n; i++) cout << ans[i] << "\n";
}