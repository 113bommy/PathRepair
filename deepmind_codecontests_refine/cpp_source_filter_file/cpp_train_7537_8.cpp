#include <bits/stdc++.h>
using namespace std;
int v[510][510], cir[510][510], mcnt[510][510], mcir[510][510], side[510];
int part[2 * 510];
int main() {
  int n, m, r, i, j, k;
  cin >> n >> m >> r;
  memset(v, 0, sizeof(v));
  memset(cir, 0, sizeof(cir));
  memset(mcnt, 0, sizeof(mcnt));
  memset(mcir, 0, sizeof(mcir));
  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= m; ++j) {
      cin >> v[i][j];
      v[i][j] += v[i][j - 1];
    }
  }
  for (i = 0; i <= r; ++i) {
    for (j = r; j >= 0; --j) {
      if (i * i + j * j <= r * r) {
        side[i] = j;
        break;
      }
    }
  }
  for (i = 0; i <= 2 * r; ++i) {
    for (j = max(i - r, 0); j <= min(r, i); ++j) {
      part[i] = max(part[i], side[j] + side[i - j]);
    }
  }
  for (i = r + 1; i <= n - r; ++i) {
    for (j = r + 1; j <= m - r; ++j) {
      for (k = -r; k <= +r; ++k) {
        cir[i][j] +=
            v[i + k][j + side[abs(k)]] - v[i + k][j - side[abs(k)] - 1];
      }
      if (cir[i][j] > mcir[i][j - 1]) {
        mcir[i][j] = cir[i][j];
        mcnt[i][j] = 1;
      } else if (cir[i][j] == mcir[i][j - 1]) {
        mcir[i][j] = cir[i][j];
        mcnt[i][j] = mcnt[i][j - 1] + 1;
      } else {
        mcir[i][j] = mcir[i][j - 1];
        mcnt[i][j] = mcnt[i][j - 1];
      }
    }
  }
  int ans = -1;
  long long num = 0;
  for (i = r + 1; i <= n - r; ++i) {
    for (j = r + 1; j <= m - r; ++j) {
      for (k = r + 1; k <= n - r; ++k) {
        if (abs(i - k) > 2 * r) {
          if (cir[i][j] + mcir[k][m - r] > ans) {
            ans = cir[i][j] + mcir[k][m - r];
            num = mcnt[k][m - r];
          } else if (cir[i][j] + mcir[k][m - r] == ans) {
            num += mcnt[k][m - r];
          }
        } else {
          int col = j - part[abs(i - k)] - 1;
          if (col > r && cir[i][j] + mcir[k][col] > ans) {
            ans = cir[i][j] + mcir[k][col];
            num = 2 * mcnt[k][col];
          } else if (cir[i][j] + mcir[k][col] == ans) {
            num += 2 * mcnt[k][col];
          }
        }
      }
    }
  }
  cout << ans << " " << num / 2 << endl;
  return 0;
}
