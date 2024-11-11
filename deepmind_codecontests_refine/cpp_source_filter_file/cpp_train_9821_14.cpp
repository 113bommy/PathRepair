#include <bits/stdc++.h>
using namespace std;
int a, b, n;
signed main() {
  scanf("%d%d%d", &a, &b, &n);
  if (n == 0) return printf("%lld\n", a), 0;
  if (n == 1) return printf("%lld\n", b), 0;
  for (int i = 2; i <= n; i++) {
    swap(a, b);
    b = a + b;
  }
  return printf("%lld\n", b), 0;
}
