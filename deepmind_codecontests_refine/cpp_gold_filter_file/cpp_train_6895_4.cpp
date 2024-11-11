#include <bits/stdc++.h>
using namespace std;
long long n, d, q, u, v, mod = 998244353ll, invfact[100], fact[100], cont, res,
                         tot, tot2;
vector<pair<long long, int> > fatt;
long long fastp(long long base, long long exp) {
  if (exp == 0) return 1ll;
  long long tmp = fastp(base, exp / 2);
  tmp = (tmp * tmp) % mod;
  if (exp % 2 == 1) tmp *= base;
  return tmp % mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  fact[0] = 1;
  for (long long i = 1; i < 100; i++) fact[i] = (fact[i - 1] * i) % mod;
  invfact[99] = fastp(fact[99], mod - 2ll);
  for (long long i = 98; i >= 0; i--)
    invfact[i] = (invfact[i + 1] * (i + 1ll)) % mod;
  cin >> d;
  for (long long i = 2; (i * i) <= d; i++) {
    if (d % i == 0) {
      cont = 0;
      while (d % i == 0) {
        cont++;
        d /= i;
      }
      fatt.push_back({i, cont});
    }
  }
  if (d != 1) fatt.push_back({d, 1});
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> u >> v;
    if (u < v) swap(u, v);
    tot = tot2 = 0;
    res = 1;
    for (int j = 0; j < fatt.size(); j++) {
      cont = 0;
      while (u % fatt[j].first == 0) {
        u /= fatt[j].first;
        cont++;
      }
      while (v % fatt[j].first == 0) {
        v /= fatt[j].first;
        cont--;
      }
      res *= invfact[abs(cont)];
      res %= mod;
      if (cont > 0)
        tot += cont;
      else
        tot2 += -cont;
    }
    res *= fact[tot];
    res %= mod;
    res *= fact[tot2];
    res %= mod;
    cout << res << "\n";
  }
  return 0;
}
