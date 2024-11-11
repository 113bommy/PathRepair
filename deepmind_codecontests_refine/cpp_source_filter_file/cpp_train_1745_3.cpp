#include <bits/stdc++.h>
using namespace std;
const int a[] = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292, 390};
const int maxn = 205;
int k, n, d;
int main() {
  scanf("%d", &n);
  if (n <= 12)
    printf("%d\n", n);
  else
    printf("%lld\n", 1LL * (n - 11) * 49 + a[11]);
  return 0;
}
