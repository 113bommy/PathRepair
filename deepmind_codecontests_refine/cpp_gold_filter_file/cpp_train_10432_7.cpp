#include <bits/stdc++.h>
const int N = 2005;
char g[N][N];
int s1[N], h1[N], s2[N], h2[N];
int main() {
  int n, i, j, k, t;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", g[i]);
  }
  int cnt = 0;
  for (k = n - 1; k > 0; k--) {
    for (i = 1; i <= n; i++) {
      j = k + i;
      if (j > n) break;
      t = ((g[i - 1][j - 1] - '0') + s1[i] + h1[j]) % 2;
      if (t) {
        cnt++;
        s1[i] = 1 - s1[i];
        h1[j] = 1 - h1[j];
      }
    }
  }
  for (k = n - 1; k > 0; k--) {
    for (j = 1; j <= n; j++) {
      i = k + j;
      if (i > n) break;
      t = ((g[i - 1][j - 1] - '0') + s2[i] + h2[j]) % 2;
      if (t) {
        cnt++;
        s2[i] = 1 - s2[i];
        h2[j] = 1 - h2[j];
      }
    }
  }
  for (i = 1; i <= n; i++) {
    j = i;
    t = ((g[i - 1][j - 1] - '0') + s1[i] + h1[j] + s2[i] + h2[j]) % 2;
    if (t) {
      cnt++;
    }
  }
  printf("%d\n", cnt);
  return 0;
}
