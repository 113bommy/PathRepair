#include <bits/stdc++.h>
using namespace std;
int n, a[300005];
long long c[2];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (i)
      c[1] += a[i] + 1 >> 1, c[0] += a[i] >> 1;
    else
      c[1] += a[i] >> 1, c[0] += a[i] + 1 >> 1;
  }
  printf("%lld", min(c[0], c[1]));
  return 0;
}
