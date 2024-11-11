#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n, k;
int a[N];
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  long long ans = -1e12;
  int l = max(1, n - 2 * k);
  for (int i = l; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      ans = max(ans, 1LL * i * j - 1LL * k * (a[i] | a[j]));
  printf("%lld\n", ans);
}
int main() {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
