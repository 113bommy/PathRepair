#include <bits/stdc++.h>
using namespace std;
long long modulo(long long a, long long b, long long n = 1000000007) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) x = (x * y) % n;
    y = (y * y) % n;
    b /= 2;
  }
  return (x % n);
}
long long fact[1000020] = {0};
long long inv[1000020] = {0};
long long C(long long n, long long r) {
  if (r < 0 || r > n || n <= 0)
    return 0;
  else {
    long long ans = (inv[r] * inv[n - r]) % 1000000007;
    ans = (ans * fact[n]) % 1000000007;
    return ans;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, a, b;
  cin >> n >> m >> a >> b;
  fact[0] = 1, inv[0] = 1;
  long long n1 = max(n, m);
  for (int i = 1; i < n1 + 1; i++)
    fact[i] = ((long long)i * fact[i - 1]) % 1000000007;
  for (int i = 1; i < n1 + 1; i++)
    inv[i] = (inv[i - 1] * modulo((long long)i, 1000000007 - 2, 1000000007)) %
             1000000007;
  long long temp = 0;
  for (int i = 2; i < n + 1; i++) {
    long long ans = 1;
    if (i == n) {
      ans = ((((C(n - 2, i - 2) * fact[i - 2]) % 1000000007) *
              ((modulo(m, n - i) * (C(m - 1, i - 2))) % 1000000007)) %
             1000000007);
      ans %= 1000000007;
    } else {
      ans = ((((C(n - 2, i - 2) * fact[i - 2]) % 1000000007) *
              ((modulo(m, n - i) * (C(m - 1, i - 2))) % 1000000007)) %
             1000000007);
      ans = ans * ((i * (modulo(n, n - 1 - i))) % 1000000007);
      ans %= 1000000007;
    }
    temp += ans;
    temp %= 1000000007;
  }
  cout << temp;
}
