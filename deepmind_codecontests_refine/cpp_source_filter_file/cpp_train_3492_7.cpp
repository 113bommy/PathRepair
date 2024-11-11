#include <bits/stdc++.h>
using namespace std;
long long mod = 1000003;
vector<int> P;
void gcdE(long long a, long long b, long long& d, long long& x, long long& y) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    gcdE(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}
long long inv(long long a, long long n) {
  long long d, x, y;
  gcdE(a, n, d, x, y);
  return d == 1 ? (x + n) % n : -1;
}
long long p(long long x) {
  if (x == 0LL) return 1LL;
  if (P[x] != -1) return P[x];
  return P[x] = (x * p(x - 1)) % mod;
}
long long mul(long long x, long long y) { return (x * y) % mod; }
long long c(long long n, long long m) {
  long long temp = mul(p(m), p(n - m));
  return mul(p(n), inv(temp, mod));
}
int main() {
  int n;
  cin >> n;
  if (n % 2)
    cout << n / 2 << endl;
  else {
    int p = 0;
    while ((1 << p) <= n) p++;
    n -= (1 << p);
    cout << n / 2 << endl;
  }
  return 0;
}
