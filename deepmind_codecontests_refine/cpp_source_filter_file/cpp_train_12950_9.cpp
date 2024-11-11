#include <bits/stdc++.h>
using namespace std;
bool debug = false;
int n, m, k;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
long long ln, lk, lm;
int a[105][105], b[105][105], x;
int cal(int sta) {
  for (int(i) = 0; (i) < (int)(n); (i)++)
    for (int(j) = 0; (j) < (int)(n); (j)++) a[i][j] = b[i][j];
  for (int i = 0; i <= x; i++) {
    if ((1 << x) & sta) {
      for (int(k) = 0; (k) < (int)(x + 1); (k)++)
        for (int(j) = 0; (j) < (int)(x + 1); (j)++) {
          a[x + k][i + j] *= -1;
        }
    }
  }
  int ans = 0;
  for (int(i) = 0; (i) < (int)(n); (i)++) ans += a[x][i];
  for (int(i) = 0; (i) < (int)(x); (i)++)
    for (int(j) = 0; (j) < (int)(n); (j)++) a[i][j] += a[i + x + 1][j];
  for (int(i) = 0; (i) < (int)(x); (i)++) {
    int p = a[i][x];
    for (int(j) = 0; (j) < (int)(x); (j)++)
      p += max(a[i][j] + a[i][j + x + 1], -a[i][j] - a[i][j + x + 1]);
    int q = -a[i][x];
    for (int(j) = 0; (j) < (int)(x); (j)++)
      q += max(a[i][j] - a[i][j + x + 1], -a[i][j] + a[i][j + x + 1]);
    ans += max(p, q);
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int(i) = 0; (i) < (int)(n); (i)++)
    for (int(j) = 0; (j) < (int)(n); (j)++) scanf("%d", &b[i][j]);
  x = n / 2;
  int ans = -((1 << 30));
  for (int(sta) = 0; (sta) < (int)((1 << (x + 1))); (sta)++) {
    ans = max(ans, cal(sta));
  }
  cout << ans << endl;
  return 0;
}
