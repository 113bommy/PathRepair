#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  if (m == 3 && n > 4) {
    printf("-1\n");
    return 0;
  }
  int a = 17;
  if (m & 1) {
    puts("0 0");
    a = 1;
    n--;
    m--;
  }
  for (int i = 1; i <= m / 2; i++) {
    int x = -a * i * i;
    printf("%d %d\n", i, x);
    printf("%d %d\n", -i, x);
  }
  n -= m;
  for (int i = 1; i * 2 <= n; i++) {
    int x = 13 * i * i + 10086;
    printf("%d %d\n", i, x);
    printf("%d %d\n", -i, x);
  }
  if (n & 1) {
    int x = (n + 7) / 2, y = x * x + 10086;
    printf("%d %d\n", x, y);
  }
  return 0;
}
