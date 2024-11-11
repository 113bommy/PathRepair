#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  int64_t n;
  cin >> n;
  vector<int64_t> L(n), R(n);
  for (int64_t i = 0; i < n; ++i) {
    cin >> L[i] >> R[i];
  }
  double E = 0;
  for (int64_t i = 1; i <= 10000; ++i) {
    double p = 0;
    for (int64_t msk = 1; msk < (1 << n); ++msk) {
      bool possible = 1;
      double prob = 1;
      int64_t cnt = 0;
      for (int64_t j = 0; j < n; ++j) {
        if ((1 << j) & msk) {
          if (L[j] > i || R[j] < i) {
            possible = 0;
            break;
          }
          prob *= (double)1 / (R[j] - L[j] + 1);
          cnt++;
        }
      }
      if (!possible) continue;
      for (int64_t w = 0; w < n; ++w) {
        if ((1 << w) & msk) continue;
        if (R[w] <= i) continue;
        double wprob = prob;
        wprob *= (double)(R[w] - max(i, L[w] - 1)) / (R[w] - L[w] + 1);
        for (int64_t j = 0; j < n; ++j) {
          if ((1 << j) & msk) continue;
          if (j == w) continue;
          if (L[j] >= i) {
            wprob = 0;
            break;
          }
          wprob *= (double)(min(R[j] + 1, i) - L[j]) / (R[j] - L[j] + 1);
        }
        p += wprob;
      }
      if (cnt >= 2) {
        double wprob = prob;
        for (int64_t j = 0; j < n; ++j) {
          if ((1 << j) & msk) continue;
          if (L[j] >= i) wprob = 0;
          wprob *= (double)(min(R[j] + 1, i) - L[j]) / (R[j] - L[j] + 1);
        }
        p += wprob;
      }
    }
    E += i * p;
  }
  printf("%.10f", E);
}
