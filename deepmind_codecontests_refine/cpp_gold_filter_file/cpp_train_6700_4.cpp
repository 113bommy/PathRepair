#include <bits/stdc++.h>
using namespace std;
int const nMax = 101000;
char a[110][11000];
int b[110][11000];
int c[110][2];
int d[11000];
int ans;
int n, m;
char s[135];
int main() {
  bool ok = true;
  scanf("%d%d", &n, &m);
  ans = (1 << 29);
  for (int i = (1); i < (n + 1); i++) {
    getchar();
    for (int j = (1); j < (m + 1); j++) {
      scanf("%c", &a[i][j]);
      if (a[i][j] == '1') {
        if (c[i][0] == 0) c[i][0] = j;
        c[i][1] = j;
      }
    }
    if (c[i][0] == 0) ok = false;
  }
  if (!ok) return printf("-1\n"), 0;
  for (int i = (1); i < (n + 1); i++) {
    int temp = m - c[i][1] + 1;
    for (int j = (1); j < (m + 1); j++) {
      if (a[i][j] == '1') {
        b[i][j] = 0;
        temp = 1;
      } else {
        b[i][j] = temp;
        temp++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int temp = c[i][0];
    for (int j = m; j > 0; j--) {
      if (a[i][j] == '1') {
        b[i][j] = 0;
        temp = 1;
      } else {
        if (temp < b[i][j]) b[i][j] = temp;
        temp++;
      }
      d[j] += b[i][j];
    }
  }
  for (int i = 1; i <= m; i++)
    if (d[i] < ans) ans = d[i];
  printf("%d\n", ans);
  return 0;
}
