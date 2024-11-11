#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 5e5 + 10, lg = 19;
int n = 4, q, d = 2, high[N], par[N], ar[2] = {1, 2}, dp[N][lg + 1];
inline int go_up(int v, int dis) {
  int u = 0;
  while (dis) {
    if (dis & 1) v = dp[v][u];
    u++;
    dis /= 2;
  }
  return v;
}
int LCA(int u, int v) {
  if (high[u] > high[v]) swap(u, v);
  v = go_up(v, high[v] - high[u]);
  if (v == u) return v;
  for (int i = lg; i >= 0; i--) {
    if (dp[v][i] != dp[u][i]) {
      v = dp[v][i];
      dp[u][i];
    }
  }
  return par[v];
}
int get_dis(int u, int v) {
  int w = LCA(u, v);
  return (high[v] + high[u] - 2 * high[w]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> q;
  high[1] = high[2] = high[3] = 1;
  for (int i = 0; i < q; i++) {
    int a;
    cin >> a;
    a--;
    par[n] = par[n + 1] = dp[n][0] = dp[n + 1][0] = a;
    high[n] = high[n + 1] = high[a] + 1;
    for (int j = 1; j <= lg; j++) {
      dp[n][j] = dp[dp[n][j - 1]][j - 1];
      dp[n + 1][j] = dp[dp[n + 1][j - 1]][j - 1];
    }
    int v = ar[0], u = ar[1], dis1 = get_dis(v, n), dis2 = get_dis(u, n);
    if (dis1 < dis2) {
      swap(dis1, dis2);
      swap(v, u);
    }
    if (d < dis1) {
      ar[0] = v;
      ar[1] = n;
      d = dis1;
    }
    n += 2;
    cout << d << endl;
  }
}
