#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0), EPS = 1e-9;
const long long INF = 1e12;
const int MX = 5 * 1e5 + 10;
int N, k, M;
int dp[22][MX];
int dep[MX];
int LCA(int u, int v) {
  if (dep[u] >= dep[v]) swap(u, v);
  int d = dep[v] - dep[u];
  for (int i = 0; i <= 20; i++)
    if (d & (1 << i)) v = dp[i][v];
  if (u == v) return u;
  for (int i = 20; i >= 0; i--) {
    if (dp[i][u] != dp[i][v]) {
      u = dp[i][u];
      v = dp[i][v];
    }
  }
  return dp[0][u];
}
void build(int node) {
  for (int j = 1; j <= 20; j++) dp[j][node] = dp[j - 1][dp[j - 1][node]];
}
int path(int u, int v) {
  int l = LCA(u, v);
  return dep[u] + dep[v] - 2 * dep[l];
}
int main() {
  memset(dp, -1, sizeof dp);
  dep[2] = dep[3] = dep[4] = 2;
  dep[1] = 1;
  dp[0][2] = dp[0][3] = dp[0][4] = 1;
  int q, first = 2, last = 3, ans = 2;
  scanf("%d", &q);
  N = 5;
  vector<int> a;
  for (int i = 0; i < q; i++) {
    int cur;
    scanf("%d", &cur);
    dp[0][N] = cur;
    dp[0][N + 1] = cur;
    dep[N] = dep[cur] + 1;
    dep[N + 1] = dep[cur] + 1;
    build(N);
    build(N + 1);
    int ans1 = path(N, first);
    int ans2 = path(N, last);
    if (ans1 > ans) {
      ans = ans1;
      last = N;
    }
    if (ans2 > ans) {
      ans = ans2;
      first = N;
    }
    a.push_back(ans);
    N += 2;
  }
  for (int i = 0; i < q; i++) cout << a[i] << "\n";
  return 0;
}
