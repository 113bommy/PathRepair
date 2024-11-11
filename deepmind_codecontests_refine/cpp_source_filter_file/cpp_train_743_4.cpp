#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, unsigned long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) {
      res = res * x;
    }
    y = y >> 1;
    x = x * x;
  }
  return res;
}
long long int powermod(long long int x, unsigned long long int y,
                       long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % p;
    }
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int32_t main() {
  long long int n, k, m, q;
  cin >> n >> k >> m >> q;
  long long int l = 1, r = n + 1, d = k;
  for (long long int i = (long long int)(0); i < (long long int)(q); i++) {
    long long int ch;
    cin >> ch;
    if (ch == 0) {
      long long int pos;
      cin >> pos;
      if (pos <= d) {
        d -= pos;
        n -= pos;
      } else {
        n = pos;
      }
    } else {
      long long int pos;
      cin >> pos;
      if (pos <= d) {
        d += 1;
        n += 1;
      } else {
        n += 1;
      }
    }
    cout << n << " " << d << "\n";
  }
  return 0;
}
