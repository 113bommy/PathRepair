#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007LL;
const long long inf = 1e18;
long long d4_1[4] = {1, 0, -1, 0};
long long d4_2[4] = {0, 1, 0, -1};
long long d8_1[8] = {1, 1, 1, -1, -1, -1, 0, 0};
long long d8_2[8] = {0, -1, 1, 0, -1, 1, 1, -1};
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(char c) { return to_string(string(1, c)); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (long long i = 0; i < static_cast<long long>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void dbg() { cout << endl; }
template <typename Head, typename... Tail>
void dbg(Head H, Tail... T) {
  cout << " " << to_string(H);
  dbg(T...);
}
struct event {
  long long const_equal_above = 0;
  long long length_flag = 0;
  string color;
  long long no_left_flag = 0;
  bool isflag = false;
};
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<string> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  long long ans = 0;
  vector<vector<event>> dp(n, vector<event>(m));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (i > 0) {
        if (v[i][j] == v[i - 1][j]) {
          dp[i][j].const_equal_above = dp[i - 1][j].const_equal_above + 1;
        } else {
          dp[i][j].const_equal_above = 1;
        }
        long long length_flag = dp[i][j].const_equal_above;
        bool isflag = false;
        if (i >= 3 * length_flag - 1) {
          if (dp[i - length_flag][j].const_equal_above == length_flag) {
            if (dp[i - 2 * length_flag][j].const_equal_above == length_flag) {
              char a, b, c;
              a = v[i][j];
              b = v[i - length_flag][j];
              c = v[i - 2 * length_flag][j];
              if (a != b && b != c) {
                isflag = true;
                dp[i][j].isflag = true;
                dp[i][j].length_flag = length_flag;
                string temp_color = "";
                temp_color += to_string(a) + to_string(b) + to_string(c);
                dp[i][j].color = temp_color;
              }
            }
          }
        }
        if (isflag) {
          if (j > 0) {
            if (dp[i][j - 1].isflag &&
                dp[i][j - 1].length_flag == dp[i][j].length_flag &&
                dp[i][j - 1].color == dp[i][j].color) {
              dp[i][j].no_left_flag = dp[i][j - 1].no_left_flag + 1;
            } else {
              dp[i][j].no_left_flag = 1;
            }
          } else {
            dp[i][j].no_left_flag = 1;
          };
          ans += dp[i][j].no_left_flag;
        }
      } else {
        dp[i][j].const_equal_above = 1;
      }
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(10);
  long long t = 1;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
}
