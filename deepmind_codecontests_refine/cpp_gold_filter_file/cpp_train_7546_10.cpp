#include <bits/stdc++.h>
using namespace std;
long long factorial[300005];
long long inverse(long long k);
long long binpow(long long a, long long b);
long long bc(int n, int k) {
  return factorial[n] * inverse(factorial[k] * factorial[n - k] % 1000000007) %
         1000000007;
}
long long inverse(long long k) { return binpow(k, 1000000007 - 2); }
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
    b >>= 1;
  }
  return res % 1000000007;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 0, q = 2;
  int n;
  cin >> n;
  if (n < 3) {
    if (n == 1)
      cout << 1;
    else
      cout << 4;
    return 0;
  }
  factorial[0] = 1;
  for (int i = 1; i <= 300005; i++) {
    factorial[i] = factorial[i - 1] * i % 1000000007;
  }
  long long ans = bc(n * 2 - 1, n);
  ans *= 2;
  ans += 1000000007 - n;
  ans %= 1000000007;
  cout << ans;
}
