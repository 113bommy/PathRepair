#include <bits/stdc++.h>
using namespace std;
int a[110], b[110], n, m, i, j;
void make_square(int v[], int x) {
  int nr = 0;
  if (x == 2)
    v[++nr] = 3, v[++nr] = 4;
  else if (x % 2 == 0) {
    int x1 = x / 2 - 1;
    v[++nr] = x1;
    for (int i = 1; i <= x - 1; ++i) v[++nr] = 1;
  } else if (n == 1)
    v[++nr] = 1;
  else {
    int x1 = (x + 1) / 2;
    v[++nr] = x1;
    v[++nr] = 2;
    for (int i = 1; i <= n - 2; ++i) v[++nr] = 1;
  }
}
int main() {
  scanf("%d %d", &n, &m);
  make_square(a, n);
  make_square(b, m);
  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= m; ++j) printf("%d ", a[i] * b[j]);
    printf("\n");
  }
  return 0;
}
