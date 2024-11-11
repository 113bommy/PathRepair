#include <bits/stdc++.h>
using namespace std;
int n, m, a[100], b[100];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) a[i] = 2;
  a[0] = n * 2, a[n - 1] = 3;
  for (int i = 0; i < m; i++) b[i] = 2;
  b[0] = m * 2, b[m - 1] = 3;
  for (int i = 0; i < n; i++) {
    printf("%d", a[i] * b[0]);
    for (int j = 1; j < m; j++) printf(" %d", a[i] * b[j]);
    printf("\n");
  }
  getchar();
  getchar();
  return 0;
}
