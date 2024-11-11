#include <bits/stdc++.h>
int n;
int main() {
  scanf("%d", &n);
  if (~n & 2) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i <= n; i++) printf("%d ", i - 1);
  puts("");
  for (int i = 1; i <= n; i++) printf("%d ", i - 1);
  puts("");
  for (int i = 1; i <= n; i++) printf("%d ", ((i - 1) << 1) % n);
  return 0;
}
