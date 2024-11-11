#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
using namespace std;
template <typename T>
void uin(T &a, T b) {
  if (b < a) {
    a = b;
  }
}
template <typename T>
void uax(T &a, T b) {
  if (b > a) {
    a = b;
  }
}
struct offer {
  long long a, b, k;
  offer() {}
  offer(long long _a, long long _b, long long _k) {
    a = _a;
    b = _b;
    k = _k;
  }
};
bool operator<(offer fir, offer sec) { return fir.b < sec.b; }
long long dp[555];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<offer> off(n);
  for (long long i = 0; i < n; ++i) {
    cin >> off[i].a >> off[i].b >> off[i].k;
  }
  sort(off.rbegin(), off.rend());
  for (auto of : off) {
    for (long long i = n; i > -1; --i) {
      uax(dp[i + 1], dp[i] + of.a - of.b * i);
      uax(dp[i], dp[i] + of.a - of.b * of.k);
    }
  }
  long long res = 0;
  for (long long i = 0; i <= n; ++i) {
    uax(res, dp[i]);
  }
  cout << res << '\n';
  return 0;
}
