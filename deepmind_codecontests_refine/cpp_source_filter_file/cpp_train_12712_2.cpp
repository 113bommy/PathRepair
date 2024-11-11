#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, l, m, n, a[10000];
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  int mx = 0, temp = 0;
  for (i = 0; i < n; i++) {
    k = 0;
    for (j = i; j < n; j++) {
      k += a[j];
      if (k > (j - i + 1) * 100) mx = max(mx, j - i + 1);
    }
  }
  printf("%d\n", mx);
  return 0;
}
