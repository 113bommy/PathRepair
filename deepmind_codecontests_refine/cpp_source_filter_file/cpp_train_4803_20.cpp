#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long u[N], v[N], c[N], p[N];
vector<long long> use;
vector<long long> node[N];
long long timer = 0;
void dfs(long long u) {
  p[u] = 1;
  for (auto j : node[u]) {
    if (!p[j]) dfs(j);
  }
  timer++;
  p[u] = timer;
}
long long n, m;
bool chk(long long mid) {
  timer = 0;
  for (int i = 1; i <= n; i++) p[i] = 0, node[i].clear();
  for (int i = 1; i <= m; i++) {
    if (c[i] > mid) {
      node[u[i]].push_back(v[i]);
    }
  }
  use.clear();
  for (int i = 1; i <= n; i++) {
    if (!p[i]) dfs(i);
  }
  for (int i = 1; i <= m; i++) {
    if (p[u[i]] < p[v[i]]) {
      if (c[i] > mid) return false;
      use.push_back(i);
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  if (fopen("A.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> u[i] >> v[i] >> c[i];
  }
  long long l = 1, h = 1e9;
  while (l <= h) {
    long long mid = (l + h) >> 1;
    if (chk(mid))
      h = mid - 1;
    else
      l = mid + 1;
  }
  chk(l);
  cout << l << " " << use.size() << '\n';
  for (auto j : use) cout << j << " ";
}
