#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool f = 1;
  string r = "{";
  for (const auto& x : v) {
    if (!f) r += ", ";
    f = 0;
    r += to_string(x);
  }
  return r + "}";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
int dp[4200][4200];
int pos[4200];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> cmp;
  vector<int> a(n);
  for (auto i = (0); i <= (n - 1); ++i) cin >> a[i], cmp.push_back(a[i]);
  sort((cmp).begin(), (cmp).end());
  cmp.erase(unique((cmp).begin(), (cmp).end()), cmp.end());
  for (auto i = (0); i <= (n - 1); ++i)
    a[i] = lower_bound((cmp).begin(), (cmp).end(), a[i]) - cmp.begin();
  int ans = min(2, n);
  for (auto i = (n - 1); i >= (0); --i) {
    for (auto j = (i + 1); j <= (n - 1); ++j) {
      dp[i][a[j]] = max({2, dp[i][a[j]], 1 + max(1, dp[j][a[i]])});
      ans = max(ans, dp[i][a[j]]);
    }
  }
  cout << ans;
  return 0;
}
