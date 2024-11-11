#include <bits/stdc++.h>
using namespace std;
int n, m, k;
long double fac[100005], ans;
inline long double C(int n, int m) { return fac[n] - fac[m] - fac[n - m]; }
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 2; i <= m; i++) fac[i] = fac[i - 1] + log(i);
  for (int r = 0; r <= n; r++)
    for (int c = 0, x; c <= n; c++)
      if ((x = (r + c) * n - r * c) <= k)
        ans += exp(C(n, r) + C(n, c) + C(m - x, k - x) - C(m, k));
  if (ans < 1e99)
    printf("%.10f\n", (double)ans);
  else
    puts("1e99");
}
