#include <bits/stdc++.h>
using namespace std;
const int MAXN = 400 * 1000;
vector<int> a[MAXN];
int mark[MAXN] = {};
void dfs(int v) {
  mark[v] = 1;
  for (auto u : a[v])
    if (!mark[u]) dfs(u);
  cout << v << ' ';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, x, y;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    a[x].push_back(y);
  }
  for (int i = 1; i <= n; i++)
    if (!mark[i]) dfs(x);
}
