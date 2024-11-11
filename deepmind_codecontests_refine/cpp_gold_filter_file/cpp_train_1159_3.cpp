#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, j, k, l;
  long long *a, *b;
  scanf("%d", &n);
  a = (long long *)malloc(n * sizeof(long long));
  b = (long long *)malloc(n * sizeof(long long));
  for (j = 0; j < n; j++) {
    scanf("%lld", &a[j]);
  }
  sort(a, a + n);
  j = (n - 1) / 2;
  l = j - 1;
  k = j + 1;
  b[j] = a[0];
  for (j = 1; j < n; j++) {
    if (j % 2) {
      b[k++] = a[j];
    } else {
      b[l--] = a[j];
    }
  }
  for (j = 0; j < n; j++) {
    printf("%lld ", b[j]);
  }
  return 0;
}
