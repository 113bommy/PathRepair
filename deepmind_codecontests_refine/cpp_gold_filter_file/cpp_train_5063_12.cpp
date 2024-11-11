#include <bits/stdc++.h>
using namespace std;
const int maxn = 50 + 5;
int n;
long long m;
int res[maxn];
long long tmp[maxn][2][2];
int main() {
  cin >> n >> m;
  m++;
  if (n == 2 && m > 2) {
    printf("-1\n");
    return 0;
  }
  res[1] = 0;
  tmp[1][0][1] = tmp[1][1][0] = 1;
  for (int i = 2; i <= (n + 1) / 2; i++)
    for (int j = 0; j < 2; j++) {
      res[i] = j;
      for (int k = 2; k <= (n + 1) / 2; k++)
        for (int l = 0; l < 2; l++)
          for (int ll = 0; ll < 2; ll++) tmp[k][l][ll] = 0;
      for (int k = 1; k < (n + 1) / 2; k++)
        for (int l = 0; l < 2; l++)
          for (int ll = 0; ll < 2; ll++)
            if (tmp[k][l][ll])
              for (int a = 0; a < 2; a++)
                for (int b = 0; b < 2; b++)
                  if ((a <= b || l) && ((!a | !b) || ll)) {
                    if (k + 1 <= i && a != res[k + 1]) continue;
                    if ((k + 1) * 2 > n && a != b) continue;
                    tmp[k + 1][l | (a < b)][ll | (!a & !b)] += tmp[k][l][ll];
                  }
      long long tot = 0;
      for (int a = 0; a < 2; a++)
        for (int b = 0; b < 2; b++) tot += tmp[(n + 1) / 2][a][b];
      if (tot < m && j == 1) {
        printf("-1\n");
        return 0;
      }
      if (tot < m)
        m -= tot;
      else
        break;
    }
  for (int i = (n + 1) / 2 + 1; i <= n; i++)
    for (int j = 0; j < 2; j++) {
      res[i] = j;
      for (int k = (n + 1) / 2; k <= n; k++)
        for (int l = 0; l < 2; l++)
          for (int ll = 0; ll < 2; ll++) tmp[k][l][ll] = 0;
      if (n & 1 && res[(n + 1) / 2])
        tmp[(n + 1) / 2][1][0] = 1;
      else
        tmp[(n + 1) / 2][1][1] = 1;
      for (int k = (n + 1) / 2; k < n; k++)
        for (int l = 0; l < 2; l++)
          for (int ll = 0; ll < 2; ll++)
            if (tmp[k][l][ll])
              for (int a = 0; a < 2; a++) {
                if (k + 1 <= i && a != res[k + 1]) continue;
                int _l, _ll;
                if (a < res[n - k])
                  _l = 0;
                else if (a > res[n - k])
                  _l = 1;
                else
                  _l = l;
                if (!res[n - k] & !a)
                  _ll = 1;
                else if (!res[n - k] | !a)
                  _ll = ll;
                else
                  _ll = 0;
                tmp[k + 1][_l][_ll] += tmp[k][l][ll];
              }
      if (tmp[n][1][1] < m)
        m -= tmp[n][1][1];
      else
        break;
    }
  for (int i = 1; i <= n; i++) printf("%d", res[i]);
  printf("\n");
}
