#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long inf = numeric_limits<long long>::max() / 2;
const long double eps = 1e-9;
const long double pi = acos(-1);
template <typename T>
inline bool mineq(T& a, T b) {
  return (a > b) ? (a = b, 1) : 0;
}
template <typename T>
inline bool maxeq(T& a, T b) {
  return (a < b) ? (a = b, 1) : 0;
}
inline void solve(), read();
const string file = "";
int main() {
  if (file != "") {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  read();
  solve();
  return 0;
}
long long x, y;
string ans;
long long gcd(long long x, long long y) {
  while (x != 0 && y != 0) {
    if (x > y) {
      if (y != 1) {
        ans += to_string(x / y) + "A";
      } else {
        ans += to_string(x / y - 1) + "A";
      }
      x %= y;
    } else if (x < y) {
      if (x != 1) {
        ans += to_string(y / x) + "B";
      } else {
        ans += to_string(y / x - 1) + "B";
      }
      y %= x;
    } else {
      break;
    }
  }
  return x ? x : y;
}
inline void solve() {
  long long g = gcd(x, y);
  if (g != 1) {
    cout << "Impossible"
         << "\n";
  } else {
    cout << ans << "\n";
  }
}
inline void read() { cin >> x >> y; }
