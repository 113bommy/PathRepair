#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int t, n, x, s, a[N];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    s = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), s += a[i];
    if (s % n) {
      printf("-1\n");
      continue;
    }
    s /= n;
    printf("%d\n", 3 * (n - 1));
    for (int i = 2; i <= n; i++) {
      x = (i - a[i] % i) % i;
      printf("1 %d %d\n", i, x);
      printf("%d 1 %d\n", i, a[i], (a[i] + x) / i);
    }
    for (int i = 2; i <= n; i++) printf("1 %d %d\n", i, s);
  }
  return 0;
}
