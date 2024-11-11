#include <bits/stdc++.h>
int a[100009];
int b[100009];
int c[100009];
int d[100009];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (c[a[i]] == 0) sum++;
    c[a[i]]++;
  }
  b[1] = sum;
  int ti;
  for (int i = 2; i <= n; i++) {
    if (c[a[i - 1]] > 1) {
      c[a[i - 1]]--;
      b[i] = b[i - 1];
    } else if (c[a[i - 1]] == 1) {
      c[a[i] - 1] = 0;
      b[i] = b[i - 1] - 1;
    }
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &d[i]);
    printf("%d\n", b[d[i]]);
  }
  return 0;
}
