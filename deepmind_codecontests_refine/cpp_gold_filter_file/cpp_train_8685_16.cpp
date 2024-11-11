#include <bits/stdc++.h>
using namespace std;
int n, m, a[200], b[200];
int main() {
  scanf("%d%d", &n, &m);
  if (n == 1)
    a[1] = 1;
  else if (n == 2)
    a[1] = 3, a[2] = 4;
  else {
    a[1] = 1 + (n & 1);
    for (int i = 2; i <= n - 1; i++) a[i] = 1;
    if (n & 1)
      a[n] = n / 2 + 1;
    else
      a[n] = n / 2 - 1;
  }
  if (m == 1)
    b[1] = 1;
  else if (m == 2)
    b[1] = 3, b[2] = 4;
  else {
    b[1] = 1 + (m & 1);
    for (int i = 2; i <= m - 1; i++) b[i] = 1;
    if (m & 1)
      b[m] = m / 2 + 1;
    else
      b[m] = m / 2 - 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m - 1; j++) printf("%d ", a[i] * b[j]);
    printf("%d\n", a[i] * b[m]);
  }
  return 0;
}
