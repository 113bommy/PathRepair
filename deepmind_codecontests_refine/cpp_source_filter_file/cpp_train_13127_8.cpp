#include <bits/stdc++.h>
const int N = 1e5 + 10, M = 26;
template <typename T = int>
inline T read() {
  T x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f ? -x : x;
}
char s[N];
int a[N], pre[N][26], suf[N][26], f[N][26], g[N], dp[51];
inline int mex(int a) {
  int res = 0;
  while (a >> res & 1) ++res;
  return res;
}
inline int solve(int l, int r, int c) {
  if (l > r) return 0;
  if (dp[c] != -1) return dp[c];
  int sta = 0;
  for (int i = 0; i < 26; ++i) {
    int L = suf[l][i], R = pre[r][i];
    if (R < L) continue;
    sta |= 1 << (f[L - 1][c] ^ g[R] ^ g[L] ^ solve(R + 1, r, i));
  }
  return dp[c] = mex(sta);
}
inline int Solve(int l, int r, int c) {
  if (l > r) return 0;
  if (dp[c] != -1) return dp[c];
  int sta = 0;
  for (int i = 0; i < 26; ++i) {
    int L = suf[l][i], R = pre[r][i];
    if (R < L) continue;
    sta |= 1 << (Solve(l, L - 1, i) ^ g[R] ^ g[L] ^ f[r][i]);
  }
  return dp[c] = mex(sta);
}
int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  for (int i = 1; i <= n; ++i) a[i] = s[i] - 'a';
  for (int i = 0; i < 26; ++i) suf[n + 1][i] = n + 1;
  for (int i = 1; i <= n; ++i)
    memcpy(pre[i], pre[i - 1], sizeof(pre[i])), pre[i][a[i]] = i;
  for (int i = n; i >= 1; --i)
    memcpy(suf[i], suf[i + 1], sizeof(suf[i])), suf[i][a[i]] = i;
  for (int i = 1; i <= n; ++i) {
    memset(dp, -1, sizeof(dp)), g[i] = g[pre[i - 1][a[i]]] ^ f[i - 1][a[i]];
    for (int c = 0; c < 26; ++c) f[i][c] = solve(pre[i][c] + 1, i, c);
  }
  for (int q = read(); q; --q) {
    int l = read(), r = read();
    memset(dp, -1, sizeof(dp));
    puts(solve(l, r, 26) ? "Alice" : "Bob");
  }
  return 0;
}
