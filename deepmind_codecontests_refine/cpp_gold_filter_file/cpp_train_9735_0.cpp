#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000000 + 7;
long long p, k;
long long po(long long b, long long e, long long mo) {
  long long r = 1;
  while (e--) {
    r *= b;
    r %= mo;
  }
  return r;
}
int main() {
  cin >> p >> k;
  if (!k) {
    cout << po(p, p - 1, mod) << endl;
    return 0;
  }
  long long o = 1, i = k;
  while (i != 1) {
    o++;
    i *= k;
    i %= p;
  }
  long long r;
  k == 1 ? r = p : r = 1;
  r *= po(p, (p - 1) / o, mod);
  r %= mod;
  cout << r << endl;
  return 0;
}
