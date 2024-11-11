#include <bits/stdc++.h>
using namespace std;
int cnt[2001], cnt2[2001];
int f2[2001][2001];
int n, m, q;
int a[2001][2001];
int sum = 0;
char str[2001];
int calc(int x, int flag) {
  if (x == 0) return 0;
  if (x == 1) return flag ^ 1;
  long long mi = 1;
  while (mi <= x) mi *= 2;
  mi /= 2;
  return mi / 2 + calc(x - mi, flag ^ 1);
}
int calc2(int x, int flag) {
  if (x == 0) return flag ^ 1;
  if (x == 1) return flag;
  if (x == 2) return flag ^ 1;
  long long mi = 1;
  while (mi < x) mi *= 2;
  mi /= 2;
  return calc2(x - mi, flag ^ 1);
}
long long calcc(int x, int y) {
  if (x == 0 || y == 0) return 0;
  int yy = y / m;
  int xx = x / n;
  int s1 = calc(yy, 0), type = calc2(yy + 1, 0);
  long long ans1 = 1LL * sum * s1 + 1LL * (yy - s1) * (n * m - sum) +
                   (type == 0 ? cnt[y % m] : n * (y % m) - cnt[y % m]);
  int s2 = calc(xx, 0), type2 = calc2(xx + 1, 0);
  long long ans2 = 1LL * ans1 * s2 + 1LL * (xx - s2) * (1LL * n * y - ans1);
  long long ans3 =
      1LL * cnt2[x % n] * (type2 ? yy - s1 : s1) +
      1LL * (type2 ? s1 : yy - s1) * (1LL * m * (x % n) - cnt2[x % n]) +
      ((type2 ^ type) == 0 ? f2[x % n][y % m]
                           : ((x % n) * (y % m) - f2[x % n][y % m]));
  return ans2 + ans3;
}
int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%s", str + 1);
    for (int j = 1; j <= m; j++) {
      a[i][j] = str[j] - '0';
      sum += a[i][j];
      cnt[j] += a[i][j];
      cnt2[i] += a[i][j];
      f2[i][j] = a[i][j];
    }
  }
  for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
  for (int i = 1; i <= n; i++) cnt2[i] += cnt2[i - 1];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      f2[i][j] = f2[i - 1][j] + f2[i][j - 1] - f2[i - 1][j - 1] + f2[i][j];
  int sx, sy, tx, ty;
  calcc(1, 1);
  while (q--) {
    scanf("%d %d %d %d", &sx, &sy, &tx, &ty);
    printf("%lld\n", calcc(tx, ty) - calcc(sx - 1, ty) - calcc(tx, sy - 1) +
                         calcc(sx - 1, sy - 1));
  }
  return 0;
}
