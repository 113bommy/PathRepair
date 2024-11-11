#include <bits/stdc++.h>
int n, m, k;
bool row[1111][1111];
bool col[1111][1111];
char buf[1111];
int ans[1111][1111];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  int tot = 0;
  for (int i = 0; i < n * 2 - 1; ++i) {
    scanf("%s", buf);
    if (i & 1) {
      for (int j = 0; j < m; ++j) col[i >> 1][j] = (buf[j] == 'E');
      tot += m;
    } else {
      for (int j = 0; j < m - 1; ++j) row[i >> 1][j] = (buf[j] == 'E');
      tot += m - 1;
    }
  }
  if (k == 1) {
    int sum = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m - 1; ++j) sum += row[i][j];
    for (int i = 0; i < n - 1; ++i)
      for (int j = 0; j < m; ++j) sum += col[i][j];
    if (sum * 4 >= tot * 3) {
      puts("YES");
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (j) putchar(' ');
          printf("1");
        }
        puts("");
      }
    } else {
      puts("NO");
    }
  } else {
    puts("YES");
    if (m > n) {
      for (int i = 0; i < n; ++i) {
        ans[i][0] = 0;
        for (int j = 0; j < m - 1; ++j)
          ans[i][j + 1] = ans[i][j] ^ row[i][j] ^ 1;
      }
      for (int i = 0; i < n - 1; ++i) {
        int cnt = 0;
        for (int j = 0; j < m; ++j)
          cnt += ans[i][j] ^ ans[i + 1][j] ^ col[i][j];
        if (cnt < m - cnt) {
          for (int j = 0; j < m; ++j) ans[i + 1][j] ^= 1;
        }
      }
    } else {
      for (int j = 0; j < m; ++j) {
        ans[0][j] = 0;
        for (int i = 0; i < n - 1; ++i)
          ans[i + 1][j] = ans[i][j] ^ col[i][j] ^ 1;
      }
      for (int j = 0; j < m - 1; ++j) {
        int cnt = 0;
        for (int i = 0; i < n; ++i)
          cnt += ans[i][j] ^ ans[i][j + 1] ^ row[i][j];
        if (cnt < n - cnt) {
          for (int i = 0; i < n; ++i) ans[i][j + 1] ^= 1;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (j) putchar(' ');
        printf("%d", ans[i][j] + 1);
      }
      puts("");
    }
  }
  return 0;
}
