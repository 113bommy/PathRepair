#include <bits/stdc++.h>
using namespace std;
vector<int> tr[100001];
int dp[100001][10][3], k, x, n, m, tmp[10][3], md = 1e9 + 7;
inline void ad(int &x, int y) {
  if ((x += y) >= md) x -= md;
}
void go(int v = 1, int p = 0) {
  dp[v][0][0] = k - 1;
  dp[v][1][1] = 1;
  dp[v][0][2] = m - k;
  int(*z)[3] = dp[v];
  for (int i = 0; i < (int)tr[v].size(); ++i) {
    int u = tr[v][i];
    if (u == p) continue;
    go(u, v);
    for (int i = 0; i < (int)10; ++i)
      for (int j = 0; j < (int)3; ++j) tmp[i][j] = z[i][j], z[i][j] = 0;
    for (int szv = 0; szv < (int)x + 1; ++szv)
      for (int szu = 0; szu < (int)x - szv + 1; ++szu) {
        int nsz = szv + szu;
        ad(z[nsz][0],
           tmp[szv][0] *
               ((long long)dp[u][szu][0] + dp[u][szu][1] + dp[u][szu][2]) % md);
        ad(z[nsz][1], tmp[szv][1] * (long long)dp[u][szu][0] % md);
        ad(z[nsz][2],
           tmp[szv][2] * (long long)(dp[u][szu][0] + dp[u][szu][2]) % md);
      }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < (int)n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    tr[a].push_back(b);
    tr[b].push_back(a);
  }
  scanf("%d%d", &k, &x);
  go();
  int an = 0;
  for (int i = 0; i < (int)x + 1; ++i)
    for (int j = 0; j < (int)3; ++j) ad(an, dp[1][i][j]);
  printf("%d\n", an);
}
