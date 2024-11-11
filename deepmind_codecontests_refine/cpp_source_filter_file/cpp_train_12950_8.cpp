#include <bits/stdc++.h>
using namespace std;
int n, m, a[40][40], b[40][40], sum[2];
void Init() {
  scanf("%d", &n);
  ;
  m = n / 2 + 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &b[i][j]);
  ;
  int ans = -(int)(1e9);
  for (int num = 0; num < 1 << m; num++) {
    for (int i = 0; i < m; i++) a[i + 1][m] = (num & (1 << i));
    for (int i = 1; i <= m - 1; i++) a[m + i][m] = a[m][m] ^ a[i][m];
    int SUM = 0;
    for (int i = 1; i <= n; i++) SUM += ((a[i][m]) ? -b[i][m] : b[i][m]);
    for (int j = 1; j <= m - 1; j++) {
      for (int p = 0; p < 2; p++) {
        a[m][j] = p, a[m][m + j] = a[m][m] ^ p;
        sum[p] = ((a[m][j]) ? -b[m][j] : b[m][j]) +
                 ((a[m][m + j]) ? -b[m][m + j] : b[m][m + j]);
        for (int i = 1; i <= m - 1; i++) {
          int S =
              ((0) ? -b[i][j] : b[i][j]) +
              ((a[i][m]) ? -b[i][j + m] : b[i][j + m]) +
              ((a[m][j]) ? -b[i + m][j] : b[i + m][j]) +
              ((a[m][j] ^ a[i + m][m]) ? -b[i + m][j + m] : b[i + m][j + m]);
          sum[p] += abs(S);
        }
      }
      SUM += max(sum[0], sum[1]);
    }
    ans = max(ans, SUM);
  }
  cout << ans;
}
int main() { Init(); }
