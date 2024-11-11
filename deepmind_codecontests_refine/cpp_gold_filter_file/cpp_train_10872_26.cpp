#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N], b[N];
void gao(int n, int *a) {
  if (n == 1)
    a[0] = 1;
  else if (n == 2) {
    a[0] = 3;
    a[1] = 4;
  } else {
    if (n & 1) {
      for (int i = 0; i < n - 2; ++i) a[i] = 1;
      a[n - 2] = 2;
      a[n - 1] = (n >> 1) + 1;
    } else {
      for (int i = 0; i < n - 1; ++i) a[i] = 1;
      a[n - 1] = (n >> 1) - 1;
    }
  }
}
int main() {
  int n, m;
  scanf("%d%d", &m, &n);
  gao(m, a);
  gao(n, b);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) printf("%d ", a[i] * b[j]);
    printf("\n");
  }
  return 0;
}
