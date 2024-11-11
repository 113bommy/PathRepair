#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
const int p = 1e9 + 7;
int l, t, num, lst, a[N], len[N], fail[N], dif[N], g[N], f[N], ans[N],
    tr[N][28];
char s[N];
inline int get_fail(int x, int y) {
  while (a[x] ^ a[x - len[y] - 1]) y = fail[y];
  return y;
}
inline int inc(int x, int y) {
  x += y;
  return x < p ? x : x - p;
}
int main() {
  scanf("%s", s + 1), l = strlen(s + 1);
  if (l & 1) {
    putchar(48);
    return 0;
  }
  t = l >> 1, len[1] = a[0] = -1, fail[0] = ans[0] = num = 1;
  for (register int i = 1; i <= t; ++i) a[(i << 1) - 1] = s[i] - 97;
  for (register int i = l; i > t; --i) a[(l - i + 1) << 1] = s[i] - 97;
  for (register int i = 1; i <= l; ++i) {
    int u = a[i], v = get_fail(i, lst);
    if (!tr[v][u]) {
      fail[++num] = tr[get_fail(i, fail[v])][u],
      len[tr[v][u] = num] = len[v] + 2, dif[num] = len[num] - len[fail[num]];
      if (dif[num] == dif[fail[num]])
        g[num] = g[fail[num]];
      else
        g[num] = fail[num];
    }
    for (register int j = lst = tr[v][u]; j; j = g[j]) {
      f[j] = ans[i - len[g[j]] - dif[j]];
      if (g[j] ^ fail[j]) f[j] = inc(f[j], f[fail[j]]);
      if (!(i & 1)) ans[i] = inc(ans[i], f[j]);
    }
  }
  printf("%d", ans[l]);
  return 0;
}
