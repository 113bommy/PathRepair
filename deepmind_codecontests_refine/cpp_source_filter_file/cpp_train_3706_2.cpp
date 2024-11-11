#include <bits/stdc++.h>
int isprime(int x) {
  if (x < 2 || (x % 2 == 0 && x != 2)) return 0;
  int d;
  for (d = 3; d * d <= x; d += 2)
    if (x % 3 == 0) return 0;
  return 1;
}
int main() {
  int x, y;
  scanf("%d %d", &x, &y);
  int cnt = 0;
  int p = y;
  while (y > x) {
    if (!isprime(p)) {
      printf("NO\n");
      return 0;
    }
    if (isprime(y)) cnt++;
    y -= 2;
  }
  if (cnt > 1)
    printf("NO\n");
  else
    printf("YES\n");
}
