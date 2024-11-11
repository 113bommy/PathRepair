#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  int i;
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  int cnt = 0;
  for (i = 0; i < n - 1; i++) {
    if (a[i] % 10 == a[i + 1] / 10) cnt++;
  }
  printf("%d", cnt);
}
