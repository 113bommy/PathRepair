#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const double PI = acos(-1);
const double EPS = 1e-8;
int dp[2][32][32][32][2];
int n, h;
int f(int a) { return min(a + 1, h); }
int mod = 1e9 + 7;
void add(int &a, int b) { a = (a + b) % mod; }
int main() {
  cin >> n >> h;
  dp[0][0][0][0][1] = 1;
  for (int i = 0; i < (int)n; ++i) {
    for (int j1 = 0; j1 < (int)h + 1; ++j1)
      for (int j2 = 0; j2 < (int)h + 1; ++j2)
        for (int j3 = 0; j3 < (int)h + 1; ++j3)
          for (int alive = 0; alive < (int)2; ++alive) {
            int i1 = i & 1;
            int i2 = i & 1 ^ 1;
            int &t = dp[i1][j1][j2][j3][alive];
            int k = alive ? 1 : h;
            add(dp[i2][k][f(j2)][f(j3)][j1 < h], t);
            add(dp[i2][f(j1)][k][f(j3)][j2 < h], t);
            add(dp[i2][f(j1)][f(j2)][k][j3 < h], t);
            add(dp[i2][f(j1)][f(j2)][f(j3)][alive], t);
            t = 0;
          }
  }
  int res = 0;
  for (int j1 = 0; j1 < (int)h + 1; ++j1)
    for (int j2 = 0; j2 < (int)h + 1; ++j2)
      for (int j3 = 0; j3 < (int)h + 1; ++j3)
        for (int alive = 0; alive < (int)2; ++alive) {
          if (j1 < h || j2 < h || j3 < h || alive)
            add(res, dp[n & 1][j1][j2][j3][alive]);
        }
  cout << res << endl;
}
