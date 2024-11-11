#include <bits/stdc++.h>
int main() {
  int n, m;
  char x[4], y[4];
  scanf("%d %d", &n, &m);
  int u = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      unsigned char ch;
      scanf("%c", &ch);
      if ((ch == 13) || (ch == 10)) {
        scanf("%c", &ch);
      }
      if (ch == char('*')) {
        x[u] = i;
        y[u] = j;
        u++;
      }
    }
  }
  if (x[0] == x[1]) {
    x[3] = x[2];
    if (y[0] == y[2]) {
      y[3] = y[1];
    } else {
      y[3] = y[2];
    }
  }
  if (x[0] == x[2]) {
    x[3] = x[1];
    if (y[0] == y[1]) {
      y[3] = y[2];
    } else {
      y[3] = y[1];
    }
  }
  if (x[1] == x[2]) {
    x[3] = x[0];
    if (y[0] == y[1]) {
      y[3] = y[2];
    } else {
      y[3] = y[1];
    }
  }
  printf("%d %d", x[3] + 1, y[3] + 1);
}
