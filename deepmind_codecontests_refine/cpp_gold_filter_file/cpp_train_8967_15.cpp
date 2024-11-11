#include <bits/stdc++.h>
using namespace std;
namespace Interpolation {
const int mod = (int)1e6 + 3;
const int maxn = 1e5 + 5;
int a[maxn];
int fac[maxn];
int ifac[maxn];
int prf[maxn];
int suf[maxn];
int fpow(int n, int k) {
  int r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = (long long)r * n % mod;
    n = (long long)n * n % mod;
  }
  return r;
}
void upd(int u, int v) { a[u] = v; }
void build() {
  fac[0] = ifac[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fac[i] = (long long)fac[i - 1] * i % mod;
    ifac[i] = fpow(fac[i], mod - 2);
  }
}
int calc(int x, int k) {
  prf[0] = suf[k + 1] = 1;
  for (int i = 1; i <= k; i++) {
    prf[i] = (long long)prf[i - 1] * (x - i + mod) % mod;
  }
  for (int i = k; i >= 1; i--) {
    suf[i] = (long long)suf[i + 1] * (x - i + mod) % mod;
  }
  int res = 0;
  for (int i = 1; i <= k; i++) {
    if (!((k - i) & 1)) {
      res = (res + (long long)prf[i - 1] * suf[i + 1] % mod * ifac[i - 1] %
                       mod * ifac[k - i] % mod * a[i]) %
            mod;
    } else {
      res = (res -
             (long long)prf[i - 1] * suf[i + 1] % mod * ifac[i - 1] % mod *
                 ifac[k - i] % mod * a[i] % mod +
             mod) %
            mod;
    }
  }
  return res;
}
}  // namespace Interpolation
const int mod = (int)1e6 + 3;
vector<pair<int, int> > guess;
void solve() {
  Interpolation::build();
  for (int i = 0; i <= 20; i++) {
    cout << "? " << i << endl;
    cout.flush();
    int resp;
    cin >> resp;
    if (resp == -1) exit(0);
    Interpolation::a[i] = resp;
    guess.push_back(pair<int, int>(i, resp));
  }
  for (int i = 0; i < mod; i++) {
    if (Interpolation::calc(i, 20) % mod == 0) {
      cout << "! " << i;
      return;
    }
  }
  cout << "! -1";
}
int main() {
  ios::sync_with_stdio(0);
  solve();
}
