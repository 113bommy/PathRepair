#include <bits/stdc++.h>
using namespace std;
int a[109][109], m, n;
bool qb(int e) {
  int i, j, k, f = 0;
  for (i = 0, k = e - 1; i < e / 2; i++, k--) {
    for (j = 0; j < n; j++) {
      if (a[i][j] != a[k][j]) {
        f = 1;
        break;
      }
    }
    if (f) break;
  }
  if (i == e / 2) return true;
  return false;
}
int main() {
  int i, j;
  while (~scanf("%d%d", &m, &n)) {
    if (m % 2) {
      for (i = 0; i < m; i++)
        for (j = 0; j < n; j++) {
          scanf("%d", &a[i][j]);
        }
      printf("%d\n", m);
    } else {
      for (i = 0; i < m; i++)
        for (j = 0; j < n; j++) {
          scanf("%d", &a[i][j]);
        }
      int x = m;
      while (qb(x)) {
        x /= 2;
        if (x % 2) break;
      }
      printf("%d\n", x);
    }
  }
  return 0;
}
