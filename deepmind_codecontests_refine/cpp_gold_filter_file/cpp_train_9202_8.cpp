#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005, M = ((int)1e9) + 7;
int n, emp[maxn], cx, cy, dp[maxn][8];
char g[4][maxn];
vector<int> st[8];
inline int add(long long a, long long b) { return (a + b) % M; }
inline int sub(long long a, long long b) { return (a - b + M) % M; }
void dfs(int p, int s1, int s2) {
  if (p >= 3) {
    if (p == 3) {
      st[s1].push_back(s2 ^ 7);
    }
    return;
  }
  dfs(p + 1, s1 << 1, s2 << 1);
  dfs(p + 1, s1 << 1 | 1, s2 << 1 | 1);
  dfs(p + 2, s1 << 2 | 3, s2 << 2);
}
int dp1() {
  memset(dp, 0, sizeof(dp));
  dp[0][7] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < 8; ++j) {
      if ((j & emp[i]) != j) continue;
      for (int k = 0; k < (int)(st[j]).size(); ++k)
        dp[i][j | (emp[i] ^ 7)] =
            add(dp[i][j | (emp[i] ^ 7)], dp[i - 1][st[j][k]]);
    }
  return dp[n][7];
}
int dp2() {
  memset(dp, 0, sizeof(dp));
  dp[0][7] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < 8; ++j) {
      if ((j & emp[i]) != j) continue;
      if (i + 1 == cx || i - 2 == cx) {
        for (int k = 0; k < (int)(st[j]).size(); ++k)
          if ((st[j][k] >> cy) & 1) {
            dp[i][j | (emp[i] ^ 7)] =
                add(dp[i][j | (emp[i] ^ 7)], dp[i - 1][st[j][k]]);
          }
      } else if (i == cx) {
        for (int k = 0; k < (int)(st[j]).size(); ++k) {
          int pres = st[j][k];
          bool f1 = cy == 0 && (j & (1 << 1)) && (j & (1 << 2)) &&
                    (pres & (1 << 1)) && (pres & (1 << 2));
          bool f2 = cy == 2 && (j & (1 << 0)) && (j & (1 << 1)) &&
                    (pres & (1 << 0)) && (pres & (1 << 1));
          if (!f1 && !f2) {
            dp[i][j | (emp[i] ^ 7)] =
                add(dp[i][j | (emp[i] ^ 7)], dp[i - 1][st[j][k]]);
          }
        }
      } else
        for (int k = 0; k < (int)(st[j]).size(); ++k)
          dp[i][j | (emp[i] ^ 7)] =
              add(dp[i][j | (emp[i] ^ 7)], dp[i - 1][st[j][k]]);
    }
  return dp[n][7];
}
int main(int argc, char const *argv[]) {
  scanf("%d", &n);
  for (int i = 0; i < 3; ++i) scanf("%s", g[i]);
  for (int j = 0; j < n; ++j)
    for (int i = 0; i < 3; ++i) {
      if (g[i][j] == '.') emp[j + 1] |= 1 << (2 - i);
      if (g[i][j] == 'O') cx = j + 1, cy = 2 - i;
    }
  dfs(0, 0, 0);
  int all = dp1();
  int neg = dp2();
  printf("%d\n", sub(all, neg));
  return 0;
}
