#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n, i, j, k = 0, l = 0, m = 0;
  int a[129], b[129], c[129], d[129];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  for (i = 0; i < n; i++) {
    if (a[i] == a[i + 1]) {
      b[k++] = a[i];
      i++;
    } else if (a[i] != a[i + 1])
      c[l++] = a[i];
  }
  if (l == 0)
    printf("%d %d\n", b[k - 1], b[k - 1]);
  else {
    int gcd = 1;
    for (i = k - 1; i > 0; i--) {
      if (gcd % b[i] != 0) gcd *= b[i];
    }
    for (i = 0; i < l; i++) {
      if (c[i] % gcd == 0) d[m++] = c[i];
    }
    if (m >= 2) {
      printf("%d ", d[m - 1]);
      for (i = m - 1; i >= 0; i--) {
        if (d[m - 1] % d[i] != 0) {
          printf("%d", d[i]);
          break;
        }
      }
      if (i == 0) printf("%d", b[k - 1]);
    } else if (m == 1)
      printf("%d %d\n", d[0], b[k - 1]);
  }
  return 0;
}
