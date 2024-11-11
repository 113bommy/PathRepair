#include <bits/stdc++.h>
using namespace std;
long long maxinf = 1000000000000000000LL;
int og[1000000];
long long a[2000], b[2000], c[2000], mx[2000], mcount[2000];
long long d[1020][1020];
int n, m, x, y;
void go(int x) {
  long long a[2000];
  int yk1, yk2, i;
  for (i = 1; i <= n; ++i) a[i] = maxinf;
  a[x] = 0;
  yk1 = 1;
  yk2 = 0;
  og[yk1] = x;
  while (yk1 > yk2) {
    ++yk2;
    x = og[yk2];
    for (i = 1; i <= n; ++i)
      if (i != x && mx[x] >= d[x][i] && a[i] > a[x] + mcount[x]) {
        ++yk1;
        og[yk1] = i;
        a[i] = a[x] + mcount[x];
      }
  }
  if (a[y] == maxinf)
    cout << -1 << endl;
  else
    cout << a[y] << endl;
}
int main() {
  cin >> n >> m;
  cin >> x >> y;
  int i, j, z;
  for (i = 1; i <= m; ++i) cin >> a[i] >> b[i] >> c[i];
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j)
      if (i == j)
        d[i][j] = 0;
      else
        d[i][j] = maxinf;
  bool any;
  for (i = 1; i < m; ++i)
    for (j = i + 1; j <= m; ++j)
      if (c[i] > c[j]) {
        swap(a[i], a[j]);
        swap(b[i], b[j]);
        swap(c[i], c[j]);
      }
  for (i = 1; i <= n; ++i) cin >> mx[i] >> mcount[i];
  for (i = 1; i <= n; ++i) {
    for (;;) {
      any = false;
      for (j = 1; j <= m; ++j) {
        if (d[i][a[j]] != maxinf && d[i][a[j]] + c[j] < d[i][b[j]] &&
            mx[a[j]] >= d[i][a[j]] + c[j]) {
          d[i][b[j]] = d[i][a[j]] + c[j];
          any = true;
        }
        if (d[i][b[j]] != maxinf && d[i][b[j]] + c[j] < d[i][a[j]] &&
            mx[b[j]] >= d[i][a[j]] + c[j]) {
          d[i][a[j]] = d[i][b[j]] + c[j];
          any = true;
        }
      }
      if (!any) break;
    }
  }
  go(x);
}
