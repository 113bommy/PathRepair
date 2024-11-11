#include <bits/stdc++.h>
using namespace std;
long long Pot(long long p, long long w, long long MOD) {
  if (w == 0) return 1;
  if (w % 2 == 0) {
    long long pol = Pot(p, w / 2, MOD);
    return pol * pol % MOD;
  }
  return p * Pot(p, w - 1, MOD) % MOD;
}
long long Pot2(long long p, long long w1, long long w2, long long MOD) {
  if (p % MOD == 0) return 0;
  long long w3 = Pot(w1, w2, MOD - 1);
  return Pot(p, w3, MOD);
}
int main() {
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    long long k, l, r, p;
    cin >> k >> l >> r >> p;
    if (p == 2 && k % 2 == 1) {
      cout << "0" << endl;
      continue;
    }
    long long ilo;
    long long mi = Pot2(k, 2, l, p) - 1;
    if (mi < 0) mi += p;
    if (mi == 0)
      ilo = Pot(2, r - l + 1, p);
    else {
      long long li = Pot2(k, 2, r + 1, p) - 1;
      if (li < 0) li += p;
      ilo = li * Pot(mi, p - 2, p) % p;
    }
    long long odp = ilo;
    if (k % 2 == 1) odp = odp * Pot(Pot(2, r - l, p), p - 2, p) % p;
    cout << odp << endl;
  }
  return 0;
}
