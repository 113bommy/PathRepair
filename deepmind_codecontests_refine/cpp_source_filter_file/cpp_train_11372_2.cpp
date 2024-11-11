#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
struct greateri {
  template <class T>
  bool operator()(T const &a, T const &b) const {
    return a > b;
  }
};
void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
int main() {
  long long u, v;
  cin >> u >> v;
  if (u > v || (abs(u - v)) % 2)
    cout << -1;
  else if (u == 0 && v == 0)
    cout << 0;
  else if (u == v) {
    cout << 1 << '\n';
    cout << u;
  } else {
    long long a = (v - u) / 2;
    bool ka = 1;
    long long ans1 = 0, ans2 = 0;
    for (int i = 0; i <= 32; ++i) {
      if ((u & ((long long)(pow(2, i)))) && !(a & ((long long)(pow(2, i))))) {
        ans1 |= ((long long)(pow(2, i)));
      }
      if (!(u & ((long long)(pow(2, i)))) && (a & ((long long)(pow(2, i))))) {
        ans1 |= ((long long)(pow(2, i)));
        ans2 |= ((long long)(pow(2, i)));
      }
      if ((u & ((long long)(pow(2, i)))) && (a & ((long long)(pow(2, i))))) {
        ka = 0;
        break;
      }
    }
    if (ka) {
      cout << 2 << '\n';
      cout << ans1 << " " << ans2;
    } else {
      cout << 3 << '\n';
      cout << u << " " << (v - u) / 2 << " " << (v - u) / 2;
    }
  }
  return 0;
}
