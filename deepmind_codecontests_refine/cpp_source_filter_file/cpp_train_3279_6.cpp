#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int a[N];
bool f[N];
int n, m, i, j, k, u, v;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 1; i <= n; i++) {
    if (a[i] == i) u = i;
    if (a[a[i]] == i) v = i;
  }
  if (u) {
    printf("YES\n");
    for (i = 1; i <= n; i++)
      if (i != u) printf("%d %d\n", u, i);
    return 0;
  } else {
    f[v] = f[a[v]] = true;
    for (i = 1; i <= n; i++)
      if (!f[i]) {
        f[i] = true;
        if (a[i] != i) {
          j = a[i];
          k = 1;
          while (j != i) {
            k++;
            f[j] = true;
            j = a[j];
          }
          if (k & 1) {
            printf("NO\n");
            return 0;
          }
        }
      }
    printf("YES\n");
    printf("%d %d\n", v, a[v]);
    f[v] = f[a[v]] = false;
    k = v;
    for (i = 1; i <= n; i++)
      if (f[i]) {
        f[i] = false;
        j = a[i];
        printf("%d %d\n", v, i);
        v = a[v];
        while (j != i) {
          f[j] = false;
          printf("%d %d\n", v, j);
          j = a[j];
          v = a[v];
        }
      }
    return 0;
  }
  printf("NO\n");
  return 0;
}
