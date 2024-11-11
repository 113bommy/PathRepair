#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
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
  for (const auto& x : v) {
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
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const long long INF = 1e13 + 7;
const long long N = 2e2 + 5;
const long double EPS = 1e-12;
const long long MOD = 1e8;
long long dp[N][N][2][12];
void solve() {
  long long n1, n2, k1, k2;
  cin >> n1 >> n2 >> k1 >> k2;
  long long n = n1 + n2;
  dp[1][0][0][1] = 1;
  dp[0][1][1][1] = 1;
  for (long long i = 0; i <= n1; i++) {
    for (long long j = 0; j <= n2; j++) {
      for (long long k = 0; k < 2; k++) {
        for (long long len = 1; len <= (k ? min(k2, j) : min(k1, i)); len++) {
          if (len == 1) {
            for (long long lenPrev = 1;
                 lenPrev <= (!k ? min(k2, j) : min(k1, i)); lenPrev++) {
              if (k) {
                dp[i][j][1][len] =
                    (dp[i][j][1][len] + dp[i][j - 1][0][lenPrev]) % MOD;
              } else {
                dp[i][j][0][len] =
                    (dp[i][j][0][len] + dp[i - 1][j][1][lenPrev]) % MOD;
              }
            }
          } else {
            if (k) {
              dp[i][j][1][len] =
                  (dp[i][j][1][len] + dp[i][j - 1][1][len - 1]) % MOD;
            } else {
              dp[i][j][0][len] =
                  (dp[i][j][0][len] + dp[i - 1][j][0][len - 1]) % MOD;
            }
          }
        }
      }
    }
  }
  long long res = 0;
  for (long long len = 1; len <= max(k1, k2); len++) {
    res = (res + dp[n1][n2][1][len] + dp[n1][n2][0][len]) % MOD;
  }
  cout << res;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long tests = 1;
  while (tests-- > 0) {
    solve();
  }
  return 0;
}
