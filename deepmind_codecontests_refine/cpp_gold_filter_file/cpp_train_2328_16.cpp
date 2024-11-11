#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int main() {
  long long n, m, v, i, si;
  scanf("%lld %lld %lld", &n, &m, &v);
  for (i = 1; i <= n; i++) a[i] = i;
  if (m < n - 1 || m > (n - 1) * (n - 2) / 2 + 1) {
    printf("-1\n");
    return 0;
  }
  swap(a[v], a[n - 1]);
  m -= n - 1;
  for (i = 1; i < n; i++) printf("%d %d\n", a[i], a[i + 1]);
  for (i = 1; i < n - 1 && m; i++) {
    for (int j = i + 2; j < n && m; j++) printf("%d %d\n", a[i], a[j]), m--;
  }
  return 0;
}
