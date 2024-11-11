#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (n > m) swap(n, m);
  if (n == 1) printf("%d", m / 6 * 3 + 2 * max(m % 6 - 3, 0));
  if (n == 2) printf("%d", m == 2 ? 0 : m == 3 ? 4 : m == 7 ? 12 : m * 2);
  if (n > 3) printf("%lld", 1LL * n * m / 2 * 2);
  return 0;
}
