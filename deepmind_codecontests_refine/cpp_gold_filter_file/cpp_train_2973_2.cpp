#include <bits/stdc++.h>
using ll = long long;
const ll INF = 1LL << 62;
const int maxn = 5001;
ll x[maxn];
ll a[maxn];
ll b[maxn];
ll c[maxn];
ll d[maxn];
int main() {
  int n;
  int s;
  int e;
  int index;
  bool now;
  bool last;
  ll val;
  ll curr;
  ll res;
  ll dp[2][maxn][2][2];
  std::ios::sync_with_stdio(false);
  std::cin >> n >> s >> e;
  --s;
  --e;
  for (index = 0; index < n; ++index) {
    std::cin >> x[index];
  }
  for (index = 0; index < n; ++index) {
    std::cin >> a[index];
  }
  for (index = 0; index < n; ++index) {
    std::cin >> b[index];
  }
  for (index = 0; index < n; ++index) {
    std::cin >> c[index];
  }
  for (index = 0; index < n; ++index) {
    std::cin >> d[index];
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j <= n; ++j) {
      dp[i][j][0][0] = dp[i][j][0][1] = INF;
      dp[i][j][1][0] = dp[i][j][1][1] = INF;
    }
  }
  dp[1][0][0][0] = 0;
  res = INF;
  for (int i = 0; i < n; ++i) {
    now = i & 1;
    last = !now;
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k < 2; ++k) {
        for (int l = 0; l < 2; ++l) {
          dp[now][j][k][l] = INF;
        }
      }
    }
    for (int j = 0; j < n + 1; ++j) {
      for (int k = 0; k < 2; ++k) {
        for (int l = 0; l < 2; ++l) {
          if (dp[last][j][k][l] != INF) {
            val = dp[last][j][k][l];
            if ((i != s) and (i != e)) {
              {
                curr = x[i] + x[i] + c[i] + a[i];
                if (j + k + l > 1) {
                  dp[now][j - 1][k][l] =
                      std::min(curr + val, dp[now][j - 1][k][l]);
                }
                if ((i == n - 1) and (not j) and (k) and (l)) {
                  res = std::min(res, curr + val);
                }
              }
              {
                curr = a[i] + d[i];
                if ((j) or (k)) {
                  dp[now][j][k][l] = std::min(dp[now][j][k][l], curr + val);
                }
              }
              {
                curr = b[i] + c[i];
                if ((j) or (l)) {
                  dp[now][j][k][l] = std::min(dp[now][j][k][l], curr + val);
                }
              }
              {
                curr = b[i] + d[i] - x[i] - x[i];
                dp[now][j + 1][k][l] =
                    std::min(dp[now][j + 1][k][l], curr + val);
              }
            } else if ((i == s) and (not k)) {
              {
                curr = x[i] + c[i];
                if (j) {
                  dp[now][j - 1][1][l] =
                      std::min(dp[now][j - 1][1][l], curr + val);
                }
                if ((i == n - 1) and (not j) and (l)) {
                  res = std::min(res, curr + val);
                }
              }
              {
                curr = -x[i] + d[i];
                dp[now][j][1][l] = std::min(dp[now][j][1][l], curr + val);
              }
            } else if ((i == e) and (not l)) {
              {
                curr = x[i] + a[i];
                if (j) {
                  dp[now][j - 1][k][1] =
                      std::min(dp[now][j - 1][k][1], curr + val);
                }
                if ((i == n - 1) and (k) and (not j)) {
                  res = std::min(res, curr + val);
                }
              }
              {
                curr = -x[i] + b[i];
                dp[now][j][k][1] = std::min(dp[now][j][k][1], curr + val);
              }
            }
          }
        }
      }
    }
  }
  std::cout << res;
  return 0;
}
