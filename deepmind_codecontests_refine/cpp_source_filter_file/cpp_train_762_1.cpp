#include <bits/stdc++.h>
using namespace std;
bool debug = false;
bool pB[1000005], pW[1000005];
int dp[1000005][3][3];
const long long mod = 1e9 + 9;
void add(int& a, int b) {
  a += b;
  if (a < 0) {
    a += mod;
  }
  if (a >= mod) {
    a -= mod;
  }
}
string s;
int n, k;
int main(int argc, char* argv[]) {
  ios::sync_with_stdio(0);
  cin >> n >> k >> s;
  int lastB = -1, lastW = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'B') {
      if (i - lastB >= k) pB[i] = true;
      lastW = i;
    }
    if (s[i] == 'W') {
      if (i - lastW >= k) pW[i] = true;
      lastB = i;
    }
    if (s[i] == 'X') {
      if (i - lastB >= k) pB[i] = true;
      if (i - lastW >= k) pW[i] = true;
    }
  }
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      if (s[i] == 'X') {
        add(dp[i + 1][j][0], dp[i][j][0]);
        add(dp[i + 1][j][0], dp[i][j][1]);
        add(dp[i + 1][j][1], dp[i][j][0]);
        add(dp[i + 1][j][1], dp[i][j][1]);
      }
      if (s[i] == 'W') {
        add(dp[i + 1][j][0], dp[i][j][0]);
        add(dp[i + 1][j][0], dp[i][j][1]);
      }
      if (s[i] == 'B') {
        add(dp[i + 1][j][1], dp[i][j][0]);
        add(dp[i + 1][j][1], dp[i][j][1]);
      }
    }
    if (pB[i]) {
      add(dp[i + 1][0][1], -dp[i - k + 1][0][0]);
      add(dp[i + 1][1][1], dp[i - k + 1][0][0]);
    }
    if (pW[i]) {
      add(dp[i + 1][1][0], -dp[i - k + 1][1][1]);
      add(dp[i + 1][2][0], dp[i - k + 1][1][1]);
    }
  }
  cout << (dp[n][2][0] + dp[n][2][1]) % mod << endl;
  return 0;
}
