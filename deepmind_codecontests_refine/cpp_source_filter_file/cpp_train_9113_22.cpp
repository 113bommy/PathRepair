#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000003ll;
long long npow[64];
long long fast_pow(long long n, long long e) {
  if (e == 0) return 1ll;
  long long tmp = fast_pow(n, e / 2ll);
  tmp = (tmp * tmp) % MOD;
  if (e & 1ll) return (tmp * n) % MOD;
  return tmp;
}
int main() {
  ios::sync_with_stdio(0);
  npow[0] = 1ll;
  for (int i = 1; i < 63; i++) npow[i] = (npow[i - 1] * 2ll);
  long long n, k;
  cin >> n >> k;
  if (n < 63 && k >= npow[n]) {
    cout << "1 1\n";
    return 0;
  }
  long long tgt = k - 1ll;
  long long pcount = 0;
  long long val = 2ll;
  while (true) {
    long long adder = tgt / val;
    if (!adder) break;
    val *= 2ll;
    pcount += adder;
  }
  long long kmult = n - (pcount / (k - 1));
  long long den = fast_pow(2, k - 1ll);
  den = fast_pow(den, kmult - 1ll);
  den = den * fast_pow(2ll, k - 1 - (pcount % (k - 1)));
  den %= MOD;
  long long num = 0;
  if (k - 1ll < MOD) {
    long long prod = fast_pow(2ll, pcount);
    long long rem = fast_pow(2ll, n);
    num = fast_pow(prod, MOD - 2ll);
    for (int i = 1; i <= k - 1ll; i++) {
      long long mult = rem - i;
      while (mult < 0) mult += MOD;
      num = (num * mult) % MOD;
    }
  }
  num = (den - num);
  while (num < 0) num += MOD;
  cout << num << " " << den << "\n";
  return 0;
}
