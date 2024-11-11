#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 17);
vector<pair<pair<int, int>, int>> state[3][2];
int dp[17][N][3][2];
int n, k;
bool a[N];
int getbit(int x, int i) { return (x >> i) & 1; }
void maxi(int &a, int b) {
  if (a < b) a = b;
}
int solve(int i, int mask, int cntw, int cntl) {
  int &res = dp[i][mask][cntw][cntl];
  if (res != -1) return res;
  res = 0;
  for (int a = 0; a < 3; a++)
    for (int b = 0; b < 2; b++)
      for (int c = 0; c < 3; c++)
        for (int d = 0; d < 2; d++) {
          for (auto x : state[a][b])
            for (auto y : state[c][d]) {
              int sumw = x.first.first + y.first.first;
              int suml = x.first.second | y.first.second;
              if (sumw == cntw && suml == cntl) {
                maxi(res, solve(i - 1, mask, a, b) +
                              solve(i - 1, mask | (1 << i), c, d) + x.second +
                              y.second);
              }
            }
        }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    int x;
    cin >> x;
    a[x - 1] = true;
  }
  memset(dp, -1, sizeof(dp));
  for (int mask = 0; mask < (1 << n); mask++)
    for (int cntw = 0; cntw < 3; cntw++)
      for (int cntl = 0; cntl < 2; cntl++) dp[1][mask][cntw][cntl] = -1e9;
  for (int i = 0; i < (1 << n); i += 4) {
    int val = (a[i] | a[i + 1]) + (a[i + 2] | a[i + 3]);
    for (int mask = 0; mask < (1 << 2); mask++) {
      int cntw = 0;
      bool cntl = 0;
      for (int j = 0; j < 2; j++) {
        if (getbit(mask, j)) {
          cntw += a[i + (j << 1)];
          cntl |= a[i + (j << 1 | 1)];
        } else {
          cntw += a[i + (j << 1 | 1)];
          cntl |= a[i + (j << 1)];
        }
      }
      dp[1][i][cntw][cntl] = val;
    }
  }
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++) {
      if (i == 0 || i == 2) {
        int a = (i > 0);
        int b = j || (i > 0);
        int val = (j << 1);
        if (i > 0) {
          val++;
          val += (j == 0);
        }
        state[i][j].push_back(make_pair(make_pair(a, b), val));
      } else {
        int val, a, b;
        val = (j << 1) + 1;
        a = 1;
        b = j;
        state[i][j].push_back(make_pair(make_pair(a, b), val));
        val = j + 2;
        a = 0;
        b = 1;
        state[i][j].push_back(make_pair(make_pair(a, b), val));
      }
    }
  int ans = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++)
      for (auto pir : state[i][j])
        ans = max(ans, solve(n - 1, 0, i, j) + pir.second +
                           (pir.first.first || pir.first.second));
  cout << ans;
  return 0;
}
