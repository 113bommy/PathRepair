#include <bits/stdc++.h>
using namespace std;
int a[105], b[105], n, m;
void work(int *a, int x) {
  if (x == 1)
    a[1] = 1;
  else if (x == 2)
    a[1] = 3, a[2] = 4;
  else {
    int i;
    a[1] = x - 2;
    for (i = 2; i <= x; i++) a[i] = 2;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  work(a, n);
  work(b, m);
  int i, j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) printf("%d ", a[i] * b[j]);
    printf("\n");
  }
  return 0;
}
