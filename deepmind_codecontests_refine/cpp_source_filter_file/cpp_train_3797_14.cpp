#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
using namespace std;
const long long mo = 1e9 + 7;
const int INF = 0x7f7f7f7f;
template <typename _T>
void read(_T &x) {
  _T f = 1;
  x = 0;
  char s = getchar();
  while (s > '9' || s < '0') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = (x << 3) + (x << 1) + (s ^ 48);
    s = getchar();
  }
  x *= f;
}
template <typename _T>
_T Fabs(_T x) {
  return x < 0 ? -x : x;
}
char s1[55], s2[55];
char a[55], b[55], c[55];
bool f[55][55][55], g[55][55][55];
int dp[55][55], len1, len2, n;
signed main() {
  scanf("%s\n%s", s1, s2);
  read(n);
  for (int i = 1; i <= n; i++) scanf("\n%c-&gt;%c%c", &a[i], &b[i], &c[i]);
  len1 = (int)strlen(s1);
  len2 = (int)strlen(s2);
  for (int i = 0; i < len1; i++) f[i][i][s1[i] - 'a'] = 1;
  for (int i = 0; i < len2; i++) g[i][i][s2[i] - 'a'] = 1;
  for (int i = 1; i < len1; i++)
    for (int j = 1; j <= n; j++)
      for (int l = 0; l < len1; l++) {
        int r = l + i;
        for (int k = l; k < r; k++)
          if (f[l][k][b[j] - 'a'] && f[k + 1][r][c[j] - 'a'])
            f[l][r][a[j] - 'a'] = 1;
      }
  for (int i = 1; i < len2; i++)
    for (int j = 1; j <= n; j++)
      for (int l = 0; l < len2; l++) {
        int r = l + i;
        for (int k = l; k < r; k++)
          if (g[l][k][b[j] - 'a'] && g[k + 1][r][c[j] - 'a'])
            g[l][r][a[j] - 'a'] = 1;
      }
  memset(dp, 0x7f, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= len1; i++)
    for (int j = 1; j <= len2; j++) {
      for (int ii = 1; ii <= i; ii++)
        for (int jj = 1; jj <= j; jj++)
          for (int k = 0; k < 26; k++)
            if (f[ii - 1][i - 1][k] && g[jj - 1][j - 1][k]) {
              dp[i][j] = min(dp[ii - 1][jj - 1] + 1, dp[i][j]);
              break;
            }
    }
  if (dp[len1][len2] > INF - 1)
    puts("-1");
  else
    printf("%d\n", dp[len1][len2]);
  return 0;
}
