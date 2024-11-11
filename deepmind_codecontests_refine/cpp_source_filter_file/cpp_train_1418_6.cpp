#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
int n, m;
int kk, x;
long long dp[11][100005][3];
long long cnt[11][100005][3], cnt2[11][100005][3];
const int mod = 1000000007;
long long m_ni;
long long quick_pow(long long x, long long y, int mod) {
  long long z = 1;
  while (y) {
    if (y) z = (z * x) % mod;
    x = (x * x) % mod;
    y = y / 2;
  }
  return z;
}
void dfs(int u, int fa) {
  int len = adj[u].size();
  cnt[0][u][0] = 1;
  for (int i = 0; i < len; i++) {
    int now = adj[u][i];
    if (now != fa) {
      dfs(now, u);
      for (int j = 0; j <= x; j++) {
        for (int k = 0; k <= j; k++) {
          cnt2[j][u][0] =
              (cnt2[j][u][0] + (cnt[j - k][u][0] * dp[k][now][0]) % mod) % mod;
          cnt2[j][u][2] =
              (cnt2[j][u][2] + (cnt[j - k][u][0] * dp[k][now][2]) % mod) % mod;
          cnt2[j][u][2] =
              (cnt2[j][u][2] + (cnt[j - k][u][2] * dp[k][now][0]) % mod) % mod;
          cnt2[j][u][2] =
              (cnt2[j][u][2] + (cnt[j - k][u][2] * dp[k][now][2]) % mod) % mod;
          cnt2[j][u][1] =
              (cnt2[j][u][1] + (cnt[j - k][u][0] * dp[k][now][1]) % mod) % mod;
          cnt2[j][u][1] =
              (cnt2[j][u][1] + (cnt[j - k][u][2] * dp[k][now][1]) % mod) % mod;
          cnt2[j][u][1] =
              (cnt2[j][u][1] + (cnt[j - k][u][1] * dp[k][now][0]) % mod) % mod;
          cnt2[j][u][1] =
              (cnt2[j][u][1] + (cnt[j - k][u][1] * dp[k][now][1]) % mod) % mod;
          cnt2[j][u][1] =
              (cnt2[j][u][1] + (cnt[j - k][u][1] * dp[k][now][2]) % mod) % mod;
        }
      }
      for (int j = 0; j <= x; j++) {
        cnt[j][u][0] = cnt2[j][u][0];
        cnt2[j][u][0] = 0;
        cnt[j][u][1] = cnt2[j][u][1];
        cnt2[j][u][1] = 0;
        cnt[j][u][2] = cnt2[j][u][2];
        cnt2[j][u][2] = 0;
      }
    }
  }
  dp[0][u][0] = (cnt[0][u][0] + cnt[0][u][2]) % mod;
  dp[0][u][0] = (dp[0][u][0] * (kk - 1)) % mod;
  dp[0][u][2] = (cnt[0][u][0] + cnt[0][u][2]) % mod;
  dp[0][u][2] = ((m - kk) * dp[0][u][2]) % mod;
  for (int i = 1; i <= x; i++) {
    long long add = (cnt[i][u][0] + cnt[i][u][2]) % mod;
    dp[i][u][0] = (add * (m - 1)) % mod;
    add = (cnt[i][u][1]) % mod;
    dp[i][u][0] = (dp[i][u][0] + add * (kk - 1)) % mod;
    dp[i][u][1] = cnt[i - 1][u][0];
    add = (cnt[i][u][0] + cnt[i][u][2]) % mod;
    dp[i][u][2] = (add * (m - kk)) % mod;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  int u, v;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  scanf("%d%d", &kk, &x);
  m_ni = quick_pow(m - 1, mod - 2, mod);
  dfs(1, -1);
  long long ans = 0;
  for (int i = 0; i <= x; i++) {
    for (int j = 0; j < 3; j++) {
      ans = (ans + dp[i][1][j]) % mod;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
