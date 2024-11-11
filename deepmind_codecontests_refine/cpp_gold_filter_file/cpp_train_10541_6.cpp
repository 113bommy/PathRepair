#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
int f[maxn][maxn];
int dp[maxn][maxn];
int g[maxn][maxn];
char s[maxn], ss[maxn], ans[5 * maxn];
int K, n, l;
void init() {
  int i, j, k;
  l = strlen(s);
  for (i = 0; i < l; i++) ss[i + 1] = s[i];
  memset(f, 0, sizeof(f));
  for (k = 2; k <= l; k++) {
    for (i = 1; i + k - 1 <= l; i++) {
      j = i + k - 1;
      if (ss[i] != ss[j])
        f[i][j] = f[i + 1][j - 1] + 1;
      else
        f[i][j] = f[i + 1][j - 1];
    }
  }
}
void change(int i, int j) {
  while (i < j) {
    if (ss[i] != ss[j]) ss[i] = ss[j];
    i++;
    j--;
  }
}
void print(int st, int ed, int k) {
  if (st == 1) {
    for (int i = st; i <= ed; i++) ans[++n] = ss[i];
    ans[++n] = '+';
    return;
  } else {
    print(g[st - 1][k - 1] + 1, st - 1, k - 1);
    for (int i = st; i <= ed; i++) ans[++n] = ss[i];
    if (ed != l) ans[++n] = '+';
  }
}
void DP() {
  int i, j, k;
  memset(dp, 0x7f, sizeof(dp));
  memset(g, 0, sizeof(g));
  for (i = 1; i <= l; i++) {
    dp[i][1] = f[1][i];
    g[i][1] = 0;
  }
  for (k = 2; k <= K; k++) {
    for (i = k; i <= l; i++) {
      for (j = k - 1; j <= i - 1; j++) {
        if (dp[i][k] > dp[j][k - 1] + f[j + 1][i]) {
          dp[i][k] = dp[j][k - 1] + f[j + 1][i];
          g[i][k] = j;
        }
      }
    }
  }
  int out = 1 << 30;
  int xgb;
  for (i = 1; i <= K; i++) {
    if (dp[l][i] < out) {
      out = dp[l][i];
      xgb = i;
    }
  }
  int tmp = xgb;
  cout << out << endl;
  int p = g[l][xgb];
  if (p == 0) {
    change(1, l);
    for (i = 1; i <= l; i++) cout << ss[i];
    cout << endl;
    return;
  }
  int ed = l;
  while (1) {
    change(p + 1, ed);
    if (p == 0) break;
    xgb--;
    ed = p;
    p = g[p][xgb];
  }
  n = 0;
  print(g[l][tmp] + 1, l, tmp);
  for (i = 1; i <= n; i++) cout << ans[i];
  cout << endl;
}
int main() {
  while (scanf("%s", s) != EOF) {
    scanf("%d", &K);
    init();
    DP();
  }
  return 0;
}
