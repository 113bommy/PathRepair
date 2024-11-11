#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 69, mod = 998244353;
long long n, m, mx, ind, ans, len, x, y;
long long fix[N], A[N], inv[N], B[N], nam[N], K[N];
vector<long long> v[N];
set<int> s;
set<int>::iterator it;
long long binpow(long long a, long long b) {
  long long ans = 1;
  a %= mod;
  while (b > 0) {
    if (b & 1) ans *= a, ans %= mod;
    a *= a;
    a %= mod;
    b >>= 1;
  }
  return ans;
}
long long calc(int x, int y) {
  long long mni = nam[y];
  mni %= mod;
  long long mri = (K[y - 1] - (x == 1 ? -1 : K[x - 2]) + mod) % mod;
  mri %= mod;
  return (mri * binpow(mni, mod - 2)) % mod;
}
void go() {
  while (ans < 0) {
    ans += mod;
  }
  ans %= mod;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  y = binpow(100, mod - 2);
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    A[i] *= y;
    A[i] %= mod;
  }
  s.insert(1);
  s.insert(n + 1);
  x = 1;
  K[0] = 0;
  nam[0] = 1;
  for (int i = 1; i <= n; i++) {
    nam[i] = ((nam[i - 1] * A[i]) % mod) % mod;
    K[i] = K[i - 1] + nam[i];
    K[i] %= mod;
  }
  ans = calc(1, n);
  ans %= mod;
  while (m--) {
    cin >> x;
    long long ok = 1;
    if (s.find(x) != s.end()) {
      s.erase(x);
      ok = -1;
    }
    it = s.upper_bound(x);
    int k = *(it);
    it--;
    int j = *(it);
    if (ok) s.insert(x);
    ans += calc(j, x - 1) * ok;
    go();
    ans += calc(x, k - 1) * ok;
    go();
    ans -= calc(j, k - 1) * ok;
    go();
    cout << ans << endl;
  }
}
