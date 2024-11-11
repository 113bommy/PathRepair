#include <bits/stdc++.h>
using namespace std;
const int N = 18, M = 1 << 17;
int f[N][M][2][2];
int arr[M];
bool st[M];
int n, k;
int init() {
  memset(f, -0x3f, sizeof f);
  for (int i = 0; i < k; i++) st[arr[i] - 1] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (1 << n); j += (1 << i)) {
      if (i == 1) {
        f[i][j][0][0] = (st[j] + st[j + 1] == 0) ? 0 : -0x3f3f3f3f;
        f[i][j][0][1] = (st[j] + st[j + 1] == 1) ? 1 : -0x3f3f3f3f;
        f[i][j][1][0] = (st[j] + st[j + 1] == 1) ? 1 : -0x3f3f3f3f;
        f[i][j][1][1] = (st[j] + st[j + 1] == 2) ? 1 : -0x3f3f3f3f;
        continue;
      }
      for (int x1 = 0; x1 < 2; x1++) {
        for (int x2 = 0; x2 < 2; x2++) {
          for (int y1 = 0; y1 < 2; y1++) {
            for (int y2 = 0; y2 < 2; y2++) {
              int cost =
                  f[i - 1][j][x1][y1] + f[i - 1][j + (1 << i - 1)][x2][y2];
              if (x1 || x2) cost++;
              if (y1 || y2) cost++;
              f[i][j][x1][x2] = max(f[i][j][x1][x2], cost + (x2 | y1));
              f[i][j][x1][x2] = max(f[i][j][x1][x2], cost + (x2 | y2));
              f[i][j][x1][y1] = max(f[i][j][x1][y1], cost + (x2 | y1));
              f[i][j][x1][y2] = max(f[i][j][x1][y2], cost + (x2 | y2));
              f[i][j][x2][x1] = max(f[i][j][x2][x1], cost + (x1 | y1));
              f[i][j][x2][x1] = max(f[i][j][x2][x1], cost + (x1 | y2));
              f[i][j][x2][y1] = max(f[i][j][x2][y1], cost + (x1 | y1));
              f[i][j][x2][y2] = max(f[i][j][x2][y1], cost + (x1 | y2));
            }
          }
        }
      }
    }
  }
  int ans = 0;
  ;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ans = max(ans, f[n][0][i][j] + (i | j));
    }
  }
  return ans;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    cin >> arr[i];
  }
  cout << init();
}
