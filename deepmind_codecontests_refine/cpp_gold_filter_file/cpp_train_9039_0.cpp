#include<bits/stdc++.h>
using namespace std;

const int MAX = 1234567;

vector<int> g[MAX];
int n;
int dfs (int v, int r) {
	int res = 0;
	for (auto u : g[v])
		if (u != r)
			res ^= dfs (u, v);

	return res + 1;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i =  0; i < n-1; i++) {
		int a, b;
		cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	cout << (dfs (0,-1)==1 ? "Bob" : "Alice") << endl;
	return 0;
}
