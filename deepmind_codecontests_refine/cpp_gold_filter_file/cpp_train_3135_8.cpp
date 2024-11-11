#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  scanf("%d", &n);
  scanf("%d", &m);
  if (n > m) swap(n, m);
  if (n == 1)
    printf("%d\n", m / 6 * 6 + max(0, m % 6 - 3) * 2);
  else if (n == 2)
    printf("%d\n", m == 2 ? 0 : m == 3 ? 4 : m == 7 ? 12 : m * n);
  else
    printf("%I64d\n", 1ll * n * m / 2 * 2);
}
