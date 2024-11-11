#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 100 + 3;
char s[maxn << 1];
int n, m, len, ans, nxt[maxn << 1], f[maxn << 1][maxn][maxn][2];
void Prepare() {
  int k = 0;
  nxt[1] = 0;
  scanf("%d", &n);
  m = n << 1;
  scanf("%s", s + 1);
  len = strlen(s + 1);
  for (int i = 2; i <= len; ++i) {
    while (k && s[k + 1] != s[i]) k = nxt[k];
    if (s[k + 1] == s[i]) ++k;
    nxt[i] = k;
  }
}
void Dp() {
  int ans = 0, nxtj, *dpv;
  f[0][0][0][0] = 1;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j <= len; ++j)
      for (int k = 0; k <= n; ++k) {
        dpv = f[i][j][k];
        if (s[j + 1] == ')') {
          if (k) {
            (f[i + 1][j + 1][k - 1][(j == len - 1)] += dpv[0]) %= mod;
            (f[i + 1][j + 1][k - 1][1] += dpv[1]) %= mod;
          }
          if (k < n) {
            nxtj = j;
            while (s[nxtj + 1] != '(' && nxtj) nxtj = nxt[nxtj];
            if (s[nxtj + 1] == '(') ++nxtj;
            (f[i + 1][nxtj][k + 1][0] += dpv[0]) %= mod;
            (f[i + 1][nxtj][k + 1][1] += dpv[1]) %= mod;
          }
        }
        if (s[j + 1] == '(') {
          if (k < n) {
            (f[i + 1][j + 1][k + 1][(j == len - 1)] += dpv[0]) %= mod;
            (f[i + 1][j + 1][k + 1][1] += dpv[1]) %= mod;
          }
          if (k) {
            nxtj = j;
            while (s[nxtj + 1] != ')' && nxtj) nxtj = nxt[nxtj];
            if (s[nxtj + 1] == ')') ++nxtj;
            (f[i + 1][nxtj][k - 1][0] += dpv[0]) %= mod;
            (f[i + 1][nxtj][k - 1][1] += dpv[1]) %= mod;
          }
        }
        if (j == len) {
          if (k < n) {
            nxtj = j;
            while (s[nxtj + 1] != '(' && nxtj) nxtj = nxt[nxtj];
            if (s[nxtj + 1] == '(') ++nxtj;
            (f[i + 1][nxtj][k + 1][1] += dpv[0]) %= mod;
            (f[i + 1][nxtj][k + 1][1] += dpv[1]) %= mod;
          }
          if (k) {
            nxtj = j;
            while (s[nxtj + 1] != ')' && nxtj) nxtj = nxt[nxtj];
            if (s[nxtj + 1] == ')') ++nxtj;
            (f[i + 1][nxtj][k - 1][1] += dpv[0]) %= mod;
            (f[i + 1][nxtj][k - 1][1] += dpv[1]) %= mod;
          }
        }
      }
  for (int j = 0; j <= len; ++j) (ans += f[m][j][0][1]) %= mod;
  printf("%d\n", ans);
}
int main() {
  Prepare();
  Dp();
  return 0;
}
