#include <bits/stdc++.h>
using namespace std;
const int Max_N = 1e3;
int n, a[Max_N + 5], f[Max_N + 5][Max_N + 5], g[Max_N + 5][Max_N + 5];
inline void Print(int x, int y) {
  if (!g[x][y]) return;
  Print(x - 2, g[x][y]);
  if (x == y)
    printf("%d %d\n", g[x][y], x - 1);
  else if (x == y + 1)
    printf("%d %d\n", g[x][y], x);
  else
    printf("%d %d\n", x - 1, x);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  if (n == 1)
    printf("%d\n", a[1]), puts("1");
  else if (n == 2)
    printf("%d\n", max(a[1], a[2])), puts("1 2");
  else {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= i; j++) f[i][j] = 1 << 30;
    f[3][1] = max(a[2], a[3]);
    g[3][1] = 0;
    f[3][2] = max(a[1], a[3]);
    g[3][2] = 1;
    f[3][3] = max(a[1], a[2]);
    g[3][3] = 1;
    int Max = 3;
    for (int i = 5; i <= n; i += 2) {
      for (int j = 1; j <= i - 2; j++) {
        if (f[i - 2][j] + max(a[j], a[i - 1]) < f[i][i])
          f[i][i] = f[i - 2][j] + max(a[j], a[i - 1]), g[i][i] = j;
        if (f[i - 2][j] + max(a[j], a[i]) < f[i][i - 1])
          f[i][i - 1] = f[i - 2][j] + max(a[j], a[i]), g[i][i - 1] = j;
        if (f[i - 2][j] + max(a[i - 1], a[i]) < f[i][j])
          f[i][j] = f[i - 2][j] + max(a[i - 1], a[i]), g[i][j] = j;
      }
      Max = i;
    }
    int ans = 1 << 30;
    for (int i = 1; i <= Max; i++)
      ans = min(ans, f[Max][i] + max(a[i], a[Max + 1]));
    printf("%d\n", ans);
    for (int i = 1; i <= Max; i++)
      if (f[Max][i] + max(a[i], a[Max + 1]) == ans) {
        Print(Max, i);
        if (Max + 1 <= n)
          printf("%d %d\n", i, Max + 1);
        else
          printf("%d\n", i);
        break;
      }
  }
  return 0;
}
