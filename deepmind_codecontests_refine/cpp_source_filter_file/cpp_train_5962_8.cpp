#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int main() {
  ios_base::sync_with_stdio(false);
  int _;
  int m, d, w;
  for (cin >> _; _ && _--;) {
    cin >> m >> d >> w;
    int d_dcg = gcd(d - 1, w);
    int d1 = (d - 1) / d_dcg;
    int w1 = w / d_dcg;
    int m_w1 = (min(m, d) - 1) / w1;
    cout << 1LL * m_w1 * min(m, d) - w1 * (1 + m_w1) * m_w1 / 2 << endl;
  }
  return 0;
}
