#include <bits/stdc++.h>
using namespace std;
int n, a, b, i;
int main() {
  scanf("%d", &n);
  if (n & 1 ^ 1) return puts("-1"), 0;
  a = n / 2;
  b = a + (n > 1);
  for (i = 1; i <= n; i++) printf("%d ", a), a = (a - 1 + n) % n;
  puts("");
  for (i = 1; i <= n; i++) printf("%d ", b), b = (b + 2 + n) % n;
  puts("");
  for (i = 1; i <= n; i++) printf("%d ", i - 1);
}
