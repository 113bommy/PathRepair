#include <bits/stdc++.h>
using namespace std;
int xs[2000], ys[2000], xx[2000], yy[2000];
long long dis[2][2000];
int main() {
  int n, i, j;
  cin >> n;
  for (i = 0; i < 2; i++) cin >> xx[i] >> yy[i];
  for (i = 0; i < n; i++) cin >> xs[i] >> ys[i];
  for (i = 0; i < 2; i++)
    for (j = 0; j < n; j++)
      dis[i][j] = 1LL * (xx[i] - xs[j]) * (xx[i] - xs[j]) +
                  1LL * (yy[i] - ys[j]) * (yy[i] - ys[j]);
  long long ans = LLONG_MAX;
  for (j = 0; j < n; j++) {
    long long r1 = dis[0][j], r2 = 0;
    for (i = 0; i < n; i++)
      if (dis[0][i] > r1) r2 = max(r2, dis[1][i]);
    ans = min(ans, r1 + r2);
  }
  for (j = 0; j < n; j++) {
    long long r1 = dis[1][j], r2 = 0;
    for (i = 0; i < n; i++)
      if (dis[1][i] > r1) r2 = max(r2, dis[0][i]);
    ans = min(ans, r1 + r2);
  }
  cout << ans;
  return 0;
}
