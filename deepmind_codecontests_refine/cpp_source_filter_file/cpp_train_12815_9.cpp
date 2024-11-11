#include <bits/stdc++.h>
using namespace std;
int n, fail[45];
long long f[45][45][45][2];
char s[45];
int l;
int getnxt(int p, char c) {
  if (p == l) p = fail[l];
  while (p && s[p + 1] != c) p = fail[p];
  return p + (s[p + 1] == c);
}
inline int dfs(int cnt, int cur, int ed, bool vis) {
  if (cur == l) vis = 1;
  if (cnt == n) return cur == ed && vis;
  if (f[cnt][cur][ed][vis] != -1) return f[cnt][cur][ed][vis];
  return f[cnt][cur][ed][vis] = dfs(cnt + 1, getnxt(cur, '0'), ed, vis) +
                                dfs(cnt + 1, getnxt(cur, '1'), ed, vis);
}
void getfail() {
  int j = 0;
  for (int i = 2; i <= l; i++) {
    while (j && s[i] != s[j + 1]) j = fail[j];
    if (s[i] == s[j + 1]) j++;
    fail[i] = j;
  }
}
int main() {
  memset(f, 255, sizeof(f));
  scanf("%d%s", &n, s + 1);
  long long ans = 0;
  l = strlen(s + 1);
  getfail();
  for (int i = 0; i <= l; i++) ans += dfs(0, i, i, 0);
  printf("%lld\n", ans);
  return 0;
}
