#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
vector<pair<long long, int> > veki;
int bp[40];
long long fakt[30], inv[30];
long long gcd(long long a, long long b) {
  long long t;
  while (a) {
    t = a;
    a = b % a;
    b = t;
  }
  return b;
}
long long inverz(long long first) {
  long long s = first;
  long long ret = 1ll;
  for (int i = 0; i < 32; i++) {
    if (bp[i]) ret = (ret * s) % mod;
    s = (s * s) % mod;
  }
  return ret;
}
int main() {
  long long n;
  cin >> n;
  for (long long i = 2ll; i * i <= n; i++) {
    if (n % i == 0ll) {
      int ai = 0;
      while (n % i == 0) {
        ai++;
        n /= i;
      }
      veki.push_back(make_pair(i, ai));
    }
  }
  if (n > 1) veki.push_back(make_pair(n, 1));
  int q;
  cin >> q;
  fakt[0] = 1ll;
  int br = 0;
  int k = mod - 2;
  while (k) {
    bp[br] = k % 2;
    k /= 2;
    br++;
  }
  for (long long i = 1ll; i < 29; i++) {
    fakt[i] = (fakt[i - 1] * i) % mod;
  }
  for (long long i = 1ll; i < 29; i++) {
    inv[i] = inverz(fakt[i]);
  }
  for (int i = 0; i < q; i++) {
    long long first, second;
    cin >> first >> second;
    long long g = gcd(first, second);
    long long x1 = first / g;
    long long y1 = second / g;
    int brx = 0, bry = 0;
    long long sx = 1ll, sy = 1ll;
    for (int j = 0; j < veki.size(); j++) {
      if (x1 % veki[j].first == 0ll) {
        int ax = 0;
        while (x1 % veki[j].first == 0ll) {
          ax++;
          brx++;
          x1 /= veki[j].first;
        }
        sx = (sx * inv[ax]) % mod;
      }
      if (y1 % veki[j].first == 0ll) {
        int ay = 0;
        while (y1 % veki[j].first == 0ll) {
          ay++;
          bry++;
          y1 /= veki[j].first;
        }
        sy = (sy * inv[ay]) % mod;
      }
    }
    sx = (sx * fakt[brx]) % mod;
    sy = (sy * fakt[bry]) % mod;
    cout << (sx * sy) % mod << endl;
  }
  return 0;
}
