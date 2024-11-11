#include <bits/stdc++.h>
using namespace std;
long long const mod = 1000000007;
int const MAX_SIZE = 100005;
long long ans[51][51][2];
long long tmp[51][51][2];
long long c[51][51];
void init_c() {
  for (int i = 0; i <= 50; ++i) c[i][i] = c[i][0] = 1;
  for (int i = 1; i <= 50; ++i)
    for (int j = 1; j < i; ++j) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  init_c();
  int n = 0;
  int k = 0;
  cin >> n >> k;
  int count50 = 0;
  int count100 = 0;
  for (int i = 0; i < n; ++i) {
    int cur = 0;
    cin >> cur;
    if (cur == 50)
      ++count50;
    else
      ++count100;
  }
  k /= 50;
  ans[count50][count100][0] = 1;
  for (int step = 1; step <= 2 * n + 5; ++step) {
    for (int i = 0; i <= count50; ++i)
      for (int j = 0; j <= count100; ++j) {
        if ((i + j > 0) && (i + 2 * j <= k)) {
          for (int t = i; t <= count50; ++t)
            for (int y = j; y <= count100; ++y) {
              tmp[t][y][0] +=
                  (ans[t - i][y - j][1] * c[t][i] % mod) * c[y][j] % mod;
            }
          for (int t = 0; t <= count50 - i; ++t)
            for (int y = 0; y <= count100 - j; ++y) {
              tmp[t][y][1] += (ans[t + i][y + j][0] * c[count50 - t][i] % mod) *
                              c[count100 - y][j] % mod;
            }
        }
      }
    for (int i = 0; i <= count50; ++i)
      for (int j = 0; j <= count100; ++j) {
        ans[i][j][0] = tmp[i][j][0] % mod;
        ans[i][j][1] = tmp[i][j][1] % mod;
        tmp[i][j][0] = 0;
        tmp[i][j][1] = 0;
      }
    if (ans[0][0][1] > 0) {
      cout << step << endl << ans[0][0][1] << endl;
      return 0;
    }
  }
  cout << -1 << endl << 0 << endl;
  return 0;
}
