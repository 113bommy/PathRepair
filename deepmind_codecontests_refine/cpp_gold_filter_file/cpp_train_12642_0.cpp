#include <bits/stdc++.h>
using namespace std;
inline void EnableFileIO(const string &fileName) {
  if (fileName.empty()) return;
  freopen((fileName + ".in").c_str(), "r", stdin);
  freopen((fileName + ".out").c_str(), "w", stdout);
  return;
}
const int INF = (1 << 30) - 1;
const long long LINF = (1LL << 61) - 1;
const double EPS = 1e-10;
const int N = 5100, P = 1e9 + 7;
const unsigned long long M = 4e7 + 7;
string a, b;
int dp[N][N];
int coma[N], comb[N];
void make(const string &s, int *res) {
  memset(dp, 0, sizeof dp);
  for (int i = s.length() - 1; i >= 0; i--) {
    for (int j = s.length() - 1; j >= 0; j--) {
      if (s[i] == s[j]) dp[i][j] = dp[i + 1][j + 1] + 1;
    }
  }
  for (int i = 0; i < s.length(); i++) {
    for (int j = 0; j < s.length(); j++) {
      if (i == j) continue;
      res[i] = max(res[i], dp[i][j]);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  EnableFileIO("");
  cin >> a >> b;
  make(a, coma);
  make(b, comb);
  int ans = INF;
  memset(dp, 0, sizeof dp);
  for (int i = (int)a.length() - 1; i >= 0; i--) {
    for (int j = (int)b.length() - 1; j >= 0; j--) {
      if (a[i] == b[j]) {
        dp[i][j] = dp[i + 1][j + 1] + 1;
      }
      if (dp[i][j] > coma[i] && dp[i][j] > comb[j]) {
        ans = min(ans, max(coma[i], comb[j]) + 1);
      }
    }
  }
  if (ans == INF) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
