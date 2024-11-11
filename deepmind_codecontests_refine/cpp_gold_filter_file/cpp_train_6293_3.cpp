#include <bits/stdc++.h>
const int N = 1e5 + 5;
int n, m, k;
long double s[N], Ans;
inline long double C(int n, int m) { return s[n] - s[m] - s[n - m]; }
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i < N; ++i) s[i] = s[i - 1] + std::log(i);
  for (int i = 0, c; i <= n; ++i)
    for (int j = 0; j <= n; ++j)
      if ((c = (i + j) * n - i * j) <= k)
        Ans = std::min(
            Ans + std::exp(C(n, i) + C(n, j) + C(m - c, k - c) - C(m, k)),
            (long double)1e99);
  return printf("%.10f\n", (double)Ans), 0;
}
