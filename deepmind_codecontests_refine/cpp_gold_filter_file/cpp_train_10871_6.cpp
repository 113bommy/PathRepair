#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int n;
long long a[2000];
int main() {
  int i, j, k;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%I64d", &a[i]);
  sort(a, a + n);
  int rmin = INT_MAX, rx, ry;
  for (i = 0; i < 30000; i++) {
    int min = INT_MAX, max = INT_MIN;
    for (j = 0; j < n; j++) {
      if (a[j] - i * j < min) min = a[j] - i * j;
      if (a[j] - i * j > max) max = a[j] - i * j;
    }
    if ((max - min + 1) / 2 < rmin) {
      rmin = (max - min + 1) / 2;
      rx = (max + min) / 2;
      ry = i;
    }
  }
  printf("%d\n%d %d", rmin, rx, ry);
  return 0;
}
