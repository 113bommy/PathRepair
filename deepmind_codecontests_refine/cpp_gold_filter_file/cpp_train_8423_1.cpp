#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
int n, m, k, p, dist[6007][2017], c[3000]; bool u[3000];
vector<string>v; string a[3000], b[3000], s1, s2; vector<pair<int, int>>x[7000];
int s(string Y) { return lower_bound(v.begin(), v.end(), Y) - v.begin(); }
int main() {
	while (true) {
		cin >> m >> k >> p; p *= 10; if (m + k + p == 0)return 0; v.clear(); cin >> s1 >> s2;
		for (int i = 0; i < m; i++) { cin >> a[i] >> b[i] >> c[i]; v.push_back(a[i]); v.push_back(b[i]); }
		sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); n = v.size();
		for (int i = 0; i < n; i++) { x[i].clear(); u[i] = false; for (int j = 0; j <= p; j++)dist[i][j] = 1e9; }
		for (int i = 0; i < m; i++) { int pos1 = s(a[i]), pos2 = s(b[i]); x[pos1].push_back(make_pair(pos2, c[i])); x[pos2].push_back(make_pair(pos1, c[i])); }
		priority_queue<tuple<short, short, short>, vector<tuple<short, short, short>>, greater<tuple<short, short, short>>>Q;
		for (int i = 0; i < k; i++) { string U; cin >> U; u[s(U)] = true; }
		
		Q.push(make_tuple(0, s(s1), p)); dist[s(s1)][p] = 0;
		while (!Q.empty()) {
			int a1 = get<0>(Q.top()), a2 = get<1>(Q.top()), a3 = get<2>(Q.top()); Q.pop();
			for (pair<int, int>i : x[a2]) {
				int cap = a3 - i.second; if (cap < 0)continue; if (u[i.first] == true)cap = p;
				if (dist[i.first][cap] > dist[a2][a3] + i.second) {
					dist[i.first][cap] = dist[a2][a3] + i.second; Q.push(make_tuple(dist[i.first][cap], i.first, cap));
				}
			}
		}
		int maxn = 1e9; for (int i = 0; i <= p; i++)maxn = min(maxn, (int)dist[s(s2)][i]); if (maxn > 1e8)maxn = -1;
		cout << maxn << endl;
	}
	return 0;
}