#include <bits/stdc++.h>
using namespace std;
int n, m;
int ans[120][120];
void out(int ts) {
  int i, j;
  if (!ts) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        printf("%d ", ans[i][j]);
      }
      puts("");
    }
    return;
  }
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", ans[j][i]);
    }
    puts("");
  }
}
int main() {
  int i, j, k, c = 0;
  scanf("%d%d", &n, &m);
  if (n * m == 1) {
    puts("1");
    return 0;
  }
  if (n > m) {
    swap(n, m);
    c = 1;
  }
  if (n == 1) {
    int now = 1;
    int pos = 0;
    while (pos < m) {
      ans[0][pos] = now;
      now += 2;
      if (now > m) now = 2;
      pos++;
    }
    if (m == 4) {
      ans[0][0] = 3;
      ans[0][1] = 1;
      ans[0][2] = 4;
      ans[0][3] = 2;
    }
    if (m < 4) {
      puts("-1");
      return 0;
    }
    out(c);
    return 0;
  }
  if (n * m <= 4) {
    puts("-1");
    return 0;
  }
  if (n == 2) {
    int now = 1;
    int pos = 0;
    for (i = 0; i < m; i++) {
      ans[0][i] = now;
      now += 2;
    }
    now = 4;
    for (i = 0; i < m - 1; i++) {
      ans[1][i] = now;
      now += 2;
    }
    ans[1][i] = 2;
    out(c);
    return 0;
  }
  int pos = 0;
  int now = 1;
  while (pos < n * m) {
    int x = pos / m;
    int y = pos % m;
    ans[x][y] = now;
    now += 2;
    pos++;
    if (now > n * m) now = 2;
  }
  out(c);
  return 0;
}
