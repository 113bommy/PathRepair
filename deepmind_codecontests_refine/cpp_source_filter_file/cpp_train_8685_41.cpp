#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], b[110];
void getans(int n, int a[110]) {
  if (n == 1)
    a[1] = 1;
  else if (n == 2)
    a[1] = 3, a[2] = 4;
  else if (n % 2) {
    a[1] = 2;
    for (int i = 2; i < n; i++) a[i] = 1;
    a[n] = (n - 1) / 2;
  } else {
    for (int i = 1; i < n; i++) a[i] = 1;
    a[n] = (n - 2) / 2;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  getans(n, a);
  getans(m, b);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d ", a[i] * b[j]);
    printf("\n");
  }
  return 0;
}
