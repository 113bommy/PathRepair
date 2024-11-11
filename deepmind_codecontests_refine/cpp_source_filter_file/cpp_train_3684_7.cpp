#include <bits/stdc++.h>
using namespace std;
int a[510][510];
int b[510];
long long c[510];
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[n + 1 - i]);
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++)
        for (int k = 1; k <= i; k++)
          if (a[b[j]][b[k]] > a[b[j]][b[i]] + a[b[i]][b[k]])
            a[b[j]][b[k]] = a[b[j]][b[i]] + a[b[i]][b[k]];
      for (int j = 1; j <= i; j++)
        for (int k = 1; k <= i; k++) c[n - i + 1] += a[b[j]][b[k]];
    }
    for (int i = 1; i < n; i++) printf("%I64d ", c[i]);
    printf("%I64d\n", c[n]);
  }
  return 0;
}
