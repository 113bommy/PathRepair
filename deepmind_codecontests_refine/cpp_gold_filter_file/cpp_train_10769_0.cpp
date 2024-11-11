#include <bits/stdc++.h>
using namespace std;
char str[110000];
int a[110000], n, m;
void work(int k) {
  scanf("%s", str);
  n = strlen(str);
  for (int i = 1; i <= n; i++) a[i] += k * (str[n - i] - '0');
  m = max(m, n);
}
void ff() {
  while (m && a[m] == 0) m--;
}
int main() {
  work(1);
  work(-1);
  ff();
  while (m > 2) {
    if (a[m] == 1 && (m == 1 || a[m - 1] >= 0)) {
      printf(">\n");
      return 0;
    }
    if (a[m] == -1 && (m == 1 || a[m - 1] <= 0)) {
      printf("<\n");
      return 0;
    }
    if (m - 1 >= 0) a[m - 1] += a[m];
    if (m - 2 >= 0) a[m - 2] += a[m];
    a[m] = 0;
    ff();
  }
  double s = (sqrt(5) + 1) / 2 * a[2] + a[1];
  if (s > 1e-10)
    printf(">\n");
  else if (s < -1e-10)
    printf("<\n");
  else
    printf("=\n");
  return 0;
}
