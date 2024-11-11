#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
const double eps = 1e-6;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e2 + 10;
const int maxm = 1e5 + 10;
vector<int> g[maxn];
int x[maxn], y[maxn];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
bool dfs(int idx, int dr, int fr, int st) {
  if (g[idx].size() > 4) return false;
  vector<int> a, b;
  for (int i = 0; i < g[idx].size(); i++)
    if (g[idx][i] != fr) a.emplace_back(g[idx][i]);
  for (int i = 0; i < 4; i++)
    if (i != dr) b.emplace_back(i);
  int dis = 1 << st;
  for (int i = 0; i < a.size(); i++) {
    x[a[i]] = x[idx] + dis * dir[b[i]][0];
    y[a[i]] = y[idx] + dis * dir[b[i]][1];
    if (!dfs(a[i], (b[i] + 2) % 4, idx, st - 1)) return false;
  }
  return true;
}
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  if (!dfs(1, -1, 0, 30))
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) cout << x[i] << " " << y[i] << endl;
  }
  return 0;
}
