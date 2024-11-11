#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > v;
int n, rev[5] = {2, 3, 0, 1};
long long x[33], y[33];
void dfs(int u, int p, int dir, int len) {
  vector<int> av;
  for (int i = 3; i >= 0; i--)
    if (i != rev[dir]) av.push_back(i);
  for (int i = 0; i < v[u].size(); i++) {
    if (v[u][i] == p) continue;
    int nx = av.back();
    av.pop_back();
    x[v[u][i]] = x[u];
    y[v[u][i]] = y[u];
    if (nx == 0) y[v[u][i]] = y[u] + (1LL << len);
    if (nx == 1) x[v[u][i]] = x[u] + (1LL << len);
    if (nx == 2) y[v[u][i]] = y[u] - (1LL << len);
    if (nx == 3) x[v[u][i]] = x[u] - (1LL << len);
    dfs(v[u][i], u, nx, len - 1);
  }
}
int main() {
  scanf("%d", &n);
  v.resize(n + 1);
  for (int i = 1; i < n; i++) {
    int xx, yy;
    cin >> xx >> yy;
    v[xx].push_back(yy);
    v[yy].push_back(xx);
  }
  for (int i = 1; i <= n; i++)
    if (v[i].size() >= 5) return !printf("NO");
  cout << "YES\n";
  dfs(1, -1, -1, 40);
  for (int i = 1; i <= n; i++) cout << x[i] << ' ' << y[i] << endl;
}
