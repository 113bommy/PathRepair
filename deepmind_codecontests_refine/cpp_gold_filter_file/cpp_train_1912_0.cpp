#include <bits/stdc++.h>
using namespace std;
int t[110][20100], odl[110][20200];
int infi = 10000000;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int licz = infi;
    for (int j = 1; j <= 2 * m; j++) {
      if (j <= m) {
        char a[2];
        scanf("%1s", a);
        t[i][j] = a[0];
        t[i][j + m] = t[i][j];
      }
      if (t[i][j] == '1') {
        licz = 0;
      } else
        licz++;
      odl[i][j] = licz;
    }
  }
  for (int i = 1; i <= n; i++) {
    int licz = infi;
    for (int j = 2 * m; j > 0; j--) {
      if (t[i][j] == '1')
        licz = 0;
      else
        licz++;
      odl[i][j] = min(odl[i][j], licz);
    }
  }
  int wyn = infi;
  for (int j = 1; j <= 2 * m; j++) {
    int su = 0;
    for (int i = 1; i <= n; i++) su += odl[i][j];
    if (su < wyn) wyn = su;
  }
  if (wyn >= infi)
    printf("-1\n");
  else
    printf("%d\n", wyn);
}
