#include <bits/stdc++.h>
using namespace std;
int nf, ne, ns, rf, re, rs, df, de, n;
double rrf, rre, rrs, ans, tot;
int a[25], b[25];
double c[25];
double d(double A, double B, double C, double D) {
  return max(0.0, min(B, D) - max(A, C));
}
int main() {
  scanf("%d%d%d%d%d%d%d%d", &nf, &ne, &ns, &rf, &re, &rs, &df, &de);
  n = nf + ne + ns;
  rrf = sqrt(1.0 * rf * rf - 1.0);
  rre = sqrt(1.0 * re * re - 1.0);
  rrs = sqrt(1.0 * rs * rs - 1.0);
  for (int i = 0; i < (1 << n); i++)
    if (__builtin_popcount(i) == ns) {
      int at = 0, bt = 0;
      tot = 0.0;
      for (int j = 0; j < n; j++)
        if (i & (1 << j))
          a[++at] = j / 2;
        else
          b[++bt] = j / 2;
      for (int j = 1; j <= bt; j++) {
        double dmf = 2.0 * rrf * df, dme = 2.0 * rre * de;
        for (int k = 1; k <= at; k++) {
          dmf += d(1.0 * a[k] - rrs, 1.0 * a[k] + rrs, 1.0 * b[j] - rrf,
                   1.0 * b[j] + rrf) *
                 df;
          dme += d(1.0 * a[k] - rrs, 1.0 * a[k] + rrs, 1.0 * b[j] - rre,
                   1.0 * b[j] + rre) *
                 de;
        }
        tot += dmf;
        c[j] = dme - dmf;
      }
      sort(c + 1, c + 1 + bt);
      reverse(c + 1, c + 1 + bt);
      for (int j = 1; j <= ne; j++) tot += c[j];
      ans = max(ans, tot);
    }
  printf("%.9f\n", ans);
  return 0;
}
