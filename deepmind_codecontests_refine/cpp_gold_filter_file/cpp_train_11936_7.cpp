#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long MD = 1e9 + 7;
unsigned long long n, m, s1[100001], s2[100001], p;
unsigned long long binpow(unsigned long long a, unsigned long long b) {
  if (b == 1) return a % MD;
  if (b % 2 == 0) {
    unsigned long long res = binpow(a, b / 2);
    return (res * res) % MD;
  } else {
    return (a * binpow(a, b - 1)) % MD;
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m;
  for (unsigned long long i = 1; i <= n; i++) cin >> s1[i];
  for (unsigned long long i = 1; i <= n; i++) cin >> s2[i];
  unsigned long long c = 1;
  bool broken = false;
  for (unsigned long long i = 1; i <= n; i++) {
    if (s1[i] == 0 && s2[i] > 0) {
      p += (((m - s2[i]) * binpow(m, MD - 2)) % MD * c) % MD;
      p %= MD;
      c = (c * (1 * binpow(m, MD - 2))) % MD;
    } else {
      if (s2[i] == 0 && s1[i] > 0) {
        p += (((s1[i] - 1) * binpow(m, MD - 2)) % MD * c) % MD;
        p %= MD;
        c = (c * (1 * binpow(m, MD - 2))) % MD;
      } else {
        if (s2[i] == 0 && s1[i] == 0) {
          p += (((m * (m - 1)) % MD * binpow(((m * m) % MD * 2) % MD, MD - 2)) %
                MD * c) %
               MD;
          p %= MD;
          c = (c * 1 * (binpow(m, MD - 2))) % MD;
        } else if (s1[i] > s2[i]) {
          p += c * 1;
          p %= MD;
          broken = 1;
          break;
        } else if (s2[i] > s1[i]) {
          p += c * 0;
          broken = 1;
          break;
        } else
          continue;
      }
    }
  }
  cout << p << endl;
}
