#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma warning(disable : 4996)
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
inline void accell() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
}
void say(string s) {
  cout << s << endl;
  return;
}
template <class T>
ostream& operator<<(ostream& out, const pair<int, int>& X) {
  out << X.first << ' ' << X.second << endl;
  return out;
}
template <class T>
ostream& operator<<(ostream& out, const vector<T>& X) {
  for (const auto& it : X) out << it << ' ';
  return out;
}
template <class T>
ostream& operator<<(ostream& out, const set<T>& X) {
  for (const auto& it : X) out << it << ' ';
  return out;
}
template <class T>
void dbg(const T& X) {
  cerr << "DEBUG: "
       << ": ";
  cerr << X << endl;
}
const int MOD1 = 1e9 + 7;
const int N = 1e6 + 1;
const int MOD2 = 998244353;
const ll inf = 3e18;
const int mx = (1 << 19) - 1;
const int mod = 1e9 + 7;
const ull K = 147;
const ll mod2 = (ll)mod * (ll)mod;
signed main() {
  accell();
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> brd(n + 5, vector<pair<int, int>>(m + 5));
  for (int i = 1; i <= n; ++i) {
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      int l, r;
      cin >> l >> r;
      for (int c = l; c <= r; ++c) {
        brd[i][c] = {l, r};
      }
    }
  }
  vector<vector<int>> dp(n + 5, vector<int>(m + 5, 0));
  for (int len = 1; len <= m; ++len) {
    for (int l = 1; l + len <= m; ++l) {
      int r = l + len;
      for (int mid = l; mid <= r; ++mid) {
        int calc = 0;
        for (int c = 1; c <= n; ++c) {
          if (brd[c][mid].first >= l && brd[c][mid].second <= r) calc++;
        }
        dp[l][r] = max(dp[l][r], dp[l][mid - 1] + dp[mid + 1][r] + calc * calc);
      }
    }
  }
  cout << dp[1][m];
  return 0;
}
