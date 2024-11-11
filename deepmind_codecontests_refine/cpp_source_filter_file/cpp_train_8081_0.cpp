#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -f;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
int buffer[25];
inline void write(int x) {
  if (x == 0) {
    putchar('0');
    return;
  }
  if (x < 0) putchar('-'), x = -x;
  int top = 0;
  while (x) buffer[++top] = x % 10, x /= 10;
  while (top) putchar(buffer[top] + '0'), top--;
  return;
}
int son[1000005][27];
int len[1000005], fail[1000005];
int tot, la;
char s[1000005];
int sl[1000005], dif[1000005];
int g[1000005];
int dp[1000005], pr[1000005];
inline void New(int &i) { i = ++tot; }
inline int find(int x, int i) {
  return s[i - len[x] - 1] == s[i] ? x : find(fail[x], i);
}
inline void ins(int i) {
  char c = s[i];
  int f = find(la, i);
  if (!son[f][c - 'a']) {
    int x;
    New(x);
    len[x] = len[f] + 2;
    fail[x] = son[find(fail[f], i)][c - 'a'];
    son[f][c - 'a'] = x;
    dif[x] = len[x] - len[fail[x]];
    if (dif[x] == dif[fail[x]])
      sl[x] = sl[fail[x]];
    else
      sl[x] = fail[x];
  }
  la = son[f][c - 'a'];
  return;
}
char a[1000005], b[1000005];
signed main() {
  scanf("%s%s", a + 1, b + 1);
  int n = strlen(a + 1);
  n += n;
  for (int i = 1; i <= n; i++)
    if (i % 2)
      s[i] = a[(i + 1) / 2];
    else
      s[i] = b[(i + 1) / 2];
  tot = 1, dp[0] = 0, len[0] = 0, len[1] = -1, fail[0] = 1, fail[1] = 0;
  g[0] = g[1] = n + 1, dp[n + 1] = 1e9;
  for (int i = 1; i <= n; i++) {
    ins(i), dp[i] = 1e9;
    for (int j = la; j; j = sl[j]) {
      g[j] = i - len[sl[j]] - dif[j];
      if (sl[j] == sl[fail[j]] && dp[g[fail[j]]] < dp[g[j]]) g[j] = g[fail[j]];
      if (i % 2 == 0 && dp[g[j]] + 1 < dp[i])
        dp[i] = dp[g[j]] + 1, pr[i] = g[j];
    }
    if (i % 2 == 0 && s[i] == s[i - 1] && dp[i - 2] < dp[i])
      dp[i] = dp[i - 2], pr[i] = i - 2;
  }
  if (dp[n] > 1e7) {
    puts("-1");
    return 0;
  }
  int now = n;
  write(dp[n]), putchar('\n');
  while (now) {
    int q = pr[now] + 1;
    int l = (q + 2) / 2, r = (now + 1) / 2;
    if (r - l + 1 > 2) write(l), putchar(' '), write(r), putchar('\n');
    now = pr[now];
  }
}
