#include <bits/stdc++.h>
using namespace std;
long long x, y, m;
long long ans = 0;
int n, nQ;
int a[70 + 4][70 + 4], d[70 + 4][70 + 4];
bool flag;
int main() {
  scanf("%d%d", &n, &nQ);
  a[1][1] = n;
  while (1) {
    flag = 0;
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= 70; i++)
      for (int j = 1; j <= 70; j++) {
        int t = a[i][j] / 4;
        d[i][j] -= t * 4;
        d[i + 1][j] += t;
        d[i - 1][j] += t;
        d[i][j + 1] += t;
        d[i][j - 1] += t;
        if (t > 0) flag = 1;
      }
    d[1][1] += a[1][2] / 4 + a[2][1] / 4;
    for (int i = 2; i <= 70; i++) {
      d[1][i] += a[2][i] / 4;
      d[i][1] += a[i][2] / 4;
    }
    for (int i = 1; i <= 70; i++)
      for (int j = 1; j <= 70; j++) a[i][j] += d[i][j];
    if (!flag) break;
  }
  while (nQ--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    if (x > 70 || y > 70)
      cout << 0 << endl;
    else
      cout << a[x + 1][y + 1] << endl;
  }
  return 0;
}
