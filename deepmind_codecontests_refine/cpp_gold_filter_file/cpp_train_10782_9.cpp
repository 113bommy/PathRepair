#include <bits/stdc++.h>
using namespace std;
char st[10];
int u[300005], p[300005], a, b, c, m, lu, tu = 0, lp, tp = 0, n = 0, i;
long long s = 0;
int main() {
  scanf("%d%d%d%d", &a, &b, &c, &m);
  while (m--) {
    scanf("%d%s", &i, st);
    if (st[0] == 'U') {
      tu++;
      u[tu] = i;
    } else {
      tp++;
      p[tp] = i;
    }
  }
  if (tu) sort(u + 1, u + tu + 1);
  if (tp) sort(p + 1, p + tp + 1);
  lu = n = min(tu, a);
  for (i = 1; i <= lu; ++i) s += u[i];
  lp = min(tp, b);
  n += lp;
  for (i = 1; i <= lp; ++i) s += p[i];
  lp++;
  lu++;
  while (c && (lp <= tp || lu <= tu)) {
    c--;
    n++;
    if (lp > tp) {
      s += u[lu];
      lu++;
    } else if (lu > tu) {
      s += p[lp];
      lp++;
    } else {
      if (p[lp] < u[lu]) {
        s += p[lp];
        lp++;
      } else {
        s += u[lu];
        lu++;
      }
    }
  }
  printf("%d %I64d\n", n, s);
  return 0;
}
