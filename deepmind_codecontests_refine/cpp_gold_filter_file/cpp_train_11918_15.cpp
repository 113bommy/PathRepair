#include <bits/stdc++.h>
using namespace std;
long long d[200005], h[200005], mx[2][200005][25], ps[2][200005][25];
int n, m;
long long tot, ret;
void RMQ() {
  for (int i = 0; i < 2; i++)
    for (int j = 1; j < 20; j++)
      for (int k = 1; k <= n; k++)
        if (k + (1 << j) - 1 <= n) {
          if (mx[i][k][j - 1] >= mx[i][k + (1 << (j - 1))][j - 1]) {
            mx[i][k][j] = mx[i][k][j - 1];
            ps[i][k][j] = ps[i][k][j - 1];
          } else {
            mx[i][k][j] = mx[i][k + (1 << (j - 1))][j - 1];
            ps[i][k][j] = ps[i][k + (1 << (j - 1))][j - 1];
          }
        }
}
long long query(int x, int y) {
  if (x > y) y += n / 2;
  int k = log(y - x + 1.0) / log(2.0);
  long long pss[2], sum[2];
  for (int i = 0; i < 2; i++) {
    if (mx[i][x][k] >= mx[i][y - (1 << k) + 1][k]) {
      pss[i] = ps[i][x][k];
      sum[i] = mx[i][x][k];
    } else {
      pss[i] = ps[i][y - (1 << k) + 1][k];
      sum[i] = mx[i][y - (1 << k) + 1][k];
    }
  }
  if (pss[0] != pss[1])
    return sum[0] + sum[1];
  else {
    long long ret1 = -1, ret2 = -1;
    if (pss[0] < y) {
      k = log(y - (pss[0] + 1) + 1.0) / log(2.0);
      ret1 = sum[1] + max(mx[0][pss[0] + 1][k], mx[0][y - (1 << k) + 1][k]);
    }
    if (pss[0] > x) {
      k = log((pss[0] - 1) - x + 1.0) / log(2.0);
      ret2 = sum[0] + max(mx[1][x][k], mx[1][pss[0] - 1 - (1 << k) + 1][k]);
    }
    return max(ret1, ret2);
  }
}
int main() {
  int i, j;
  while (cin >> n >> m) {
    ret = tot = 0;
    d[1] = 0;
    for (i = 1; i <= n; i++) {
      cin >> d[i + 1];
      d[i + 1] += d[i];
    }
    for (i = n + 2; i <= 2 * n; i++) d[i] = d[i - n] + d[n + 1];
    tot = d[2 * n];
    for (i = 1; i <= n; i++) {
      cin >> h[i];
      h[i + n] = h[i];
    }
    n *= 2;
    for (i = 1; i <= n; i++) {
      mx[0][i][0] = 2 * h[i] + d[i];
      ps[0][i][0] = i;
      mx[1][i][0] = 2 * h[i] - d[i];
      ps[1][i][0] = i;
    }
    RMQ();
    for (i = 1; i <= m; i++) {
      int a, b;
      cin >> a >> b;
      cout << query(b + 1, a - 1) << endl;
    }
  }
  return 0;
}
