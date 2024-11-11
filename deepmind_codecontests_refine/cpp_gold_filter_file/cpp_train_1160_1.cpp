#include <bits/stdc++.h>
using namespace std;
int n, a[100005];
long long ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    ans += 1ll * a[i] * (n - a[i] + 1);
  }
  for (int i = 1; i < n; i++)
    ans -= 1ll * min(a[i], a[i + 1]) * (n - max(a[i], a[i + 1]) + 1);
  printf("%I64d\n", ans);
  return 0;
}
