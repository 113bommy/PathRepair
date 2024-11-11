#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
int r, n, x[maxn], y[maxn], g[4][maxn], G, cnt = 1, mark[4][maxn], sar = -1,
                                           js = -1, occ[maxn][2], a[maxn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> r >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
    occ[x[i]][y[i]] = occ[x[i]][1 - y[i]] = 1;
    if (x[i] > 0) occ[x[i] - 1][1 - y[i]] = 1;
    if (x[i] < r - 1) occ[x[i] + 1][1 - y[i]] = 1;
  }
  occ[r][0] = occ[r][1] = 1;
  for (int i = 0; i <= r; i++) a[i] = 3 - occ[i][0] * 2 - occ[i][1];
  for (int i = 1; i < 200; i++) {
    for (int j = 0; j < i; j++) {
      mark[0][g[0][j] ^ g[0][i - j - 1]] = cnt;
      if (j > 0 && j < i - 1) mark[0][g[1][j - 1] ^ g[1][i - j - 2]] = cnt;
    }
    while (mark[0][g[0][i]] == cnt) g[0][i]++;
    for (int j = 0; j < i; j++) mark[1][g[1][j] ^ g[0][i - j - 1]] = cnt;
    while (mark[1][g[1][i]] == cnt) g[1][i]++;
    for (int j = 0; j < i; j++) {
      mark[2][g[2][j] ^ g[0][i - j - 1]] = cnt;
      if (j < i - 1) mark[2][g[2][j] ^ g[1][i - j - 2]] = cnt;
    }
    while (mark[2][g[2][i]] == cnt) g[2][i]++;
    for (int j = 0; j < i; j++) mark[3][g[2][j] ^ g[2][i - j - 1]] = cnt;
    while (mark[3][g[3][i]] == cnt) g[3][i]++;
    cnt++;
  }
  for (int i = 0; i <= r; i++) {
    if (a[i] > 0 && (i == 0 || a[i - 1] == 0)) {
      sar = a[i];
      js = i;
    }
    if (a[i] == 0 && i > 0 && a[i - 1] > 0) {
      if ((sar == 1 && a[i - 1] == 1) || (sar == 2 && a[i - 1] == 2)) {
        G ^= g[0][i - js];
      }
      if ((sar == 1 && a[i - 1] == 2) || (sar == 2 && a[i - 1] == 1)) {
        G ^= g[1][i - js - 1];
      }
      if ((sar == 3 && (a[i - 1] == 1 || a[i - 1] == 2)) ||
          (a[i - 1] == 3 && (sar == 2 || sar == 1))) {
        G ^= g[2][i - js];
      }
      if (sar == 3 && a[i - 1] == 3) {
        G ^= g[3][i - js];
      }
      sar = js = -1;
    }
  }
  if (G > 0)
    cout << "WIN";
  else
    cout << "LOSE";
  return 0;
}
