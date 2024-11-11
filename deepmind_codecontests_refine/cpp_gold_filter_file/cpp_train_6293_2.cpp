#include <bits/stdc++.h>
using namespace std;
namespace RA {
int r(int p) { return 1ll * rand() * rand() % p; }
int r(int L, int R) { return r(R - L + 1) + L; }
}  // namespace RA
const int M = 1e5 + 5;
long double fac[M], ans;
long double binom(int n, int m) { return fac[n] - fac[m] - fac[n - m]; }
int main() {
  int n, n2, m, k;
  scanf("%d%d%d", &n, &m, &k);
  n2 = n * n;
  fac[0] = log(1);
  for (int i = (1); i <= (m); ++i) fac[i] = fac[i - 1] + log(i);
  for (int i = (0); i <= (n); ++i)
    for (int j = (0); j <= (n); ++j) {
      int s = (n - i) * (n - j);
      if (k + s - n2 >= 0)
        ans += exp(binom(n, i) + binom(n, j) + fac[k] - fac[k - n2 + s] +
                   fac[m - n2 + s] - fac[m]);
    }
  printf("%.15lf", (double)min(ans, (long double)1e99));
  return 0;
}
