#include <bits/stdc++.h>
using namespace std;
int n, x, p;
long long powe(long long x, int y) {
  if (y == 0) return 1ll;
  long long now = powe(x, y >> 1);
  now = now * now % p;
  if (y & 1) now = now * x % p;
  return now;
}
int main() {
  scanf("%d%d", &n, &x);
  p = n + 1;
  for (int i = 2; i * i <= p; i++)
    if (p % i == 0) {
      printf("-1\n");
      return 0;
    }
  for (int i = x - 1; i > 0; i--) {
    int j;
    for (j = 2; j * j <= n; j++)
      if (n % j == 0) {
        if (powe(i, j) == 1 || powe(i, n / j) == 1) break;
      }
    if (j * j > n) {
      printf("%d\n", i);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
