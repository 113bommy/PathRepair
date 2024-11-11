#include <bits/stdc++.h>
using namespace std;
int s[40][40], a[40][40], ans, sum, n, m, f[2];
inline int Work() {
  int sum = 0;
  for (int i = m + 1; i <= n; i++) s[i][m] = s[m][m] ^ s[i - m][m];
  for (int i = 1; i <= n; i++) sum += f[s[i][m]] * a[i][m];
  for (int i = 1; i < m; i++) {
    int maxn = -1e8;
    for (int j = 0; j < 2; j++) {
      int num = 0;
      s[m][i] = j, s[m][i + m] = j ^ s[m][m];
      num = f[s[m][i]] * a[m][i] + f[s[m][i + m]] * a[m][i + m];
      int del = 0;
      for (int k = 1; k < m; k++) {
        int Max = -1e8;
        for (int l = 0; l < 2; l++) {
          s[k][i] = l;
          s[k][i + m] = l ^ s[k][m];
          s[k + m][i] = s[k][i] ^ s[m][i],
                s[k + m][i + m] = s[k][i + m] ^ s[m][i + m];
          int now = f[s[k][i]] * a[k][i] + f[s[k][i + m]] * a[k][i + m];
          now += f[s[k + m][i]] * a[k + m][i] +
                 f[s[k + m][i + m]] * a[k + m][i + m];
          Max = max(Max, now);
        }
        del += Max;
      }
      maxn = max(maxn, num + del);
    }
    sum += maxn;
  }
  memset(s, 0, sizeof(s));
  return (sum);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
  m = (n + 1) / 2;
  f[0] = 1, f[1] = -1;
  for (int i = 1; i < (1 << m); i++) {
    for (int j = 1; j <= m; j++) s[j][m] = i >> (j - 1) & 1;
    ans = max(ans, Work());
  }
  printf("%d\n", ans);
}
