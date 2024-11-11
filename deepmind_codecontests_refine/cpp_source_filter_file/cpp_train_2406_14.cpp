#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
const int mod = 998244353;
int nxt[N], ext[N];
void getnxt(char *s, int m) {
  memset(nxt, 0, sizeof(nxt));
  nxt[0] = m;
  for (int i = 0; i < m - 1 && s[i] == s[i + 1]; i++) nxt[1] = i + 1;
  int l = 1;
  for (int i = 2; i < m; i++) {
    int r = l + nxt[l] - 1, j = i + nxt[i - l] - 1;
    if (j >= r) {
      j = max(0, r - i + 1);
      while (i + j < m && s[i + j] == s[j]) j++;
      nxt[i] = j;
      l = i;
    } else
      nxt[i] = nxt[i - l];
  }
}
void getext(char *s, int n, char *t, int m) {
  memset(ext, 0, sizeof(ext));
  getnxt(t, m);
  for (int i = 0; i < min(n, m) && s[i] == t[i]; i++) ext[0] = i + 1;
  int l = 0;
  for (int i = 1; i < n; i++) {
    int r = l + ext[l] - 1, j = i + nxt[i - l] - 1;
    if (j >= r) {
      j = max(0, r - i + 1);
      while (i + j < n && j < m && s[i + j] == t[j]) j++;
      ext[i] = j;
      l = i;
    } else
      ext[i] = nxt[i - l];
  }
}
int n, nl, nr;
char a[N], l[N], r[N];
int dp[N];
int extl[N], extr[N];
int main() {
  scanf("%s", a), n = strlen(a);
  scanf("%s", l), nl = strlen(l);
  scanf("%s", r), nr = strlen(r);
  getext(a, n, l, nl);
  for (int i = 0; i < n; i++) extl[i] = ext[i];
  getext(a, n, r, nr);
  for (int i = 0; i < n; i++) extr[i] = ext[i];
  dp[0] = 1, dp[1] = mod - 1;
  for (int i = 0; i <= n; i++) {
    if (i > 0) dp[i] = (dp[i] + dp[i - 1]) % mod;
    if (a[i] == '0') {
      if (nl == 1 && l[0] == '0') {
        dp[i + 1] = (dp[i + 1] + dp[i]) % mod;
        dp[i + 2] = (dp[i + 1] - dp[i] + mod) % mod;
      }
      continue;
    }
    int lb = i + nl, rb = i + nr;
    if (lb <= n && extl[i] < nl && a[i + extl[i]] < l[extl[i]]) lb++;
    if (rb <= n && extr[i] < nr && a[i + extr[i]] > r[extr[i]]) rb--;
    if (lb <= n) dp[lb] = (dp[lb] + dp[i]) % mod;
    if (rb + 1 <= n) dp[rb + 1] = (dp[rb + 1] - dp[i] + mod) % mod;
  }
  printf("%d\n", dp[n]);
  return 0;
}
