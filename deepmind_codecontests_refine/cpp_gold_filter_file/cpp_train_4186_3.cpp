#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& out, vector<T> a) {
  for (int i = (int)(0); i < (int)((int)a.size()); i++)
    if (i != (int)a.size() - 1)
      out << a[i] << " ";
    else
      out << a[i] << endl;
  return out;
}
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2>& a) {
  out << a.first << " " << a.second;
  return out;
}
struct fastio {
  fastio() {
    string filename = "";
    if (filename.size()) {
      string inp = filename + ".in";
      string out = filename + ".out";
      freopen(inp.c_str(), "r", stdin);
      freopen(out.c_str(), "w", stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << showpoint;
    cout << setprecision(12);
    cout << fixed;
    cerr << showpoint;
    cerr << setprecision(3);
    cerr << fixed;
  }
} _____;
const int MAX = 2e6 + 10;
const long long INF = 1e9 + 10;
const long double EPS = 1e-8;
const long long MOD = 1e9 + 7;
int dp[1010][2];
void solve() {
  int T;
  cin >> T;
  for (int ___ = (int)(0); ___ < (int)(T); ___++) {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int ans = n;
    for (int i = (int)(0); i < (int)(n + 1); i++) dp[i][0] = dp[i][1] = 0;
    for (int i = (int)(0); i < (int)(n); i++) {
      dp[i + 1][0] = dp[i][0] + 1;
      dp[i + 1][1] = dp[i][1] + 1;
      if (s[i] == '1') {
        for (int j = (int)(0); j < (int)(i + 1); j++) {
          dp[i + 1][0] = max(dp[i + 1][0], dp[j][1] + i - j + 2);
          ans = max(ans, dp[j][1] + i - j + 2 + i - j);
          dp[i + 1][1] = max(dp[i + 1][1], dp[j][0] + i - j + 2);
          ans = max(ans, dp[j][0] + i - j + 2 + i - j);
        }
      }
      ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    for (int i = (int)(0); i < (int)(n + 1); i++) dp[i][0] = dp[i][1] = 0;
    reverse(s.begin(), s.end());
    for (int i = (int)(0); i < (int)(n); i++) {
      dp[i + 1][0] = dp[i][0] + 1;
      dp[i + 1][1] = dp[i][1] + 1;
      if (s[i] == '1') {
        for (int j = (int)(0); j < (int)(i + 1); j++) {
          dp[i + 1][0] = max(dp[i + 1][0], dp[j][1] + i - j + 2);
          ans = max(ans, dp[j][1] + i - j + 2 + i - j);
          dp[i + 1][1] = max(dp[i + 1][1], dp[j][0] + i - j + 2);
          ans = max(ans, dp[j][0] + i - j + 2 + i - j);
        }
      }
      ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    cout << ans << endl;
  }
}
int main() {
  solve();
  return 0;
}
