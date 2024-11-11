#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
const long long N = 0;
void solve() {
  long long n;
  cin >> n;
  if (n % 2 == 0) {
    n--;
    long long x = n / 2;
    long long y = n - x;
    cout << x << " " << y << " " << 1 << "\n";
    return;
  }
  long long f = n;
  long long p = n / f;
  f--;
  long long xx = f / 2;
  if (xx & 1) {
    cout << p * (xx - 2) << " " << (f - xx + 2) * p << " " << p << "\n";
  } else
    cout << p * (xx - 1) << " " << (xx + 1) * p << " " << p << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
}
