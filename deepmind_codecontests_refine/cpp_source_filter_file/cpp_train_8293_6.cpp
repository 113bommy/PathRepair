#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1e9 + 7;
const long long Maxn = 1e6 + 10;
long long fact[Maxn + 10], in_fact[Maxn + 10];
long long qp(long long a, long long b) {
  long long sum = 1;
  while (b) {
    if (b & 1) sum = (sum * a) % Mod;
    a = (a * a) % Mod;
    b >>= 1;
  }
  return sum;
}
long long C(long long nn, long long mm) {
  return fact[nn] * in_fact[mm] % Mod * in_fact[nn - mm] % Mod;
}
int main() {
  fact[0] = in_fact[0] = 1;
  for (int i = 1; i <= Maxn; i++) {
    fact[i] = fact[i - 1] * i % Mod;
    in_fact[i] = in_fact[i - 1] * qp(i, Mod - 2) % Mod;
  }
  long long n;
  scanf("%lld", &n);
  long long temp_1 = 1, ans = (qp(3, n * n) - qp(qp(3, n) - 3, n) + Mod) % Mod;
  for (long long i = 1; i <= n; i++) {
    ans += temp_1 *
           (3 * C(n, i) % Mod * qp(qp(3, n - i) - 1, n) % Mod +
            C(n, i) * (qp(3, i) - 3) % Mod * qp(3, (n - i) * n) % Mod) %
           Mod;
    temp_1 = temp_1 * (-1);
  }
  printf("%lld", (ans % Mod + Mod) % Mod);
  return 0;
}
