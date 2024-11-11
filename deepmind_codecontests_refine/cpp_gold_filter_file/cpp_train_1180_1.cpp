#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int inf = numeric_limits<int>::max() / 2;
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
int n, k;
vector<int> a;
unordered_map<int, int> cnt;
inline void solve() {
  long long ans = 0;
  int j = 0;
  for (int i = 0; i < n; i++) {
    while (j <= n) {
      if (j && cnt[a[j - 1]] == k) {
        ans += n - (j - 1);
        break;
      }
      if (j == n) {
        break;
      }
      ++cnt[a[j]];
      if (cnt[a[j]] == k) {
        ans += n - j;
        ++j;
        break;
      }
      ++j;
    }
    --cnt[a[i]];
  }
  cout << ans << "\n";
}
inline void read() {
  cin >> n >> k;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
}
