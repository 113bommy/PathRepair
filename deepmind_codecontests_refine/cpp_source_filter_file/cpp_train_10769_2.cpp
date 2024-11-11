#include <bits/stdc++.h>
using namespace std;
int n, m, c, d, x[100001];
char a[100001], b[100001], cc[100001];
int main() {
  int i;
  scanf("%s%s", &a, &b);
  n = strlen(a);
  m = strlen(b);
  for (i = 0; i < n; i++) cc[i] = a[i];
  for (i = 0; i < n; i++) a[i] = cc[n - 1 - i];
  for (i = 0; i < n; i++) cc[i] = b[i];
  for (i = 0; i < m; i++) b[i] = cc[m - 1 - i];
  for (i = 0; i < n; i++) x[i] += a[i] - '0';
  for (i = 0; i < m; i++) x[i] -= b[i] - '0';
  for (i = max(n, m) - 1; i > 1; i--) {
    if (abs(x[i]) > 1) break;
    x[i - 1] += x[i];
    x[i - 2] += x[i];
  }
  if (i <= 1 && x[0] == 0 && x[1] == 0)
    printf("=");
  else if (i > 1)
    if (x[i] > 0)
      printf(">");
    else
      printf("<");
  else if (x[1] == 0)
    if (x[0] > 0)
      printf(">");
    else
      printf("<");
  else if (x[1] > 0)
    printf(">");
  else
    printf("<");
  return 0;
}
