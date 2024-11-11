#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1000000007, n, k;
long long int PWR(long long int a, long long int b) {
  if (b == 0) return (1);
  if (b % 2 == 1) return ((a * PWR(a, b - 1)) % MOD);
  long long int x = PWR(a, b / 2);
  return ((x * x) % MOD);
}
int main() {
  scanf("%I64d %I64d", &n, &k);
  printf("%I64d", PWR(k, k - 1) * PWR(n - k, n - k) % MOD);
  return 0;
}
