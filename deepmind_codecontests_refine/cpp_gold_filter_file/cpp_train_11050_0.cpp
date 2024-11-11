#include <bits/stdc++.h>
using namespace std;
int pr[2010];
bool st[2][2010];
void kmp(char *w, char *p, int s) {
  int q, i, k, m;
  m = strlen(p);
  pr[0] = -1;
  k = -1;
  for (i = 1; i < m; i++) {
    while (k > -1 && p[k + 1] != p[i]) k = pr[k];
    if (p[k + 1] == p[i]) k++;
    pr[i] = k;
  }
  q = 0;
  k = -1;
  for (i = 0; w[i]; i++) {
    while (k > -1 && p[k + 1] != w[i]) k = pr[k];
    if (p[k + 1] == w[i]) k++;
    if (k == (m - 1)) {
      if (!s)
        st[s][i - k] = 1;
      else
        st[s][i] = 1;
      q++;
      k = pr[k];
    }
  }
}
char s[2010], b[2010], e[2010];
int dp[2010][2010];
int main() {
  int i, j, k, lb, le;
  scanf("%s %s %s", s, b, e);
  lb = strlen(b);
  le = strlen(e);
  kmp(s, b, 0);
  kmp(s, e, 1);
  int r = 0, l = strlen(s);
  int m = max(lb, le);
  for (i = l - 1; i >= 0; i--) {
    dp[i][l] = 0;
    dp[l][i] = 0;
    for (j = i + 1; j < l; j++) {
      if (s[i] == s[j])
        dp[i][j] = dp[j][i] = dp[i + 1][j + 1] + 1;
      else
        dp[i][j] = dp[j][i] = 0;
    }
  }
  for (i = 0; i < l; i++)
    if (st[0][i]) {
      k = m - 1;
      for (j = 0; j < i; j++)
        if (st[0][j]) k = max(k, dp[i][j]);
      for (j = i + k; j < l; j++)
        if (st[1][j]) r++;
    }
  cout << r << '\n';
  return 0;
}
