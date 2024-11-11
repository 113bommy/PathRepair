#include <bits/stdc++.h>
using namespace std;
const int N = 35;
const int K = 205;
int a[N];
int n, k;
int tmp = 0;
long double dp[N][N][K];
void pre() {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      dp[i][j][0] = 1;
    }
  }
}
void solver(int m) {
  for (int l = 0; l < n; l++) {
    for (int r = l; r < n; r++) {
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          int x, y;
          if (i < l || i > r) {
            x = i;
          } else {
            x = r - i + l;
          }
          if (j < l || j > r) {
            y = j;
          } else {
            y = r - j + l;
          }
          if (x < y) {
            dp[i][j][m] += dp[x][y][m - 1] / tmp;
          } else {
            swap(x, y);
            dp[i][j][m] += (1 - dp[x][y][m - 1]) / tmp;
          }
        }
      }
    }
  }
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  pre();
  tmp = (n * (n + 1));
  tmp = tmp / 2;
  for (int i = 1; i <= k; i++) {
    solver(i);
  }
  double ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] > a[j]) {
        ans += dp[i][j][k];
      } else {
        ans += 1 - dp[i][j][k];
      }
    }
  }
  cout << setprecision(20) << fixed << ans << endl;
}
