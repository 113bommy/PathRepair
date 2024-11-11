#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
const int N = 88;
int dp[N][N][2][N], adj[N][N];
int rec(int l, int r, int which, int rem) {
  if (!rem) return 0;
  int &ret = dp[l][r][which][rem], nd;
  if (~ret) return ret;
  ret = 1000000007;
  if (which)
    nd = r + 1;
  else
    nd = l - 1;
  for (int i = l; i <= r; i++)
    if (adj[nd][i] < 1000000007) {
      umin(ret, rec(l, i - 1, 1, rem - 1) + adj[nd][i]);
      umin(ret, rec(i + 1, r, 0, rem - 1) + adj[nd][i]);
    }
  return ret;
}
int main() {
  memset(dp, -1, sizeof dp);
  int n, k, m;
  scanf("%d%d%d", &n, &k, &m);
  if (k == 1) {
    puts("0");
    return 0;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) adj[i][j] = 1000000007;
  while (m--) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    umin(adj[u][v], c);
  }
  int ans = 1000000007;
  for (int i = 1; i <= n; i++) {
    umin(ans, rec(1, i - 1, 1, k - 1));
    umin(ans, rec(i + 1, n, 0, k - 1));
  }
  if (ans >= 1000000007) ans = -1;
  printf("%d\n", ans);
  return 0;
}
