#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
long long mul(long long x, long long y) { return ((x % M) * (y % M) % M); }
long long binpow(long long x, long long y) {
  long long z = 1;
  while (y) {
    if (y & 1LL) z = mul(z, x);
    x = mul(x, x);
    y >>= 1LL;
  }
  return z;
}
long long inv(long long x) { return binpow(x, M - 2); }
long long divide(long long x, long long y) { return mul(x, inv(y)); }
int x;
void solve() {
  cin >> x;
  int ans = 0;
  long long sf = 1;
  long long prev = 1;
  while (sf <= x) {
    ++ans;
    long long next = sf + prev;
    prev = sf;
    sf = next;
  }
  cout << ans - 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int q, multicase = 0;
  if (multicase)
    cin >> q;
  else
    q = 1;
  for (int i = 1; i <= q; ++i) solve();
}
