#include <bits/stdc++.h>
using namespace std;
long long a[100005];
int main() {
  long long n, i, ans;
  scanf("%lld", &n);
  for (i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    ans += 1ll * a[i] * (n - a[i] + 1);
  }
  for (i = 1; i < n; i++)
    ans -= 1ll * min(a[i], a[i + 1]) * (n - max(a[i], a[i + 1]) + 1);
  printf("%lld", ans);
  return 0;
}
