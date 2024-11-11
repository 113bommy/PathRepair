#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
double p[maxn], g[maxn];
int n, m, i, j, s[maxn];
long long sp[maxn], lp[maxn], st[maxn], lt[maxn], pr[maxn], f[maxn],
    b = 1000000;
bool cmp(int x, int y) {
  return (lt[x] + lt[y]) * b * (b - pr[y]) + lt[x] * (b - pr[x]) * pr[y] <
         (lt[x] + lt[y]) * b * (b - pr[x]) + lt[y] * pr[x] * (b - pr[y]);
}
void upd(int t, long long x, double y) {
  if (f[t] < x)
    f[t] = x, g[t] = y;
  else if (f[t] == x && g[t] > y)
    g[t] = y;
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%I64d %I64d %I64d %I64d %lf", sp + i, lp + i, st + i, lt + i, p + i);
    pr[i] = p[i] * b + 0.5;
    s[i] = i;
  }
  sort(s + 1, s + n + 1, cmp);
  for (i = 1; i <= n; i++) {
    for (j = m; j >= 0; j--) {
      if (j + st[s[i]] <= m)
        upd(j + st[s[i]], f[j] + sp[s[i]] * b, g[j] + st[s[i]]);
      if (j + st[s[i]] + lt[s[i]] <= m)
        upd(j + st[s[i]] + lt[s[i]],
            f[j] + sp[s[i]] * b + lp[s[i]] * (b - pr[s[i]]),
            st[s[i]] + p[s[i]] * g[j] + (1. - p[s[i]]) * (lt[s[i]] + j));
    }
  }
  for (i = 0; i < m; i++) upd(m, f[i], g[i]);
  printf("%.10f %.10f\n", (double)f[m] / b, g[m]);
  return 0;
}
