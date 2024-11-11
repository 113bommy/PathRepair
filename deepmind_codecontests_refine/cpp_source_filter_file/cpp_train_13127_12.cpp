#include <bits/stdc++.h>
using namespace std;
const int maxn = 100500;
int n, m, l, r, pre[maxn][30], suc[maxn][30], f[maxn][30], a[maxn], g[maxn],
    sg[30];
char s[maxn];
int calc(int l, int r, int c, int op) {
  if (l > r) return 0;
  if (~sg[c]) return sg[c];
  int now = 0;
  for (int j = 0; j <= 25; j++) {
    int le = suc[l][j], ri = pre[r][j];
    if (ri >= l)
      now |=
          1 << (g[ri] ^ g[le] ^ (!op ? f[le - 1][c] : calc(l, le - 1, j, op)) ^
                (!op ? calc(ri + 1, r, c, op) : f[r][j]));
  }
  return sg[c] = __builtin_ctz(~now);
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) a[i] = s[i] - 'a';
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 25; j++) {
      if (j == a[i])
        pre[i][j] = i;
      else
        pre[i][j] = pre[i - 1][j];
    }
  }
  for (int i = 0; i <= 25; i++) suc[n + 1][i] = n + 1;
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j <= 25; j++) {
      if (j == a[i])
        suc[i][j] = i;
      else
        suc[i][j] = suc[i + 1][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    g[i] = f[i - 1][a[i]] ^ g[pre[i - 1][a[i]]];
    memset(sg, -1, sizeof(sg));
    for (int j = 0; j <= 25; j++) f[i][j] = calc(pre[i][j] + 1, i, j, 0);
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    memset(sg, -1, sizeof(sg));
    if (calc(l, r, 26, 1))
      puts("Alice");
    else
      puts("Bob");
  }
  return 0;
}
