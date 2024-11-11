#include <bits/stdc++.h>
using namespace std;
long double log_fac[100005], ans, big = 1e99;
int n, m, k;
inline long double log_choose(int i, int j) {
  return i >= j ? log_fac[i] - log_fac[j] - log_fac[i - j] : 0;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (auto i = (1); i < m + 1; i++) log_fac[i] = log_fac[i - 1] + log(i);
  for (auto r = (0); r < n + 1; r++)
    for (auto c = (0); c < n + 1; c++) {
      int p = n * (r + c) - r * c;
      if (p > k) continue;
      ans += exp(log_choose(n, r) + log_choose(n, c) +
                 log_choose(m - p, k - p) - log_choose(m, k));
      if (ans >= big) break;
    }
  printf("%.11lf", (double)min(ans, big));
  return 0;
}
