#include <bits/stdc++.h>
using namespace std;
int inf = INT_MAX;
long long modulo(long long num, long long MOD = 998244353) {
  return ((num % MOD) + MOD) % MOD;
}
long long power(long long b, long long e, long long MOD = 998244353) {
  long long ans = 1;
  while (e) {
    if (e % 2) ans = (ans * b) % MOD;
    b = (b * b) % MOD;
    e /= 2;
  }
  return ans;
}
long long inv(long long num, long long MOD = 998244353) {
  return power(modulo(num), MOD - 2, MOD);
}
long long gcd(long long a, long long b) {
  return ((b == 0) ? a : gcd(b, a % b));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long q;
  cin >> q;
  while (q-- > 0) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long sum = a + b + c + 1;
    cout << sum / 2 << endl;
  }
  return 0;
}
