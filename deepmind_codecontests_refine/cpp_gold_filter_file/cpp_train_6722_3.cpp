#include <bits/stdc++.h>
using namespace std;
int n, a, b, dif = 1e6 + 11;
int main() {
  scanf("%d", &n);
  for (int i = 1; i * i <= n; ++i)
    if (n % i == 0 && (max(n / i, i) - min(n / i, i)) < dif)
      a = min(n / i, i), b = max(n / i, i),
      dif = (max(n / i, i) - min(n / i, i));
  printf("%d %d\n", a, b);
  return 0;
}
