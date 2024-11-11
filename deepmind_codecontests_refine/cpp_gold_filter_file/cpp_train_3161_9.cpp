#include <bits/stdc++.h>
using namespace std;
const int oo = 0x7fffffff;
const long long OO = 1000000000000000000LL;
const int base = 1000000009;
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, 1, -1, 0};
int n, m, x, y;
char a[1111][1111];
int s[1111][1111], f[1111][2];
int main() {
  cin >> n >> m >> x >> y;
  for (int i = 1; i <= n; ++i) scanf("%s", a[i] + 1);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (a[i][j] == '.');
  memset(f, -1, sizeof f);
  f[0][0] = 0;
  f[0][1] = 0;
  for (int i = 1; i <= m; ++i)
    for (int j = i - x; j >= i - y; --j) {
      if (j >= 0 && f[j][0] != -1) {
        int add = s[n][i] - s[n][j];
        if (f[i][1] == -1 || f[i][1] > f[j][0] + add) f[i][1] = f[j][0] + add;
      }
      if (j >= 0 && f[j][1] != -1) {
        int add = (i - j) * n - s[n][i] + s[n][j];
        if (f[i][0] == -1 || f[i][0] > f[j][1] + add) f[i][0] = f[j][1] + add;
      }
    }
  cout << min(f[m][1], f[m][0]);
  return 0;
}
