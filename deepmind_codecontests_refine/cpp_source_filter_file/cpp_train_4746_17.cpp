#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
const int mod = (int)1e9 + 7;
vector<string> vert = {".........", "....O....", "..O...O..", "..O.O.O..",
                       "O.O...O.O", "O.O.O.O.O", "O.OO.OO.O"},
               hori = {".........", "....O....", "O.......O", "O...O...O",
                       "O.O...O.O", "O.O.O.O.O", "OOO...OOO"};
const long long MAX = 300;
char s[MAX * 4][MAX * 4];
bool is_vert[MAX][MAX], is_hori[MAX][MAX];
bool vertical(long long i, long long j) {
  return is_vert[i][j] && is_vert[i][j + 1];
}
bool horisontal(long long i, long long j) {
  return is_hori[i][j] && is_hori[i][j + 1];
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  long long n, m;
  cin >> n >> m;
  for (long long i = 0; i <= 4 * n; i++) {
    for (long long j = 0; j <= 4 * m; j++) cin >> s[i][j];
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      long long x = i * 4 + 1, y = j * 4 + 1;
      string link = "";
      for (long long t = 0; t < 9; t++) link += s[x + t / 3][y + t % 3];
      if (find(vert.begin(), vert.end(), link) != vert.end())
        is_vert[i][j] = true;
      if (find(hori.begin(), hori.end(), link) != hori.end())
        is_hori[i][j] = true;
    }
  }
  vector<long long> p(m + 1, 0);
  for (long long i = 0; i < m; i++) {
    bool ok = true;
    for (long long j = 0; j < n; j++)
      if (is_vert[j][i] == 0) ok = false;
    if (ok && n % 2 == 0) p[i] = 1;
  }
  vector<long long> q(m);
  for (long long i = 0; i < m - 1; i++) {
    vector<long long> temp_q(n);
    if (horisontal(0, i)) temp_q[0]++;
    if (horisontal(0, i) && horisontal(1, i)) temp_q[1]++;
    if (vertical(0, i), vertical(1, i)) temp_q[1]++;
    for (long long j = 2; j < n; j++) {
      temp_q[j] = (horisontal(j, i) * temp_q[j - 1] +
                   vertical(j, i) * vertical(j - 1, i) * temp_q[j - 2]) %
                  mod;
    }
    q[i] = temp_q[n - 1];
    if (q[i] >= mod) q[i] %= mod;
  }
  long long dp[MAX];
  dp[1] = p[0];
  dp[2] = q[0];
  for (long long i = 3; i <= m; i++) {
    dp[i] = dp[i - 2] * q[i - 2] + dp[i - 1] * p[i - 1] -
            dp[i - 2] * p[i - 2] * p[i - 1];
    if (dp[i] >= mod) dp[i] %= mod;
  }
  cout << dp[m];
  return 0;
}
