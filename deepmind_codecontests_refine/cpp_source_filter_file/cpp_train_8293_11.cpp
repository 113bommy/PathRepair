#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll P = 998244353;
ll pwr(ll a, ll k) {
  if (k == 0) return 1;
  return (k & 1 ? (a * pwr(a, k - 1)) % P : pwr((a * a) % P, k / 2));
}
int n;
vector<ll> dwum(1000002);
vector<ll> sil(1000002);
vector<ll> silin(1000002);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  sil[0] = silin[0] = dwum[0] = 1;
  for (int i = 0; i < n; ++i) {
    sil[i + 1] = (sil[i] * (i + 1)) % P;
    silin[i + 1] = pwr(sil[i + 1], P - 2);
  }
  for (int i = 0; i < n; ++i)
    dwum[i + 1] = (((sil[n] * silin[i + 1]) % P) * silin[n - i - 1]) % P;
  ll ans = 0, muler = 2 * pwr(3, n * n - n + 1),
     hlp = (P - pwr(3, n * (P - 2) + 1)) % P;
  for (int i = 0; i < n; ++i) {
    ans += dwum[i + 1] * muler;
    ans %= P;
    muler *= hlp;
    muler %= P;
  }
  ll ansm = 0, hlp2;
  muler = -1;
  for (int a = 0; a < n; ++a) {
    hlp = (P - pwr(3, a)) % P;
    hlp2 = pwr(hlp + 1, n) - pwr(hlp, n);
    hlp2 = (P + hlp2) % P;
    hlp2 *= dwum[a];
    hlp2 %= P;
    if (muler == -1) {
      hlp2 = (P - hlp2) % P;
    }
    ansm += hlp2;
    muler = -muler;
  }
  cout << (ans + 3 * ansm) % P << (char)10;
}
