#include <bits/stdc++.h>
const int z = 1005;
int sumx[z], sumy[z], cntx[z], cnty[z], ansx[z][z], ansy[z][z], x[z], y[z];
int main() {
  int n, m, i, j, cnt = 0;
  long long res = 0;
  char a;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      do a = getchar();
      while (a != '.' && a != 'X');
      if (a == 'X')
        x[i] = j, y[j] = i;
      else
        sumx[i] += i, sumy[j] += j, cntx[i]++, cnty[j]++, cnt++;
    }
  for (i = 1; i <= 1001; i++)
    sumx[i] += sumx[i - 1], sumy[i] += sumy[i - 1], cntx[i] += cntx[i - 1],
        cnty[i] += cnty[i - 1];
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (x[i] != j) {
        res += cntx[i] * i - sumx[i] + cnty[j] * j - sumy[j];
        res += sumx[m] - sumx[i] - i * (cnt - cntx[i]) + sumy[n] - sumy[j] -
               j * (cnt - cnty[j]);
        if (x[i])
          if (x[i] > j)
            ansx[i][j] = m - x[i] + (x[i - 1] > x[i] ? ansx[i - 1][j] : 0);
          else
            ansx[i][j] = x[i] - 1 + (x[i - 1] < x[i] ? ansx[i - 1][j] : 0);
        if (y[j])
          if (y[j] > i)
            ansy[i][j] = n - y[j] + (y[j - 1] > y[j] ? ansy[i][j - 1] : 0);
          else
            ansy[i][j] = y[j] - 1 + (y[j - 1] < y[j] ? ansy[i][j - 1] : 0);
        if (ansx[i][j] + ansy[i][j]) res += 2 * (ansx[i][j] + ansy[i][j]);
      }
  memset(ansx, 0, sizeof ansx), memset(ansy, 0, sizeof ansy);
  for (i = n; i; i--)
    for (j = m; j; j--)
      if (x[i] != j) {
        if (x[i]) {
          if (x[i] > j) {
            ansx[i][j] = m - x[i] + (x[i + 1] > x[i] ? ansx[i + 1][j] : 0);
            res += 2 * (x[i + 1] > x[i] ? ansx[i + 1][j] : 0);
          } else {
            ansx[i][j] = x[i] - 1 + (x[i + 1] < x[i] ? ansx[i + 1][j] : 0);
            res += 2 * (x[i + 1] < x[i] ? ansx[i + 1][j] : 0);
          }
        }
        if (y[j])
          if (y[j] > i) {
            ansy[i][j] = n - y[j] + (y[j + 1] > y[j] ? ansy[i][j + 1] : 0);
            res += 2 * (y[j + 1] > y[j] ? ansy[i][j + 1] : 0);
          } else {
            ansy[i][j] = y[j] - 1 + (y[j + 1] < y[j] ? ansy[i][j + 1] : 0);
            res += 2 * (y[j + 1] < y[j] ? ansy[i][j + 1] : 0);
          }
      }
  printf("%.8lf\n", res / double(cnt) / cnt);
  return 0;
}
