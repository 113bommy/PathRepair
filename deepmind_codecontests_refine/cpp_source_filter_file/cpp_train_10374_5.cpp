#include <bits/stdc++.h>
using namespace std;
int a[100001];
int b[100002];
int c[100001];
int main() {
  int n, i, j, min, l, r, m;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
  min = a[n];
  j = n;
  c[j] = j;
  for (i = n; i >= 1; --i) {
    if (a[i] < min) {
      min = a[i];
      j = i;
    }
    b[i] = min;
    c[i] = j;
  }
  b[0] = 0;
  b[n + 1] = 2000000000;
  for (i = 1; i <= n; ++i) {
    if (a[i] > b[i]) {
      l = lower_bound(b + i + 1, b + n + 1, a[i] + 1) - b - 1;
      printf("%d ", l - i - 1);
    } else
      printf("-1 ");
  }
  return 0;
}
