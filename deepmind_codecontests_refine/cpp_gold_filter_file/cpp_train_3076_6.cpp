#include <bits/stdc++.h>
using namespace std;
bool f[2][501][501], res[501];
int cnt;
int coin[501], flag;
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> coin[i];
  f[0][0][0] = f[1][0][0] = true;
  for (int t = 1; t <= n; ++t) {
    for (int i = 0; i <= k; ++i) {
      for (int j = 0; j <= k; ++j) {
        if (f[flag][i][j]) {
          if (i + coin[t] <= k) f[1 - flag][i + coin[t]][j] = true;
          if (j + coin[t] <= k) f[1 - flag][i][j + coin[t]] = true;
        }
      }
    }
    for (int i = 0; i <= k; ++i) {
      for (int j = 0; j <= k; ++j) {
        if (f[flag][i][j]) f[1 - flag][i][j] = true;
      }
    }
    flag = 1 - flag;
  }
  for (int i = 0; i <= k; ++i)
    for (int j = 0; j <= k; ++j) {
      if (f[flag][i][j] && i + j == k) {
        if (!res[i]) {
          res[i] = true;
          cnt++;
        }
      }
    }
  cout << cnt << endl;
  for (int i = 0; i <= k; ++i)
    if (res[i]) cout << i << " ";
  return 0;
}
