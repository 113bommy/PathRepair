#include <bits/stdc++.h>
int main() {
  int n, i = 1;
  scanf("%d", &n);
  while (i * i < n) {
    i++;
  }
  i = i - 1;
  int ans = i * 4;
  n = n - i * i;
  if (n <= i)
    ans += 2;
  else
    ans += 4;
  printf("%d", ans);
}
