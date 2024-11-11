#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << "\n"; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
void solve() {
  long long n, m;
  cin >> n >> m;
  char c[n][m];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> c[i][j];
    }
  }
  if (n >= 4 && m >= 4) {
    cout << -1 << "\n";
  } else {
    if (n == 1 || m == 1) {
      cout << 0 << "\n";
    } else if (n == 2 || m == 2) {
      char a[max(n, m)][2];
      if (n == 2) {
        for (long long i = 0; i < n; i++) {
          for (long long j = 0; j < m; j++) {
            a[j][i] = c[i][j];
          }
        }
        swap(n, m);
      } else {
        for (long long i = 0; i < n; i++) {
          for (long long j = 0; j < m; j++) {
            a[i][j] = c[i][j];
          }
        }
      }
      vector<long long> v;
      for (long long i = 0; i < n; i++) {
        long long val = 0;
        for (long long j = 0; j < m; j++) {
          if (a[i][j] == '1') {
            val |= (1 << j);
          }
        }
        v.push_back(val);
      }
      long long dp[n][4];
      for (auto &c : dp) {
        for (auto &d : c) d = 1e18;
      }
      for (long long i = 0; i < 4; i++) {
        dp[0][i] = __builtin_popcountll(v[0] ^ i);
      }
      for (long long i = 1; i < n; i++) {
        for (long long j = 0; j < 4; j++) {
          for (long long k = 0; k < 4; k++) {
            if ((__builtin_popcountll(j) + __builtin_popcountll(k)) & 1) {
              dp[i][j] =
                  min(dp[i][j], dp[i - 1][k] + __builtin_popcountll(j ^ v[i]));
            }
          }
        }
      }
      cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2], dp[n - 1][3]})
           << "\n";
    } else {
      char a[max(n, m)][3];
      if (n == 3) {
        for (long long i = 0; i < n; i++) {
          for (long long j = 0; j < m; j++) {
            a[j][i] = c[i][j];
          }
        }
        swap(n, m);
      } else {
        for (long long i = 0; i < n; i++) {
          for (long long j = 0; j < m; j++) {
            a[i][j] = c[i][j];
          }
        }
      }
      vector<long long> v;
      for (long long i = 0; i < n; i++) {
        long long val = 0;
        for (long long j = 0; j < m; j++) {
          if (a[i][j] == '1') {
            val |= (1 << j);
          }
        }
        v.push_back(val);
      }
      long long dp[n][8];
      for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < 8; j++) {
          dp[i][j] = 1e18;
        }
      };
      for (long long i = 0; i < 8; i++) {
        dp[0][i] = __builtin_popcountll(v[0] ^ i);
      }
      for (long long i = 1; i < n; i++) {
        for (long long j = 0; j < 8; j++) {
          for (long long k = 0; k < 8; k++) {
            if (((__builtin_popcountll(j & 6) + __builtin_popcountll(k & 6)) &
                 1) &&
                ((__builtin_popcountll(j & 3) + __builtin_popcountll(k & 3)) &
                 1)) {
              dp[i][j] =
                  min(dp[i][j], dp[i - 1][k] + __builtin_popcountll(j ^ v[i]));
            }
          }
        }
      }
      cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2], dp[n - 1][3],
                   dp[n - 1][4], dp[n - 1][5], dp[n - 1][6], dp[n - 1][7]})
           << "\n";
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}
