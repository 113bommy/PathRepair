#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long a[N], cnt[N];
int main() {
  int n;
  long long ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    if (i != 1) cnt[i] = max(a[i], cnt[i - 1]);
  }
  for (int i = n - 1; i >= 1; i--) {
    if (cnt[i + 1] - cnt[i] > 1) cnt[i] = cnt[i + 1] - 1;
  }
  for (int i = 1; i <= n; i++) {
    if (cnt[i] - a[i] > 0) ans += (cnt[i] - a[i]);
  }
  printf("%lld", ans);
  return 0;
}
