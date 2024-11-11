#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
long long a[2][10] = {{0, 0, 0, 2, 4, 6}, {0, 0, 4, 8, 10, 12, 12}};
int main() {
  long long n, m;
  scanf("%lld%lld", &n, &m);
  if (n > m) swap(n, m);
  if (n == 1) {
    printf("%lld\n", 6ll * ((m - 1) / 6) + a[0][(m - 1) % 6]);
  } else if (n == 2) {
    if (m >= 8)
      printf("%lld\n", n * m);
    else
      printf("%lld\n", a[1][m - 1]);
  } else if ((n * m) & 1)
    printf("%lld\n", n * m - 1);
  else
    printf("%lld\n", n * m);
}
