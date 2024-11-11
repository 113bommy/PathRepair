#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, fu = 0;
  char ch = getchar();
  for (; ch < 48 || ch > 57; ch = getchar()) fu |= (ch == '-');
  for (; ch > 47 && ch < 58; ch = getchar()) x = x * 10 + ch - '0';
  return fu ? -x : x;
}
namespace KMP {
char s[45];
int l, nxt[45];
void getnxt() {
  scanf("%s", s), l = strlen(s);
  for (int i = 0, j = nxt[0] = -1; i < l;)
    (j == -1 || s[i] == s[j]) ? nxt[++i] = ++j : j = nxt[j];
}
int next(int x, char ch) {
  if (x == l) x = nxt[x];
  while (x >= 0 && s[x] != ch) x = nxt[x];
  return x + 1;
}
void outnxt() {
  for (int i = 1; i <= l; i++) cout << nxt[i] << " ";
  cout << endl;
}
}  // namespace KMP
using namespace KMP;
int n;
long long f[45][45][45][2], ans;
bool vis[45][45][45][2];
long long dp(int len, int st, int ed, bool had) {
  if (vis[len][st][ed][had]) return f[len][st][ed][had];
  vis[len][st][ed][had] = 1, had |= (st == l);
  if (!len) return f[len][st][ed][had] = (had & (st == ed));
  f[len][st][ed][had] = dp(len - 1, next(st, '0'), ed, had);
  f[len][st][ed][had] += dp(len - 1, next(st, '1'), ed, had);
  return f[len][st][ed][had];
}
int main() {
  n = read(), getnxt();
  for (int i = 0; i <= l; i++) ans += dp(n, i, i, 0);
  printf("%I64d\n", ans);
  return 0;
}
