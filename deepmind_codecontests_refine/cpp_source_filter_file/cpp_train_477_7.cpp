#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1.1e5;
int N;
int sum[MAXN];
int par[MAXN][20];
int depth[MAXN];
int lca(int a, int b) {
  if (depth[a] < depth[b]) swap(a, b);
  int d = depth[a] - depth[b];
  for (int i = 0; (1 << i) <= d; i++) {
    if (d & (1 << i)) {
      a = par[a][i];
    }
  }
  assert(depth[a] == depth[b]);
  if (a == b) return a;
  int i = 0;
  while (par[a][i]) i++;
  while (i) {
    i--;
    if (par[a][i] != par[b][i]) {
      a = par[a][i];
      b = par[b][i];
    }
  }
  assert(a != b);
  assert(par[a][0] == par[b][0]);
  return par[a][0];
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> N;
  for (int i = 1; i <= N; i++) {
    int p, x;
    cin >> p >> x;
    if (p > 0) {
      depth[i] = depth[p] + 1;
      sum[i] = sum[p] + x;
      par[i][0] = p;
    } else {
      depth[i] = 0;
      sum[i] = 0;
      par[i][0] = 0;
    }
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 0; par[i][j]; j++) {
      par[i][j + 1] = par[par[i][j]][j];
    }
  }
  int Q;
  cin >> Q;
  while (Q--) {
    int t, u, v;
    cin >> t >> u >> v;
    int w = lca(u, v);
    if (w == 0 || u == v) {
      cout << "NO" << '\n';
      continue;
    }
    if (t == 1) {
      cout << ((w == u && sum[w] == sum[u]) ? "YES" : "NO") << '\n';
    } else {
      cout << ((w != v && sum[w] == sum[u] &&
                sum[v] == sum[w] + depth[v] - depth[w])
                   ? "YES"
                   : "NO")
           << '\n';
    }
  }
  return 0;
}
