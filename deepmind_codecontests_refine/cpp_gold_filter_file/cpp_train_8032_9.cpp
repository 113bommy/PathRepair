#include <bits/stdc++.h>
using namespace std;
int n, m, d;
char a[502][502];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j], d += (a[i][j] == '*');
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '.') continue;
      int x, y, z, t;
      x = y = z = t = 0;
      for (int k = i - 1; k >= 1; k--)
        if (a[k][j] == '.')
          break;
        else
          x++;
      for (int k = i + 1; k <= n; k++)
        if (a[k][j] == '.')
          break;
        else
          y++;
      for (int k = j - 1; k >= 1; k--)
        if (a[i][k] == '.')
          break;
        else
          z++;
      for (int k = j + 1; k <= m; k++)
        if (a[i][k] == '.')
          break;
        else
          t++;
      if (x + y + z + t == d - 1 && x > 0 && y > 0 && z > 0 && t > 0) {
        printf("YES");
        return 0;
      }
    }
  printf("NO");
  return 0;
}
