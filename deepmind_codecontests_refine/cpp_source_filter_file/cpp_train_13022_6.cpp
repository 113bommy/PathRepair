#include <bits/stdc++.h>
using namespace std;
long long n, m, sq[100069], zs = 0;
pair<long long, long long> a[100069];
int main() {
  long long i, j, mx = -1e18;
  scanf("%lld%lld", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%lld%lld", &a[i].first, &a[i].second);
  }
  sort(a, a + n);
  for (j = 0, i = 1; i <= m; i++) {
    for (; a[j].first <= i; j++) {
      mx = max(mx, a[j].second);
    }
    if (i > mx) {
      zs++;
      sq[zs] = i;
    }
  }
  printf("%lld\n", zs);
  for (i = 1; i <= zs; i++) {
    printf("%lld%c", sq[i], " \n"[i == zs]);
  }
}
