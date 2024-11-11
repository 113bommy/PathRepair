#include <bits/stdc++.h>
int n;
int main() {
  scanf("%d", &n);
  if (n % 2 == 0) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (int i = 1; i <= 2 * n; i++) {
    printf("%d ", i);
    if (i % 2) i += 2;
  }
  for (int i = 2; i <= 2 * n; i++) {
    printf("%d ", i);
    if (i % 2) i += 2;
  }
  return 0;
}
