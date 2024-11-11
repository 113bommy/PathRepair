#include <bits/stdc++.h>
using namespace std;
int a[1001][1001];
int b[1001];
int main() {
  int n, m, c, i, j, count;
  scanf("%d", &n);
  memset(b, 0, sizeof(b));
  count = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
      if (i == j && a[i][j] == 1) {
        b[i] = 1;
        count++;
      }
    }
  }
  scanf("%d", &m);
  for (i = 0; i < m; i++) {
    scanf("%d", &c);
    if (c == 3) {
      printf("%d\n", count % 2);
    } else if (c == 1) {
      scanf("%d", &c);
      if (b[c] == 1) {
        count--;
        b[c] = 0;
      } else {
        count++;
        b[c] = 1;
      }
    } else if (c == 2) {
      scanf("%d", &c);
      if (b[c] == 1) {
        count--;
        b[c] = 0;
      } else {
        count++;
        b[c] = 1;
      }
    }
  }
  return 0;
}
