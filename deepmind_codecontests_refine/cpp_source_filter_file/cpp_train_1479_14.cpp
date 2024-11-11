#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f3f3f3f3fll;
int n, u, v;
long long c[3][N], dp[N][3][3];
vector<int> E[N];
int res[N];
int dfn[N], to[N], cnt;
void dfs(int u, int fa) {
  dfn[++cnt] = u;
  to[u] = cnt;
  for (int v : E[u]) {
    if (v == fa) continue;
    dfs(v, u);
  }
}
void solve() {
  long long ans = INF;
  int now, pre, las;
  bool ok = 1;
  for (int i = 1; i <= n; ++i)
    if (E[i].size() > 2) ok = 0;
  if (!ok) {
    puts("-1");
    return;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        dp[i][j][k] = INF;
      }
    }
  }
  if (n == 1) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        if (j == k) continue;
        dp[1][j][k] = c[j][1];
      }
    }
    for (int j = 0; j < 3; ++j)
      if (ans > c[j][1]) ans = c[j][1], now = j;
    printf("%I64d\n", ans);
    printf("%d\n", 1 + now);
    return;
  }
  if (n == 2) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        if (j == k) continue;
        dp[1][j][k] = c[j][1];
      }
    }
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        if (j == k) continue;
        dp[2][j][k] = min(dp[2][j][k], c[j][2] + dp[1][k][3 - j - k]);
      }
    }
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        if (j == k) continue;
        if (dp[2][j][k] < ans) {
          ans = dp[2][j][k];
          now = j;
          pre = k;
          las = 3 - now - pre;
        }
      }
    }
    printf("%I64d\n", ans);
    printf("%d %d\n", 1 + pre, 1 + now);
    return;
  }
  int rt;
  for (int i = 1; i <= n; ++i) {
    if (E[i].size() == 1) {
      rt = i;
      break;
    }
  }
  dfs(rt, -1);
  for (int j = 0; j < 3; ++j) {
    for (int k = 0; k < 3; ++k) {
      if (j == k) continue;
      dp[1][j][k] = c[j][dfn[1]];
    }
  }
  for (int j = 0; j < 3; ++j) {
    for (int k = 0; k < 3; ++k) {
      if (j == k) continue;
      dp[2][j][k] = min(dp[2][j][k], c[j][dfn[2]] + dp[1][k][3 - j - k]);
    }
  }
  for (int i = 3; i <= n; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        if (j == k) continue;
        dp[i][j][k] = min(dp[i][j][k], c[j][dfn[i]] + dp[i - 1][k][3 - j - k]);
      }
    }
  }
  for (int j = 0; j < 3; ++j) {
    for (int k = 0; k < 3; ++k) {
      if (j == k) continue;
      if (ans > dp[n][j][k]) {
        ans = dp[n][j][k];
        now = j;
        pre = k;
        las = 3 - j - k;
      }
    }
  }
  printf("%I64d\n", ans);
  int tmp;
  for (int i = n; i >= 1; --i) {
    res[dfn[i]] = now;
    tmp = now;
    now = pre;
    pre = las;
    las = tmp;
  }
  for (int i = 1; i <= n; ++i) printf("%d%c", 1 + res[i], " \n"[i == n]);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 3; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%I64d", &c[i][j]);
    }
  }
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &u, &v);
    E[u].push_back(v);
    E[v].push_back(u);
  }
  solve();
  return 0;
}
