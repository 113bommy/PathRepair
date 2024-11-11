#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int i, ns, nt, q, a, b, c, d, as[N], bs[N], at[N], bt[N], sa, sb, ta, tb, p;
char s[N], t[N];
int main() {
  scanf("%s%s%d", s + 1, t + 1, &q);
  ns = strlen(s + 1);
  nt = strlen(t + 1);
  for (i = 1; i <= ns; i++)
    if (s[i] == 'A')
      as[i] = as[i - 1] + 1, bs[i] = bs[i - 1];
    else
      as[i] = 0, bs[i] = bs[i - 1] + 1;
  for (i = 1; i <= nt; i++)
    if (t[i] == 'A')
      at[i] = at[i - 1] + 1, bt[i] = bt[i - 1];
    else
      at[i] = 0, bt[i] = bt[i - 1] + 1;
  for (i = 1; i <= q; i++) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    sa = ((as[b]) < (b - a + 1) ? (as[b]) : (b - a + 1));
    sb = bs[b] - bs[a - 1];
    ta = ((at[d]) < (d - c + 1) ? (at[d]) : (d - c + 1));
    tb = bt[d] - bt[c - 1];
    if (sb > tb)
      p = 0;
    else if (sb == tb)
      p = (sa >= ta && (sa - ta) % 3 == 0);
    else if (sb && sb < tb)
      p = (sa >= ta && (tb - sb) & 1 == 0);
    else
      p = (sa > ta && tb & 1 == 0);
    printf("%d", p);
  }
}
