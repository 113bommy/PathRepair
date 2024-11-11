#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,tune=native")
#pragma GCC target("avx,avx2")
long long MOD = 1e9 + 7;
void solve();
signed main() { solve(); }
void solve() {
  int n, m;
  cin >> n >> m;
  if (n >= 4) {
    cout << "-1\n";
    return;
  }
  if (n == 1) {
    cout << "0\n";
    return;
  }
  vector<vector<int>> d(n, vector<int>(m));
  char t;
  for (int i = 0; i < n; i++) {
    for (int q = 0; q < m; q++) {
      cin >> t;
      d[i][q] = t - '0';
    }
  }
  if (n == 2) {
    long long ans1 = 0;
    for (int i = 0; i < m; i++) {
      ans1 += (i + d[0][i] + d[1][i]) % 2;
    }
    long long ans2 = 0;
    for (int i = 0; i < m; i++) {
      ans2 += (i + 1 + d[0][i] + d[1][i]) % 2;
    }
    cout << min(ans1, ans2) << "\n";
    return;
  }
  long long ans = 1e9;
  for (int a = 0; a <= 1; a++) {
    for (int b = 0; b <= 1; b++) {
      for (int c = 0; c <= 1; c++) {
        vector<int> dp_straight(m, -1);
        vector<int> dp_inverse(m, -1);
        int initial = (d[0][0] != a) + (d[1][0] != b) + (d[2][0] != c);
        int ra = 1 - a, rb = b, rc = 1 - c;
        vector<vector<int>> re = {{a, ra}, {b, rb}, {c, rc}};
        dp_straight[0] = initial;
        dp_inverse[0] = initial;
        for (int i = 1; i < m; i++) {
          int da = re[0][i % 2];
          int db = re[1][i % 2];
          int dc = re[2][i % 2];
          int score_straight =
              (d[0][i] != da) + (d[1][i] != db) + (d[2][i] != dc);
          int score_inverse =
              (d[0][i] == da) + (d[1][i] == db) + (d[2][i] == dc);
          dp_straight[i] = min(dp_straight[i - 1] + score_straight,
                               dp_inverse[i - 1] + score_inverse);
          dp_inverse[i] = min(dp_straight[i - 1] + score_inverse,
                              dp_inverse[i - 1] + score_straight);
        }
        long long cans = min(dp_straight[m - 1], dp_inverse[m - 1]);
        ans = min(ans, cans);
      }
    }
  }
  cout << ans << "\n";
}
