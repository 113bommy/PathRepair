#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
char s[maxn], ss[maxn];
int n;
long long f[maxn], ans[maxn];
int len[maxn], fail[maxn], ch[maxn][26], last = 1, tot = 1, fa[maxn], cha[maxn];
int getfail(int x, int i) {
  while (i - len[x] - 1 < 0 || s[i - len[x] - 1] != s[i]) x = fail[x];
  return x;
}
int main() {
  scanf("%s", ss + 1);
  n = strlen(ss + 1);
  for (int i = 1; i <= n; i += 2) s[i] = ss[(i + 1) >> 1];
  reverse(ss + 1, ss + n + 1);
  for (int i = 2; i <= n; i += 2) s[i] = ss[(i + 1) >> 1];
  if (n & 1) {
    printf("0\n");
    return 0;
  }
  len[1] = -1;
  fail[0] = fail[1] = 1;
  ans[0] = 1;
  fa[0] = 1;
  for (int i = 1; i <= n; i++) {
    int cur = last;
    cur = getfail(cur, i);
    if (!ch[cur][s[i] - 'a']) {
      fail[++tot] = ch[getfail(fail[cur], i)][s[i] - 'a'];
      len[tot] = len[cur] + 2;
      ch[cur][s[i] - 'a'] = tot;
      cha[tot] = len[tot] - len[fail[tot]];
      fa[tot] = (cha[tot] == cha[fail[tot]]) ? fa[fail[tot]] : fail[tot];
    }
    last = ch[cur][s[i] - 'a'];
    for (int j = last; j; j = fa[j]) {
      f[j] = ans[i - len[fa[j]] - cha[j]];
      if (fa[j] != fail[j]) f[j] = (f[j] + f[fail[j]]) % mod;
      if (i % 2 == 0) ans[i] = (ans[i] + f[j]) % mod;
    }
  }
  printf("%lld", ans[n]);
  return 0;
}
