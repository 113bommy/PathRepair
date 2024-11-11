#include <bits/stdc++.h>
using namespace std;
const int N = 1100;
char row[N][N];
char col[N][N];
int ans[N][N];
int n, m, k;
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n - 1; i++) {
    scanf("%s", row[i]);
    scanf("%s", col[i]);
  }
  scanf("%s", row[n]);
  if (k == 1) {
    int cnt = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < m - 1; j++)
        if (row[i][j] == 'E') ++cnt;
    for (int i = 1; i <= n - 1; i++)
      for (int j = 0; j < m; j++)
        if (col[i][j] == 'E') ++cnt;
    if (cnt * 4 >= ((n - 1) * m + (m - 1) * n) * 3) {
      printf("YES\n");
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) printf("%d ", 1);
        printf("\n");
      }
    } else
      printf("NO\n");
  }
  if (k > 1) {
    printf("YES\n");
    if (n >= m) {
      for (int j = 1; j <= m; j++) ans[1][j] = 0;
      for (int i = 2; i <= n; i++)
        for (int j = 1; j <= m; j++)
          ans[i][j] = ans[i - 1][j] ^ (col[i - 1][j - 1] == 'N');
      for (int j = 2; j <= m; j++) {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
          cnt += (ans[i][j] == ans[i][j - 1]) ^ (row[i][j - 2] == 'E');
        if (cnt > n / 2)
          for (int i = 1; i <= n; i++) ans[i][j] = ans[i][j] ^ 1;
      }
    } else {
      for (int i = 1; i <= n; i++) ans[i][1] = 0;
      for (int j = 2; j <= m; j++)
        for (int i = 1; i <= n; i++)
          ans[i][j] = ans[i][j - 1] ^ (row[i][j - 2] == 'N');
      for (int i = 2; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= m; j++)
          cnt += (ans[i][j] == ans[i - 1][j]) ^ (col[i - 1][j - 1] == 'E');
        if (cnt > m / 2)
          for (int j = 1; j <= m; j++) ans[i][j] = ans[i][j] ^ 1;
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) printf("%d ", ans[i][j] + 1);
      printf("\n");
    }
  }
  return 0;
}
