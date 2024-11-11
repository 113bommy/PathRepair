#include <bits/stdc++.h>
using namespace std;
int ABS(int a) {
  if (a < 0) return (-a);
  return a;
}
void input() {}
int n, table;
int a[55];
double dp[55][55][55][55];
int aim;
double f(int idx, int sum, int k, int cnt) {
  if (idx == n) {
    if (sum != aim || cnt == 0) return 0;
    return (k * cnt * 1.0) / ((double)(n)-k);
  }
  double &res = dp[idx][sum][k][cnt];
  if (res > -0.5) return res;
  double invK = (k + 1.0) / (idx + 1.0);
  double invNK = (idx - k + 1.0) / (idx + 1.0);
  res = 0.0;
  if (sum + a[idx] <= aim) {
    res += invK * f(idx + 1, sum + a[idx], k + 1, cnt);
  }
  if (aim + a[idx] > table) cnt++;
  res += invNK * f(idx + 1, sum, k, cnt);
  return res;
}
int main() {
  input();
  cin >> n;
  int sum = 0;
  for (int i = (0); i < (n); ++i) {
    cin >> a[i];
    sum += a[i];
  }
  cin >> table;
  if (sum <= table) {
    printf("%d\n", sum);
    return 0;
  }
  double ans = 0.0;
  for (int i = (1); i < (table + 1); ++i) {
    for (int I = (0); I < (55); ++I)
      for (int j = (0); j < (55); ++j)
        for (int k = (0); k < (55); ++k)
          for (int l = (0); l < (55); ++l) dp[I][j][k][l] = -1.0;
    aim = i;
    ans += f(0, 0, 0, 0);
  }
  printf("%.12lf\n", ans);
  return 0;
}
