#include <bits/stdc++.h>
using namespace std;
template <class T, class T2>
inline bool chkmax(T &x, const T2 &y) {
  return x < y ? x = y, 1 : 0;
}
template <class T, class T2>
inline bool chkmin(T &x, const T2 &y) {
  return x > y ? x = y, 1 : 0;
}
const long long mod = 1e9 + 7;
template <class T>
inline void fix(T &x) {
  if (x >= mod | x <= -mod) {
    x %= mod;
  }
  if (x < 0) {
    x += mod;
  }
}
map<long long, long long> cnt;
signed main() {
  long long n, p, k;
  cin >> n >> p >> k;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    long long t = (a * a) % p;
    t = (t * t) % mod;
    t = t - (k * a) % p;
    t %= p;
    if (t < 0) {
      t += p;
    }
    ans += cnt[t];
    cnt[t]++;
  }
  cout << ans << "\n";
  return 0;
}
