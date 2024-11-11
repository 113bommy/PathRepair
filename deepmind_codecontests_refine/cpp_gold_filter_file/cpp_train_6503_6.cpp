#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9 + 7;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int N = 100010;
const int mod = 2333333;
int U[N], V[N], n, cnt[N];
double W[N], Cn3;
vector<pair<int, int> > g[N];
int dfs(int u, int fa) {
  int tot = 0;
  for (int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i].first, id = g[u][i].second;
    if (v == fa) continue;
    int tmp = dfs(v, u);
    cnt[id] = n - tmp;
    tot += tmp;
  }
  return tot + 1;
}
double cal(int id) {
  double a = cnt[id], b = n - cnt[id];
  return 2.0 * W[id] / Cn3 * (a * (a - 1) / 2.0 * b + b * (b - 1) / 2.0 * a);
}
int main() {
  while (~scanf("%d", &n)) {
    int u, v, w;
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i <= n; ++i) g[i].clear();
    Cn3 = 1.0 * n * (n - 1) / 2.0 * (n - 2) / 3.0;
    double res = 0;
    for (int i = 1; i < n; ++i) {
      scanf("%d%d%lf", &U[i], &V[i], &W[i]);
      g[U[i]].push_back(pair<int, int>(V[i], i));
      g[V[i]].push_back(pair<int, int>(U[i], i));
    }
    int m = dfs(1, 0);
    for (int i = 1; i < n; ++i) res += cal(i);
    int q;
    scanf("%d", &q);
    while (q--) {
      int x;
      double y;
      scanf("%d%lf", &x, &y);
      res -= cal(x);
      W[x] = y;
      res += cal(x);
      printf("%.9lf\n", res);
    }
  }
}
