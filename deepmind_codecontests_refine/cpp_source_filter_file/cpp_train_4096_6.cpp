#include <bits/stdc++.h>
using namespace std;
int n, ne, nf, ns, re, rf, rs;
double df, de, xe, xf, xs, ans = 0;
double uni(double l1, double r1, double l2, double r2) {
  return max(0.0, min(r1, r2) - max(l1, l2));
}
int main() {
  scanf("%d%d%d%d%d%d%lf%lf", &nf, &ne, &ns, &rf, &re, &rs, &df, &de);
  n = ne + nf + ns;
  xe = sqrt(re * re - 1);
  xf = sqrt(rf * rf - 1);
  xs = sqrt(rs * rs - 1);
  for (int smsk = (0); smsk < (1 << n); ++smsk)
    if (__builtin_popcount(smsk) == ns) {
      vector<double> vec;
      double res = 0;
      for (int i = (1 << n) - 1 - smsk; i; i -= i & (-i)) {
        int pos = __builtin_ctz(i) >> 1;
        double cf = df * xf * 2, ce = de * xe * 2;
        for (int j = smsk; j; j -= j & (-j)) {
          int ice = __builtin_ctz(j) >> 1;
          cf += df * uni(pos - xf, pos + xf, ice - xs, ice + xs),
              ce += de * uni(pos - xe, pos + xe, ice - xs, ice + xs);
        }
        res += cf;
        vec.push_back(cf - ce);
      }
      sort(vec.begin(), vec.end());
      for (int i = (0); i < (nf); ++i) res -= vec[i];
      ans = max(ans, res);
    }
  printf("%.10lf\n", ans);
  return 0;
}
