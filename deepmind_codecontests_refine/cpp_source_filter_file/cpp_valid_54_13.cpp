#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
int n, k;
long long f[200005];
long long ff;
long long powlc(long long ac, long long bc) {
  if (bc == 0) return 1;
  if (bc == 1) return (ac % mod);
  long long cc = powlc(ac, bc / 2) % mod;
  cc = (cc * cc) % mod;
  if (bc % 2 == 1) cc = (cc * ac) % mod;
  return cc;
}
long long Cmod(int nx, int mx) {
  long long res =
      ((f[nx] * powlc(f[mx], mod - 2) % mod) * powlc(f[nx - mx], mod - 2)) %
      mod;
  return res;
}
void process() {
  f[0] = 1;
  for (int i = 1; i <= 200000; i++) {
    f[i] = (f[i - 1] * i) % mod;
  }
  int tcase = 1;
  cin >> tcase;
  while (tcase--) {
    cin >> n >> k;
    if (k == 0) {
      cout << 1 << endl;
      continue;
    }
    ff = 1;
    for (int i = 2; i <= n; i += 2) {
      ff = (ff + Cmod(n, i)) % mod;
    }
    if (n % 2 == 1)
      ff = (ff + 1) % mod;
    else
      ff = (ff - 1 + mod) % mod;
    long long res = 0;
    long long bounus = 1;
    for (int i = k; i >= 1; i--) {
      if (n % 2 == 0) {
        res = (res + (bounus * powlc(powlc(2, k - 1), n) % mod)) % mod;
      }
      bounus = (bounus * ff) % mod;
    }
    res = (res + bounus) % mod;
    cout << res << endl;
  }
}
int online = 2;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (online == 0) {
    freopen("in.inp", "r", stdin);
    freopen("out.out", "w", stdout);
  } else if (online == 1) {
    freopen(".inp", "r", stdin);
    freopen(".out", "w", stdout);
  }
  process();
  return 0;
}
