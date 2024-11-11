#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[1000][1000];
char a1[1000][1000];
double cnt1[2000], cnt2[2000];
bool mark[1000][1000];
int l[2000], r[2000];
int d[2000];
double ans;
double num;
int main() {
  scanf("%d%d", &n, &m);
  num = n * m;
  for (int i = 0; i < n; i++) scanf("%s", a[i]);
  for (int i = 0; i < n; i++) cnt1[i] = m;
  for (int i = 0; i < m; i++) cnt2[i] = n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (a[i][j] == 'X') {
        cnt1[i]--;
        cnt2[j]--;
        num--;
      }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      ans += cnt1[i] * cnt1[j] * ((double)max((i - j), (j - i)));
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++)
      ans += cnt2[i] * cnt2[j] * ((double)max((i - j), (j - i)));
  for (int T = 1; T <= 2; T++) {
    memset(d, 0, sizeof(d));
    memset(mark, 0, sizeof(mark));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (a[i][j] == 'X') {
          l[i] = j;
          r[i] = m - j - 1;
          mark[i][i] = true;
          d[i] = j;
        }
    for (int i = 1; i <= n; i++)
      for (int j = 0; j + i < n; j++)
        mark[j][j + i] =
            (mark[j][j + i - 1] && (d[j + i - 1] < d[j + i]) && d[j + i] != 0);
    for (int i = 0; i < n; i++)
      for (int j = i; j < n; j++)
        if (mark[i][j]) ans += 2 * 2 * l[i] * r[j];
    memset(d, 0, sizeof(d));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (a[i][j] == 'X') {
          l[i] = j;
          r[i] = m - j - 1;
          mark[i][i] = true;
          d[i] = j;
        }
    for (int i = 1; i <= n; i++)
      for (int j = 0; j + i < n; j++)
        mark[j][j + i] =
            (mark[j][j + i - 1] && (d[j + i - 1] > d[j + i]) && d[j + i] != 0);
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (mark[i][j]) ans += 2 * 2 * r[i] * l[j];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) a1[j][i] = a[i][j];
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) a[i][j] = a1[i][j];
    swap(n, m);
  }
  printf("%.12lf\n", ans / num / num);
  return 0;
}
