#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000126;
int n, m, a, q;
int factorials[MAXN];
int ans[MAXN];
int binpow(int a, int pwr, int q) {
  int res = 1;
  while (pwr > 0) {
    if (pwr & 1) res = (1ll * res * a) % q;
    a = (a * a) % q;
    pwr >>= 1;
  }
  return res;
}
int cnk(int n, int k, int phi) {
  if (k > n || k < 0) return 0;
  int nfact = factorials[n];
  int kfact = factorials[k];
  int nkfact = factorials[n - k];
  int res = (1ll * nfact * binpow(kfact, phi - 2, phi)) % phi;
  res = (1ll * res * binpow(nkfact, phi - 2, phi)) % phi;
  return res;
}
int main() {
  ios_base::sync_with_stdio();
  cin.tie(0);
  cin >> n >> m >> a >> q;
  int phi = 1;
  int cur = a;
  while (cur != 1) {
    cur = (1ll * cur * a) % q;
    phi++;
  }
  factorials[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    factorials[i] = (1ll * factorials[i - 1] * i) % phi;
  }
  ans[n] = 1;
  for (int i = n - 1; i >= 0; i--) {
    int power = cnk(m, n - 1 - i, phi);
    ans[i] = (1ll * ans[i + 1] * binpow(a, power, q)) % q;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
}
