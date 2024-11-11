#include <bits/stdc++.h>
using namespace std;
int a[105][105], tot, n = 2, k;
inline int Read() {
  int t = 0;
  char c = getchar();
  for (; c > 57 || c < 48; c = getchar())
    ;
  for (; c > 47 && c < 58; c = getchar()) t = (t << 1) + (t << 3) + c - 48;
  return t;
}
int main() {
  k = Read();
  for (; tot < k; n++) {
    for (int i = 1; i < n && tot + i - 1 <= k; i++)
      a[n][i] = a[i][n] = 1, tot += i - 1;
  }
  printf("%d\n", n - 1);
  for (int i = 1; i <= n; i++, printf("\n"))
    for (int j = 1; j <= n; j++) printf("%d", a[i][j]);
}
