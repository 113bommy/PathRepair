#include <bits/stdc++.h>
using namespace std;
char s[1000005 * 6];
int n, m, c;
int f[1000005][22];
int a[1000005];
int st, mx;
int calc(int x) {
  int tot = m;
  for (int i = 20; i >= 0; i--) {
    if (tot >= (1 << i)) {
      x = f[x][i];
      tot -= (1 << i);
    }
  }
  return x;
}
int main() {
  scanf("%d%d%d", &n, &m, &c);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + a[i]);
    a[i + 1] = a[i] + strlen(s + a[i]);
    s[a[i + 1]++] = ' ';
  }
  int wz = 1;
  for (int i = 1; i <= n; i++) {
    while (wz <= n && a[wz + 1] - 2 - a[i] + 1 <= c) wz++;
    f[i][0] = wz;
  }
  f[n + 1][0] = n + 1;
  for (int i = 1; i <= 20; i++)
    for (int j = 1; j <= n; j++) f[j][i] = f[f[j][i - 1]][i - 1];
  for (int i = 1; i <= n; i++) {
    int nt = calc(i);
    if (nt - i > mx) {
      mx = nt - i;
      wz = i;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (wz == n + 1) break;
    int nt = f[wz][0];
    if (nt != wz) {
      for (int j = a[wz]; j <= a[nt] - 2; j++) putchar(s[j]);
      puts("");
      wz = nt;
    }
  }
  return 0;
}
