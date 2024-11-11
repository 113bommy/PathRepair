#include <bits/stdc++.h>
using namespace std;
int d[2005][2050][2], a[2005];
int main() {
  int n, k, i, j, b, f;
  cin >> n >> k;
  for (i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  if (a[1] == 2) {
    d[1][1 << 0][0] = 1;
  } else if (a[1] == 4) {
    d[1][1 << 1][0] = 1;
  } else {
    d[1][1 << 0][0] = 1;
    d[1][1 << 1][0] = 1;
  }
  int ans = 0;
  for (i = 2; i <= n; ++i) {
    for (j = 1; j < (1 << k); ++j) {
      for (f = 0; f < 2; ++f) {
        if (a[i] == 4 || a[i] == 0) {
          if (j & 1) {
            d[i][1 << 1][f] += d[i - 1][j][f];
            d[i][1 << 1][f] %= 1000000007;
          } else {
            int mask = j;
            for (b = 1; b < 15; ++b) {
              if ((j & (1 << b))) {
                mask -= (1 << b);
              } else {
                mask += (1 << b);
                break;
              }
            }
            mask = min(mask, (1 << k) - 1);
            if (mask >= (1 << (k - 1))) {
              d[i][mask][1] += d[i - 1][j][f];
              d[i][mask][1] %= 1000000007;
            } else {
              d[i][mask][f] += d[i - 1][j][f];
              d[i][mask][f] %= 1000000007;
            }
          }
        }
        if (a[i] == 2 || a[i] == 0) {
          int mask = j;
          for (b = 0; b < 15; ++b) {
            if ((j & (1 << b))) {
              mask -= (1 << b);
            } else {
              mask += (1 << b);
              break;
            }
          }
          mask = min(mask, (1 << k) - 1);
          if (mask >= (1 << (k - 1))) {
            d[i][mask][1] += d[i - 1][j][f];
            d[i][mask][1] %= 1000000007;
          } else {
            d[i][mask][f] += d[i - 1][j][f];
            d[i][mask][f] %= 1000000007;
          }
        }
      }
    }
  }
  for (i = 0; i < (1 << k); ++i) {
    ans += d[n][i][1];
    ans %= 1000000007;
  }
  cout << ans;
  return 0;
}
