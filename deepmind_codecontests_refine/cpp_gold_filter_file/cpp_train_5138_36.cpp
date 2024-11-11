#include <bits/stdc++.h>
using namespace std;
struct node {
  int cost, aut, ch;
} p[200005];
bool cmp(node a, node b) {
  return (a.ch < b.ch || (a.ch == b.ch && a.cost < b.cost));
}
int main() {
  int n, k;
  long long c, cc, i, j, a, x, y, m, cha = 0, nn = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%d%I64d%I64d%I64d%I64d", &k, &a, &x, &y, &m);
    for (j = 0, c = 0, cc = -9999999; j < k; ++j) {
      if (a < cc) ++c;
      if (nn <= 200000) {
        p[++nn].cost = a;
        p[nn].aut = i;
        p[nn].ch = c;
      }
      cc = a;
      a = (a * x + y) % m;
    }
    cha = max(cha, c);
  }
  printf("%I64d\n", cha);
  if (nn <= 200000) {
    sort(p + 1, p + nn + 1, cmp);
    for (i = 1; i <= nn; ++i) printf("%d %d\n", p[i].cost, p[i].aut);
  }
  return 0;
}
