#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
int fa[N], n, m, K, a[N], val[N], d[N], q[N];
vector<int> g[N], vec[N], V;
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void gofail() {
  cout << -1 << '\n';
  exit(0);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> K;
  for (int i = 1; i <= n; ++i) cin >> a[i], val[i] = a[i];
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    d[y]++;
  }
  int t = 0, w = 0;
  for (int i = 1; i <= n; ++i)
    if (!d[i]) {
      if (!val[i]) val[i] = K;
      q[++w] = i;
    }
  for (; t < w;) {
    int x = q[++t];
    for (int i : g[x]) {
      if (a[i] >= val[x] || val[x] == 1) gofail();
      if (!val[i] || val[i] >= val[x]) val[i] = val[x] - 1;
      if (!--d[i]) q[++w] = i;
    }
  }
  if (w != n) gofail();
  for (int i = 1; i <= n; ++i) vec[val[i]].push_back(i);
  for (int i = 1; i <= K; ++i) {
    V.clear();
    fa[i] = i;
    for (int j : vec[i]) {
      if (a[j]) {
        V.push_back(j);
        continue;
      }
      int mx = 0;
      for (int k : g[j]) mx = max(mx, val[k]);
      mx = find(mx + 1);
      if (mx < i)
        val[j] = mx, vec[mx].push_back(j), fa[mx] = mx + 1;
      else
        V.push_back(j);
    }
    swap(vec[i], V);
    fa[i] = i + !vec[i].empty();
  }
  for (int i = 1; i <= K; ++i)
    if (vec[i].empty()) gofail();
  for (int i = 1; i <= n; ++i) cout << val[i] << " \n"[i == n];
  return 0;
}
