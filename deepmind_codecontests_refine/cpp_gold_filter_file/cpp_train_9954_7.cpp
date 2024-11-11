#include <bits/stdc++.h>
using namespace std;
long long n, m, a, _, q, ph, p[1234567], f[1234567], c[1234567];
int main() {
  scanf("%I64d%I64d%I64d%I64d", &n, &m, &a, &q);
  p[0] = 1, p[1] = a % q, ph = 1;
  while (p[ph] != 1) p[++ph] = p[ph - 1] * a % q;
  f[1] = 1;
  for (long long i = 2; i < ph; i++) f[i] = -(ph / i) * f[ph % i] % ph;
  _ = 1;
  c[0] = 1;
  for (long long i = 1; i < n; i++)
    _ = _ * (m - i + 1) % ph * f[i] % ph, c[i] = c[i - 1] + _, c[i] %= ph;
  for (long long i = 1; i <= n; i++)
    printf("%I64d%c", p[(c[n - i] + ph) % ph], i == n ? '\n' : ' ');
  return 0;
}
