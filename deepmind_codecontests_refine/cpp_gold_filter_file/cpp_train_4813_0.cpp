#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long LMT = 100000000;
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  vector<long long> v[20001];
  for (long long i = 1; i < 20001; i++) {
    long long cc = i;
    while (cc < 20001) {
      v[i].push_back(cc);
      cc += i;
    }
  }
  while (t--) {
    long long n, i, j, k, l, a, b, c, ans = LMT;
    cin >> a >> b >> c;
    long long curr = LMT;
    long long aa = a, bb = b, cc = c;
    for (long long i = 1; i <= 20000; i++) {
      curr = abs(a - i);
      for (auto z : v[i]) {
        long long tp = abs(b - z);
        tp += curr;
        for (auto zz : v[z]) {
          long long ca = (tp + abs(c - zz));
          if (ca < ans) {
            aa = i;
            bb = z;
            cc = zz;
            ans = ca;
          }
        }
      }
    }
    cout << ans << endl;
    cout << aa << " " << bb << " " << cc << endl;
  }
  return 0;
}
