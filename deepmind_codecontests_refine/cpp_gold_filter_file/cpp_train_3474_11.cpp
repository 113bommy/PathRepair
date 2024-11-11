#include <bits/stdc++.h>
using namespace std;
long long s[1010][1010], s1[1010][1010], s2[1010][1010];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int x;
      scanf("%d", &x);
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      s1[i][j] =
          s1[i - 1][j - 1] + s[i][j] - (i > k && j > k ? s[i - k][j - k] : 0);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= m; j++)
      s2[i][j] = s2[i - 1][j + 1] + s[i][j] -
                 (i > k && j + k <= m ? s[i - k][j + k] : 0);
  long long ans = 0;
  int x, y;
  for (int i = k; i <= n - k + 1; i++)
    for (int j = k; j <= m - k + 1; j++)
      if (s2[i + k - 1][j] + s2[i - 1][j - k] - s1[i + k - 1][j - 1] -
              s1[i - 1][j + k - 1] >=
          ans) {
        ans = s2[i + k - 1][j] + s2[i - 1][j - k] - s1[i + k - 1][j - 1] -
              s1[i - 1][j + k - 1];
        x = i;
        y = j;
      }
  printf("%d %d\n", x, y);
  return 0;
}
