#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
int a[MAXN], b[MAXN];
void make(int *x, int y) {
  if (y == 1)
    x[1] = 1;
  else if (y == 2)
    x[1] = 3, x[2] = 4;
  else {
    x[1] = y - 2;
    for (int i = 2; i <= y; i++) x[i] = 2;
  }
}
int main(int argc, char *argv[]) {
  int n, m;
  scanf("%d%d", &n, &m);
  make(a, n);
  make(b, m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d ", a[i] * b[j]);
    printf("\n");
  }
  return EXIT_SUCCESS;
}
