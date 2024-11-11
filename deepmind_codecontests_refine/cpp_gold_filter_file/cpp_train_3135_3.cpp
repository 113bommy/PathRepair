#include <bits/stdc++.h>
using namespace std;
long long n, m;
int main() {
  scanf("%lld%lld", &n, &m);
  if (n > m) swap(n, m);
  if (n == 1)
    printf("%lld\n", 6 * (m / 6) + max((m % 6) * 2 - 6, 0LL));
  else if (n == 2) {
    if (m == 2)
      printf("0\n");
    else if (m == 3)
      printf("4\n");
    else if (m == 7)
      printf("12\n");
    else
      printf("%lld\n", m * 2);
  } else
    printf("%lld\n", n * m / 2 * 2);
  return 0;
}
