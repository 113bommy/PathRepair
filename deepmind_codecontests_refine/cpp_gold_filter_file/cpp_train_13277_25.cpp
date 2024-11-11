#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, j, a[100100], p = 1;
  scanf("%lld", &n);
  for (i = 0; i < n; i++) scanf("%lld", &a[i]);
  sort(a, a + n);
  for (i = 0; i < n; i++) {
    if (a[i] >= p) p++;
  }
  printf("%lld\n", p);
  return 0;
}
