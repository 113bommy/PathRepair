#include <bits/stdc++.h>
using namespace std;
int a[5005];
int flag[1000005];
int g[1000005];
int main() {
  int n, m, i, j, k, l;
  scanf("%d %d", &n, &m);
  memset(g, 0, sizeof(g));
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + 1 + n);
  for (i = 1; i <= n; i++) {
    for (j = i + 1; j <= n; j++)
      if (a[j] - a[i] <= 1000000) {
        g[a[j] - a[i]]++;
      } else {
        break;
      }
  }
  memset(flag, 0, sizeof(flag));
  for (i = 1; i <= 1000001; i++) {
    if (i > 5000) {
      k = 0;
      for (j = i; j <= 1000000; j += i) {
        k += g[j];
      }
      if (k > m * (m + 1) / 2) {
        continue;
      }
    }
    k = 0;
    for (j = 1; j <= n; j++) {
      l = a[j] % i;
      if (flag[l] < i) {
        flag[l] = i;
      } else {
        k++;
        if (k > m) {
          break;
        }
      }
    }
    if (k <= m) {
      break;
    }
  }
  printf("%d\n", i);
}
