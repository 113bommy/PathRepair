#include <bits/stdc++.h>
using namespace std;
int a[5000 + 9];
int b[5000 + 9];
int c[20000 + 9][2];
int n, m;
int caldist(int x, int y) {
  if (y < x) {
    return n - (x - y);
  }
  return y - x;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[x]++;
    c[i][0] = x;
    c[i][1] = x;
  }
  int ans = 1000000000;
  for (int i = 1; i <= n; i++) {
    b[i] = 1000000000;
  }
  for (int i = 1; i <= m; i++) {
    b[c[i][0]] =
        min(b[c[i][0]], n * (a[c[i][0]] - 1) + caldist(c[i][0], c[i][1]));
  }
  for (int i = 1; i <= n; i++) {
    int ans = 0;
    for (int j = 1; j <= n; j++) {
      if (b[j] == 1000000000) {
        continue;
      }
      ans = max(ans, caldist(i, j) + b[j]);
    }
    printf("%d ", ans + 1);
  }
  return 0;
}
