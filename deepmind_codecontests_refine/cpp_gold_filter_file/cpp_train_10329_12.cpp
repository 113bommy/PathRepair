#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 7;
const long long INF = 1e9 + 7;
long long n, m;
long long fac[N];
int main() {
  scanf("%I64d%I64d", &n, &m);
  fac[0] = 1;
  for (long long i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % m;
  long long ans = 0;
  for (long long i = 1; i <= n; i++)
    ans = (ans + (n - i + 1) * (n - i + 1) % m * fac[i] % m * fac[n - i]) % m;
  printf("%I64d\n", ans);
  return 0;
}
