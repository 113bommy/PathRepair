#include <bits/stdc++.h>
using namespace std;
void solutionD();
int main() {
  ios_base::sync_with_stdio(false);
  solutionD();
  return EXIT_SUCCESS;
}
string a, b;
long long dp[1024][1024];
struct command {
  long long x, y, z;
  command(long long x = 0, long long y = 0, long long z = 0)
      : x(x), y(y), z(z) {}
};
pair<pair<long long, long long>, command> p[1024][1024];
void solve() {
  long long n = a.size(), m = b.size();
  for (long long i = 0; i <= n; ++i)
    for (long long j = 0; j <= m; ++j) dp[i][j] = 1000000000;
  dp[0][0] = 0;
  for (long long i = 0; i < n; ++i)
    for (long long j = 0; j < m; ++j) {
      if (a[i] == b[j]) {
        if (dp[i][j] < dp[i + 1][j + 1]) {
          dp[i + 1][j + 1] = dp[i][j];
          p[i + 1][j + 1] = make_pair(make_pair(i, j), command(0, -1, -1));
        }
      } else {
        if (dp[i][j] + 1 < dp[i + 1][j + 1]) {
          dp[i + 1][j + 1] = dp[i][j] + 1;
          p[i + 1][j + 1] = make_pair(make_pair(i, j), command(3, j, b[j]));
        }
        if (dp[i][j] + 1 < dp[i][j + 1]) {
          dp[i][j + 1] = dp[i][j] + 1;
          p[i][j + 1] = make_pair(make_pair(i, j), command(1, j, b[j]));
        }
        if (dp[i][j] + 1 < dp[i + 1][j]) {
          dp[i + 1][j] = dp[i][j] + 1;
          p[i + 1][j] = make_pair(make_pair(i, j), command(2, i, -1));
        }
      }
    }
  assert(dp[n][m] != 1000000000);
  pair<long long, long long> v(n, m);
  vector<command> ans;
  while (v.first != 0 || v.second != 0) {
    command it = p[v.first][v.second].second;
    if (it.x != 0) ans.push_back(it);
    v = p[v.first][v.second].first;
  }
  reverse(ans.begin(), ans.end());
  cout << dp[n][m] << endl;
  for (command it : ans) {
    if (it.x == 1) {
      cout << "INSERT " << it.y + 1 << " " << char(it.z) << '\n';
    } else if (it.x == 2) {
      cout << "DELETE " << it.y + 1 << '\n';
    } else if (it.x == 3) {
      cout << "REPLACE " << it.y + 1 << " " << char(it.z) << '\n';
    }
  }
}
void solutionD() {
  for (; cin >> a >> b;) {
    solve();
    cerr << endl;
  }
}
