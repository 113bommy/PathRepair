#include <bits/stdc++.h>
#pragma GCC optimize("-O2")
using namespace std;
void err(istream_iterator<string> it) { cerr << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << "\t";
  err(++it, args...);
}
template <typename T1, typename T2>
ostream& operator<<(ostream& c, pair<T1, T2>& v) {
  c << "(" << v.first << "," << v.second << ")";
  return c;
}
template <template <class...> class TT, class... T>
ostream& operator<<(ostream& out, TT<T...>& c) {
  out << "{ ";
  for (auto& x : c) out << x << " ";
  out << "}";
  return out;
}
const int LIM = 1e5 + 5, MOD = 1e9 + 7;
int t, n, m, k, x, y, w;
int dp[LIM], tab[LIM], cum[LIM];
void solve(int x) {
  int c = 2;
  int grund[1000] = {0};
  while (tab[c] <= x) {
    if ((x - tab[c]) % c == 0) {
      int in = (x - tab[c]) / c;
      grund[cum[in] ^ cum[in + c]]++;
    }
    ++c;
  }
  int& ans = dp[x];
  while (grund[ans]) ans++;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  dp[0] = dp[1] = dp[2] = 0;
  for (int i = 0; i < 1000; ++i) tab[i] = (i * (i + 1)) / 2;
  for (int i = 3; i < LIM; ++i) {
    solve(i);
    cum[i] = (cum[i - 1] ^ dp[i]);
  }
  cin >> n;
  int c = 2;
  while (tab[c] <= n) {
    if ((n - tab[c]) % c == 0) {
      int in = (n - tab[c]) / c;
      if ((cum[in] ^ cum[in + c]) == 0) {
        cout << c << '\n';
        exit(0);
      }
    }
    ++c;
  }
  cout << -1 << '\n';
  return 0;
}
