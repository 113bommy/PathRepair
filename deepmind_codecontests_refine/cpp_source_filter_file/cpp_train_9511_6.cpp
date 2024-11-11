#include <bits/stdc++.h>
using namespace std;
long long c[2010][2010];
long double C[2010][2010], f[2010][2010];
int a[2010][2010], n, m, cnt, minn, res;
bool Cmp(int a, int b) { return (a > b); }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &a[i][0]);
    for (int j = 1; j <= a[i][0]; j++) {
      scanf("%d", &a[i][j]);
      a[0][++a[0][0]] = a[i][j];
    }
    sort(a[i] + 1, a[i] + 1 + a[i][0], Cmp);
  }
  sort(a[0] + 1, a[0] + 1 + a[0][0], Cmp);
  minn = a[0][n];
  for (int i = a[0][0]; i; i--)
    if (a[0][i] == minn) cnt++, res = n - i + 1;
  C[0][0] = 1.;
  for (int i = 1; i <= a[0][0]; i++) {
    C[i][0] = 1.;
    for (int j = 1; j <= i; j++) C[i][j] = C[i - 1][j] + C[i][j - 1];
  }
  f[0][0] = 1.;
  for (int i = 1; i <= m; i++) {
    int bg = 1, ed = 1;
    while (a[i][bg] > minn) bg++;
    bg--;
    while (a[i][ed] >= minn) ed++;
    ed--;
    for (int k = 0; k <= ed - bg; k++)
      for (int j = k; j <= res; j++)
        if (f[i - 1][j - k] > 1e-12)
          f[i][j] += f[i - 1][j - k] / C[a[i][0]][bg + k];
  }
  printf("%.12lf\n", (double)(f[m][res] / C[cnt][res]));
}
