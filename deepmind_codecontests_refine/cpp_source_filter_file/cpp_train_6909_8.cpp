#include <bits/stdc++.h>
using namespace std;
int n, x;
long long a[100100], b[100100];
int main() {
  while (~scanf("%d%d", &n, &x)) {
    x--;
    for (int i = 0; i < n; i++) scanf("%I64d", a + i);
    int z = x;
    for (int i = x + 1; i < n; i++)
      if (a[i] < a[z] || (a[i] == a[z] && x > z)) z = i;
    for (int i = x - 1; i >= 0; i--)
      if (a[i] < a[z] || (a[i] == a[z] && z > x)) z = i;
    if (z <= x) {
      for (int i = 0; i < n; i++)
        if (i > z && i <= x)
          b[i] = a[i] - a[z] - 1;
        else
          b[i] = a[i] - a[z];
      b[z] = a[z] * n + x - z;
    } else {
      for (int i = 0; i < n; i++)
        if (i > x && i <= z)
          b[i] = a[i] - a[z];
        else
          b[i] = a[i] - a[z] - 1;
      b[z] = (a[z] + 1) * n - z + x;
    }
    for (int i = 0; i < n; i++) {
      if (i) putchar(' ');
      printf("%I64d", b[i]);
    }
    puts("");
  }
  return 0;
}
