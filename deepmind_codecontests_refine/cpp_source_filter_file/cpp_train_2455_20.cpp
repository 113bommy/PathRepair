#include <bits/stdc++.h>
bool a[2105];
int n, i = 1, j, k;
int main() {
  scanf("%d", &n);
  k = (n + 1) / 2;
  for (; i <= n; i++) {
    scanf("%d", &j);
    a[j] = 1;
  }
  i = 0;
  while (k) {
    if (a[i]) {
      k--;
    }
    i++;
  }
  printf("%d", i);
  return 0;
}
