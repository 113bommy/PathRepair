#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const long long mod = 998244353;
const long long Inf = 1e18;
vector<int> g[7][N], e;
int x[7], y[7], X[N], Y[N];
bool check(int i, int j, int k) {
  if (j == k) return 0;
  if (X[k] < min(x[i], X[j]) || X[k] > max(x[i], X[j])) return 0;
  if (Y[k] < min(y[i], Y[j]) || Y[k] > max(y[i], Y[j])) return 0;
  return 1ll * (X[k] - x[i]) * (Y[k] - Y[j]) ==
         1ll * (X[k] - X[j]) * (Y[k] - y[i]);
}
int p[7], v[7];
int k, n, t;
bool dfs(int i) {
  if (t == k) return 0;
  for (auto x : g[p[t]][i]) {
    if (!v[x]) {
      ++t;
      if (!dfs(x)) return 0;
    }
  }
  return e.push_back(i), v[i] = 1, 1;
}
int main() {
  scanf("%d%d", &k, &n);
  for (int i = (0); i < (k); ++i) scanf("%d%d", &x[i], &y[i]);
  for (int i = (0); i < (n); ++i) scanf("%d%d", &X[i], &Y[i]);
  for (int i = (0); i < (k); ++i)
    for (int j = (0); j < (n); ++j)
      for (int o = (0); o < (n); ++o) {
        if (check(i, j, o)) g[i][j].push_back(o);
        if (g[i][j].size() == k) break;
      }
  int ans = 0;
  for (int i = (0); i < (n); ++i) {
    for (int j = (0); j < (k); ++j) p[j] = j;
    do {
      t = 0;
      while (e.size()) v[e.back()] = 0, e.pop_back();
      if (dfs(i)) {
        ++ans;
        break;
      }
    } while (next_permutation(p, p + k));
  }
  cout << ans;
}
