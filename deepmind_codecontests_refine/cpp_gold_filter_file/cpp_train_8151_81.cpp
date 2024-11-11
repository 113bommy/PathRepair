#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, k, l, c, d, p, nl, np, kl = 0, cdd = 0, pnp = 0, m;
  scanf("%d%d%d%d%d%d%d%d", &n, &k, &l, &c, &d, &p, &nl, &np);
  kl = k * l / nl;
  cdd = c * d;
  pnp = p / np;
  m = min(kl, cdd);
  m = min(m, pnp);
  int ans = m / n;
  printf("%d", ans);
}
