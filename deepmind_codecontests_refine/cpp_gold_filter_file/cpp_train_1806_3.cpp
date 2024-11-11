#include <bits/stdc++.h>
using namespace std;
const static int inf = 10000000;
const static int mod = 1000000007;
long long modpow(long long a, long long r, long long p) {
  if (r == 0ll) return 1ll;
  long long init = r % 2 == 1ll ? a : 1ll;
  long long tmp = modpow(a, r / 2, p);
  long long buf = (tmp * tmp + p) % p;
  return (buf * init + p) % p;
}
long long minus_one(long long a, long long p) {
  if (a > 0) {
    return a - 1;
  } else {
    return p - 1;
  }
}
int calc(long long k, long long l, long long r, long long p) {
  long long x = modpow(k, (modpow(2ll, l, p - 1) + (p - 1)), p);
  long long ret;
  if (x == 1) {
    ret = modpow(2ll, r - l + 1, p);
  } else {
    ret = minus_one(modpow(x, (modpow(2ll, r - l + 1, p - 1) + (p - 1)), p), p);
    long long y = minus_one(x, p);
    ret = (ret * modpow(y, p - 2, p) + p) % p;
  }
  if (k % 2 == 1) {
    long long div = modpow(2ll, r - l, p);
    ret = (ret * modpow(div, p - 2, p) + p) % p;
  }
  return ret;
}
int calc2(long long k, long long l, long long r) {
  if (k % 2 == 1) {
    return 0;
  } else {
    return 1;
  }
}
int main() {
  int t;
  while (cin >> t) {
    for (int i = 0; i < (int)(t); i++) {
      long long k, l, r, p;
      cin >> k >> l >> r >> p;
      if (p == 2) {
        cout << calc2(k, l, r) << endl;
      } else {
        cout << calc(k, l, r, p) << endl;
      }
    }
  }
  return 0;
}
