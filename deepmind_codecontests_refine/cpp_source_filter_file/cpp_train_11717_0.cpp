#include <bits/stdc++.h>
using namespace std;
long long powq(long long a, long long b, long long n) {
  long long res = 1;
  while (b) {
    if (b % 2) {
      res = (res * a) % n;
    }
    a = (a * a) % n;
    b /= 2;
  }
  return res;
}
int main() {
  long long mod = 1e9 + 7;
  int k;
  cin >> k;
  vector<long long> a(k);
  bool par = true;
  long long dmp = 2, dmt = 2;
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    if (a[i] % 2 == 1) par = !par;
    dmt = powq(dmt, a[i], 3);
    dmp = powq(dmp, a[i], mod);
  }
  bool tr;
  if (par)
    tr = ((dmt + 2) % 3 == 0);
  else
    tr = ((dmt + 1) % 3 == 0);
  long long d, n;
  if (tr) {
    d = dmp;
    if (par)
      n = (dmp + 2) % mod;
    else
      n = (dmp + mod - 2) % mod;
    n = (n * powq(3, mod - 2, mod)) % mod;
  } else {
    d = (dmp * 3) % mod;
    if (par)
      n = (dmp + 2) % mod;
    else
      n = (dmp + mod - 2) % mod;
  }
  n = (n * powq(2, mod - 2, mod)) % mod;
  d = (d * powq(2, mod - 2, mod)) % mod;
  cout << n << "/" << d << endl;
  return 0;
}
