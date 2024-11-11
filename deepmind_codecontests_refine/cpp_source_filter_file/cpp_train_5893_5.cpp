#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n;
long long a[maxn];
int l[maxn], r[maxn];
long long solve() {
  for (int i = 0; i < n; i++) {
    l[i] = n;
    r[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    int j;
    for (j = i - 1; j >= 0 && a[i] > a[j]; j = min(l[j], j - 1))
      ;
    l[i] = j;
  }
  for (int i = n - 1; i >= 0; i--) {
    int j;
    for (j = i + 1; j < n && a[i] >= a[j]; j = max(r[j], j + 1))
      ;
    r[i] = j;
  }
  long long res = 0;
  for (int i = 0; i < n; i++) {
    res += a[i] * (i - l[i]) * (r[i] - i);
  }
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", a + i);
  long long ans = solve();
  for (int i = 0; i < n; i++) a[i] = -a[i];
  ans = solve();
  printf("%lld\n", ans);
  return 0;
}
