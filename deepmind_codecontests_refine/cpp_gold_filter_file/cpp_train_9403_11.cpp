#include <bits/stdc++.h>
int main() {
  int n, k, s = 0;
  scanf("%d%d", &n, &k);
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int j = 0; j < n; j++) {
    if (n == k && a[j] >= a[k - 1] && a[j] > 0)
      s++;
    else if (a[j] >= a[k - 1] && a[j] > 0)
      s++;
  }
  printf("%d", s);
}
