#include <bits/stdc++.h>
using namespace std;
int n;
int k;
long long m;
long long f[1001][101];
long long ans;
long long ksm(long long a, long long n, long long p) {
  long long ret = 1;
  for (a %= p; n; n >>= 1) {
    if (n & 1) ret = ret * a % p;
    a = a * a % p;
  }
  return ret;
}
long long gcd(long long a, long long b) {
  long long temp;
  while (b != 0) {
    temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
int main() {
  cin >> n >> k >> m;
  for (int i = 1; i <= n; i++) {
    if (i == 1) {
      for (int t = 1; t <= 9; t++) f[i][t % k]++;
    } else {
      for (int j = 1; j < k; j++)
        for (int t = i == n ? 1 : 0; t <= 9; t++) {
          int tp = (t * ksm(10, i - 1, k) + j) % k;
          f[i][tp] = (f[i][tp] + f[i - 1][j]) % m;
        }
    }
    if (i > 1)
      for (int t = 1; t <= 9; t++)
        f[i][t * ksm(10, i - 1, m) % k] =
            (f[i][t * ksm(10, i - 1, m) % k] + 1) % m;
    if (i < n)
      ans = (ans + f[i][0] * 9 * ksm(10, n - i - 1, m)) % m;
    else
      ans = (ans + f[i][0]) % m;
  }
  cout << ans << endl;
  return 0;
}
