#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, num = 0, i, j, a[10];
  scanf("%d", &n);
  for (i = 0; i < n * n; i++) {
    scanf("%d", &a[i]);
    num += a[i];
  }
  sort(a, a + n * n);
  num /= n;
  do {
    int r[4] = {0}, c[4] = {0}, d1 = 0, d2 = 0;
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        r[i] += a[i * n + j];
        c[j] += a[i * n + j];
      }
      d1 += a[i * n + i];
      d2 += a[i * n + n - i - 1];
    }
    bool mark = true;
    for (i = 0; i < n; i++)
      if (r[i] != num || c[i] != num) mark = false;
    if (d1 != num || d1 != num) mark = false;
    if (mark == false) continue;
    printf("%d\n", num);
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
        printf("%d%c", a[i * n + j], j == n - 1 ? '\n' : ' ');
    return 0;
  } while (next_permutation(a, a + n * n));
}
