#include <bits/stdc++.h>
using namespace std;
int n, k, p, a[2005], b[2005];
long long ans = 5000000000000000000;
int main() {
  scanf("%d %d %d", &n, &k, &p);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < k; i++) {
    scanf("%d", b + i);
  }
  sort(a, a + n);
  sort(b, b + k);
  for (int i = 0; i < k - n + 1; i++) {
    long long cev = 0;
    for (int j = i; j < i + n; j++) {
      if (abs(p - a[j - i]) > abs(p - b[j]) &&
          abs(p - a[j - i]) > abs(a[j - i] - b[j])) {
        cev = max(1ll * abs(p - a[j - i]), cev);
      } else {
        cev = max(1ll * abs(a[j - i] - b[j]) + 1ll * abs(b[j] - p), cev);
      }
    }
    ans = min(ans, cev);
  }
  printf("%lld", ans);
}
