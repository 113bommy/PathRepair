#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("-O3")
using ld = long double;
const long long int mod = 1000000007;
const long long int inf = 1000000000000000000;
const long long int rk = 256;
const ld PI = 3.141592653589793;
ostream& operator<<(ostream& os, pair<long long int, long long int> const& x) {
  os << x.first << "," << x.second;
  return os;
}
template <class T>
ostream& operator<<(ostream& os, vector<T> const& x) {
  os << "{ ";
  for (auto& y : x) os << y << " ";
  return os << "}";
}
template <class T>
ostream& operator<<(ostream& os, set<T> const& x) {
  os << "{ ";
  for (auto& y : x) os << y << " ";
  return os << "}";
}
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os,
                                  Container const& x) {
  os << "{ ";
  for (auto& y : x) os << y << " ";
  return os << "}";
}
template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
  return os << "[ " << p.first << ", " << p.second << "]";
}
struct comp {
  bool operator()(int const& i, int const& j) const { return i > j; }
};
struct Triplet {
  long long int x, y, z;
};
long long int modularexpo(long long int x, long long int n, long long int mod) {
  long long int res = 1;
  while (n > 0) {
    if (n % 2 == 1) res = (res * x) % mod;
    x = (x * x) % mod;
    n = n / 2;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    vector<long long int> graph[n];
    for (long long int i = 0; i < m; i++) {
      long long int u, v;
      cin >> u >> v;
      if (u != v) {
        u -= 1;
        v -= 1;
        graph[v].push_back(u);
      }
    }
    vector<long long int> dp(n, 0);
    vector<long long int> vis(n, 0);
    vector<long long int> ans;
    for (long long int i = 1; i < n; i++) {
      for (auto v : graph[i]) {
        if (vis[i] == 0) {
          dp[i] = max(dp[i], dp[v] + 1);
        }
      }
      if (dp[i] >= 2) {
        ans.push_back(i + 1);
        vis[i] = 1;
      }
    }
    cout << ans.size() << '\n';
    for (auto i : ans) {
      cout << i << " ";
    }
    cout << '\n';
  }
  return 0;
}
