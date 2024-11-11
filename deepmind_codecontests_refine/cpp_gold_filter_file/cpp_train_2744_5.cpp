#include <bits/stdc++.h>
int main() {
  int n, h[100001], m[100001], i, count = 1, max = 1;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d %d", &h[i], &m[i]);
  }
  for (i = 0; i < n; i++) {
    if (h[i] == h[i - 1] && m[i] == m[i - 1])
      count++;
    else
      count = 1;
    if (count > max) {
      max = count;
    }
  }
  printf("%d", max);
  return 0;
}
