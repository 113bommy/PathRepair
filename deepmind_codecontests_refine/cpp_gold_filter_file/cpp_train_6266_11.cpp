#include <bits/stdc++.h>
using namespace std;
inline long long mod(long long n, long long m) {
  long long ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}
long long gcd(long long a, long long b) {
  return (b == 0LL ? a : gcd(b, a % b));
}
long long exp(long long a, long long b, long long m) {
  if (b == 0LL) return 1LL;
  if (b == 1LL) return mod(a, m);
  long long k = mod(exp(a, b / 2, m), m);
  if (b & 1LL) {
    return mod(a * mod(k * k, m), m);
  } else
    return mod(k * k, m);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  int a = 1, b = 2;
  while (a < n and b < n) {
    int c = b + b + 1;
    int d = a + b + 1;
    a = c, b = d;
  }
  if (a == n or b == n) {
    cout << 1 << "\n";
  } else
    cout << 0 << "\n";
}
