#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 5;
char s[MAXN], tmp[MAXN];
double f[MAXN][2];
int init() {
  scanf("%s", tmp + 1);
  int len = strlen(tmp + 1), n = 0;
  if (tmp[1] == tmp[len] && tmp[1] == 'R') s[++n] = 'X';
  for (int i = 1; i <= len; i++) {
    if (s[n] != 'X' && tmp[i] == s[n]) s[++n] = 'X';
    s[++n] = tmp[i];
  }
  return n;
}
int main() {
  int n = init();
  double l = 0, r = 1;
  while (l + 1e-12 < r) {
    double mid = (l + r) / 2;
    f[0][0] = -mid, f[0][1] = 0;
    for (int i = 1; i <= n; i++) {
      f[i][0] = f[i - 1][1] + (int)(s[i] == 'L') - mid;
      f[i][1] = f[i - 1][0] + (int)(s[i] == 'R') - mid;
      double tmp1 = f[i][0], tmp2 = f[i][1];
      f[i][0] = max(f[i][0], tmp2 - mid);
      f[i][1] = max(f[i][1], tmp1 - mid);
    }
    f[n][1] > -1e-12 ? l = mid : r = mid;
  }
  l += 1e-12;
  printf("%d.%06d\n", (int)(l * 100), (int)(l * 100000000) % 1000000);
  return 0;
}
