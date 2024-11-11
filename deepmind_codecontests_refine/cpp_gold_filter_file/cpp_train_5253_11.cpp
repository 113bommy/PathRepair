#include <bits/stdc++.h>
using namespace std;
char s[4000010];
long long n, ans;
int nxt[4000010][5], tot = 1, len;
struct matrix {
  long long a[5][5];
  matrix() { memset(a, 127, sizeof(a)); }
  long long* operator[](int x) { return a[x]; }
  long long get() {
    long long t = 1ll << 60;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++) t = min(t, a[i][j]);
    return t;
  }
} f[64], tmp;
matrix operator+(matrix x, matrix y) {
  matrix z;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 4; k++) z[i][j] = min(z[i][j], x[i][k] + y[k][j]);
  return z;
}
void add(int k, int p, int l) {
  if (l > 20 || p >= len) return;
  if (!nxt[k][s[p] - 'A']) nxt[k][s[p] - 'A'] = ++tot;
  add(nxt[k][s[p] - 'A'], p + 1, l + 1);
}
void dfs(int k, int p, int l) {
  for (int i = 0; i < 4; i++)
    if (!nxt[k][i])
      f[0][p][i] = min(f[0][p][i], (long long)l);
    else
      dfs(nxt[k][i], p, l + 1);
}
int main() {
  scanf("%I64d%s", &n, s);
  len = strlen(s);
  for (int i = 0; i < len; i++) add(1, i, 1);
  for (int i = 0; i < 4; i++) dfs(nxt[1][i], i, 1);
  for (int i = 1; i <= 60; i++) f[i] = f[i - 1] + f[i - 1];
  memset(tmp.a, 0, sizeof(tmp.a));
  for (int i = 60; i + 1; i--) {
    matrix z = f[i] + tmp;
    if (z.get() < n) ans += 1ll << i, tmp = z;
  }
  printf("%I64d", ans + 1);
}
