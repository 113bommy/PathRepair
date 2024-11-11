#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n;
  scanf("%d", &n);
  for (i = 1; i <= 4; ++i) {
    int m1, m2, a, b;
    scanf("%d%d", &a, &b);
    m1 = min(a, b);
    scanf("%d%d", &a, &b);
    m2 = min(a, b);
    if (m1 + m2 <= n) {
      printf("%d %d %d\n", i, m1, n - m2);
      return 0;
    }
  }
  puts("-1");
  return 0;
}
