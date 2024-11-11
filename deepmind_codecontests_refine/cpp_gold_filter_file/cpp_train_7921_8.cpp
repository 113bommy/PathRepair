#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  if (n > m) swap(n, m);
  if (n == 1)
    printf("%d\n", m / 6 * 6 + 2 * max(m % 6 - 3, 0));
  else if (n == 2) {
    if (m == 2)
      printf("0\n");
    else if (m == 3)
      printf("4\n");
    else if (m == 7)
      printf("12\n");
    else
      printf("%lld\n", 1LL * n * m);
  } else
    printf("%lld\n", 1LL * n * m / 2 * 2);
  return 0;
}
