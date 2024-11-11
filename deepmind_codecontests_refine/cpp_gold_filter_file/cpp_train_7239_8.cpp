#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
const int INF = 1234567890;
int n;
int L[maxn][maxn], H[maxn][maxn], A[maxn][maxn];
map<vector<int>, int> mm[maxn][maxn];
int dfs(int u, int v, vector<int> vec) {
  if (u == n - 1) {
    return 0;
  }
  int nu, nv;
  nu = u;
  nv = v + 1;
  if (nv == n) {
    nu++;
    nv = nu + 1;
  }
  if (!mm[u][v].count(vec)) {
    int ret = -INF;
    int t1 = L[u][v], t2 = H[u][v];
    for (int i = t1; i <= t2; i++) {
      if (i > vec[u]) continue;
      if (v == n - 1 && i != vec[u]) continue;
      vector<int> v2 = vec;
      v2[u] -= i;
      v2[v] += i;
      int cost = dfs(nu, nv, v2) + (i == 0 ? 0 : A[u][v] + i * i);
      ret = max(ret, cost);
    }
    mm[u][v][vec] = ret;
  }
  return mm[u][v][vec];
}
void solve() {
  for (int ans = 0; ans <= 30; ans++) {
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) mm[i][j].clear();
    }
    vector<int> vec(n, 0);
    vec[0] = ans;
    int ret = dfs(0, 1, vec);
    if (ret >= 0) {
      printf("%d %d\n", ans, ret);
      return;
    }
  }
  printf("-1 -1\n");
}
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n * (n - 1) / 2; i++) {
      int s, f, l, h, a;
      scanf("%d%d%d%d%d", &s, &f, &l, &h, &a);
      s--;
      f--;
      L[s][f] = l;
      H[s][f] = h;
      A[s][f] = a;
    }
    solve();
  }
  return 0;
}
