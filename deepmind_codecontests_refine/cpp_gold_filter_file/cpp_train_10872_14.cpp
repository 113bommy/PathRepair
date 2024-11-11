#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int gi() {
  int w = 0;
  bool q = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') q = 0, c = getchar();
  while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
  return q ? w : -w;
}
int a[N], b[N];
int main() {
  int n = gi(), m = gi(), i, j;
  if (n == 1)
    a[1] = 1;
  else if (n == 2)
    a[1] = 3, a[2] = 4;
  else {
    for (i = 1; i < n; i++) a[i] = 2;
    a[n] = n - 2;
  }
  if (m == 1)
    b[1] = 1;
  else if (m == 2)
    b[1] = 3, b[2] = 4;
  else {
    for (i = 1; i < m; i++) b[i] = 2;
    b[m] = m - 2;
  }
  for (i = 1; i <= n; i++, putchar(10))
    for (j = 1; j <= m; j++) printf("%d ", a[i] * b[j]);
  return 0;
}
