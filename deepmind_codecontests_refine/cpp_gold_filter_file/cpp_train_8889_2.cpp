#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 9;
int n, m, k;
long long Pow(long long m, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = (ans * m) % MOD;
    m = (m * m) % MOD;
    n >>= 1;
  }
  return ans;
}
long long getAns() {
  int numk = n / k;
  if (numk * (k - 1) >= m) return m;
  int restn = n - k * numk;
  int restm = m - numk * (k - 1);
  if (restm <= restn) return (numk * (k - 1) + restm) % MOD;
  int t = restm - restn;
  int num = restn + t * k;
  long long ans = (numk - t) * (k - 1) % MOD;
  numk = num / k;
  ans = (ans + num - numk * k) % MOD;
  ans = ans + 2 * (k * (Pow(2, numk) - 1)) % MOD;
  return ans % MOD;
}
int main() {
  while (scanf("%d%d%d", &n, &m, &k) != EOF) {
    printf("%lld\n", getAns());
  }
  return 0;
}
