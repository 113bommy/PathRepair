#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
inline T range(T l, T r) {
  return uniform_int_distribution<T>(l, r)(rng);
}
inline void setin(string s) { freopen(s.c_str(), "r", stdin); }
inline void setout(string s) { freopen(s.c_str(), "w", stdout); }
template <typename T>
void Min(T &a, T b) {
  a = min(a, b);
}
template <typename T>
void Max(T &a, T b) {
  a = max(a, b);
}
const int p = 41;
const int mod = 1e9 + 7;
const int inf = 2e9;
const int N = 2e3 + 15;
int n, t, a[N];
bitset<N> dp;
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    dp.reset();
    dp[0] = 1;
    cin >> n;
    for (int i = 1; i <= n + n; ++i) cin >> a[i];
    int mx = 0;
    for (int i = 1; i <= n + n; ++i) {
      if (a[i] > a[mx]) {
        if (mx) dp |= dp << (i - mx);
        mx = i;
      }
    }
    dp |= dp << (n + 1 - mx);
    cout << (dp[n] ? "YES" : "NO") << '\n';
  }
  return 0;
}
