#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
void adto(long long &a, long long b) { a = (a + b) % ((long long)(1e9 + 7)); }
long long dp[106][24][24];
long long f[24][24];
vector<long long> v[((long long)(1e5 + 900))];
long long n, m, k, p, K;
void go(long long x, long long p) {
  dp[x][0][0] = 1;
  dp[x][K + 1][1] = 1;
  for (auto y : v[x]) {
    if (y == p) continue;
    go(y, x);
    memset(f, 0, sizeof(f));
    for (int a = 0; a <= K + 2; a++)
      for (int b = 0; b <= K + 2; b++)
        for (int c = 0; c <= K + 2; c++)
          for (int d = 0; d <= K + 2; d++) {
            long long k = min(a, c + 1), p = max(b, d + 1);
            adto(f[k][p], dp[x][a][b] * dp[y][c][d]);
          }
    for (int a = 0; a <= K + 2; a++)
      for (int b = 0; b <= K + 2; b++) {
        dp[x][a][b] = f[a][b];
      }
  }
  for (int a = 0; a <= K + 2; a++)
    for (int b = 1; b <= K + 2; b++)
      if (a + b <= K + 1) {
        adto(dp[x][a][0], dp[x][a][b]);
        dp[x][a][b] = 0;
      }
}
int main() {
  cin >> n >> K;
  for (int i = 0; i < n - 1; i++) {
    cin >> k >> p;
    v[p].push_back(k);
    v[k].push_back(p);
  }
  go(1, -1);
  long long pas = 0;
  for (int i = 0; i <= K + 2; i++) adto(pas, dp[1][i][0]);
  cout << pas;
}
