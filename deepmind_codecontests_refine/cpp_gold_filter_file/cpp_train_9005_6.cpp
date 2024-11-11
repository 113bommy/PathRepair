#include <bits/stdc++.h>
using namespace std;
int a[200000], ndiff[200000];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  ndiff[n - 1] = n;
  for (int i = n - 2; i >= 0; i--) {
    if (a[i + 1] != a[i])
      ndiff[i] = i + 1;
    else
      ndiff[i] = ndiff[i + 1];
  }
  int l, r, x;
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &l, &r, &x);
    if (a[l - 1] != x)
      printf("%d\n", l);
    else if (ndiff[l - 1] < r)
      printf("%d\n", ndiff[l - 1] + 1);
    else
      printf("-1\n");
  }
  return 0;
}
