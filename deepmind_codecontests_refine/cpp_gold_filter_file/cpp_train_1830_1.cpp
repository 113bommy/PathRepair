#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const double eps = 1e-8;
const int nm = 1000005;
int n, k, m, t;
long long res;
int a[nm];
char s[nm];
bool check1[nm], check2[nm], check3[nm], check4[nm];
void Try(int x, int y) {
  if (x == 1)
    if (check2[y])
      return;
    else
      check2[y] = true;
  if (y == 1)
    if (check1[x])
      return;
    else
      check1[x] = true;
  if (x == n)
    if (check3[y])
      return;
    else
      check3[y] = true;
  if (y == m)
    if (check4[x])
      return;
    else
      check4[x] = true;
  int delta = min(n - x, y - 1);
  Try(x + delta, y - delta);
  delta = min(x - 1, m - y);
  Try(x - delta, y + delta);
  delta = min(n - x, m - y);
  Try(x + delta, y + delta);
  delta = min(x - 1, y - 1);
  Try(x - delta, y - delta);
}
int main() {
  int i, j, x, y, z, w;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++)
    if (!check1[i]) res++, Try(i, 1);
  for (i = 2; i <= m; i++)
    if (!check2[i]) res++, Try(1, i);
  cout << res;
  return 0;
}
