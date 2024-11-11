#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
void solve() {
  string s;
  cin >> s;
  long long n = s.size();
  long long dp[n + 6][2];
  s += "?????????";
  memset(dp, 0, sizeof dp);
  if (n == 5) {
    cout << 0 << '\n';
    return;
  }
  set<string> ans;
  dp[n - 2][0] = true;
  dp[n - 3][1] = true;
  for (long long i = n - 4; i >= 5; --i) {
    string sub = s.substr(i, 2);
    dp[i][0] = dp[i + 2][1] | (dp[i + 2][0] && sub + sub != s.substr(i, 4) &&
                               sub.back() != '?');
    sub = s.substr(i, 3);
    dp[i][1] = dp[i + 3][0] | (dp[i + 3][1] && sub + sub != s.substr(i, 6) &&
                               sub.back() != '?');
  }
  for (long long i = 0; i < n; ++i) {
    if (dp[i][0]) ans.insert(s.substr(i, 2));
    if (dp[i][1]) ans.insert(s.substr(i, 3));
  }
  cout << ans.size() << '\n';
  for (auto x : ans) cout << x << " ";
  cout << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t = 1;
  while (t--) solve();
}
