#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;
long long er[100];
long long a[N], b[N], ta[N], tb[N];
int n;
int enough(long long x) {
  for (int i = 1; i <= n; i++) ta[i] = a[i], tb[i] = b[i];
  ta[1] -= tb[1] - x;
  tb[1] = x;
  for (int i = 2; i <= n; ++i) {
    ta[i] -= tb[i - 1];
    if (ta[i] > tb[i]) return 0;
    if (ta[i] > 0) tb[i] -= ta[i];
  }
  if (ta[1] > tb[n]) return 1;
  return 2;
}
long long get() {
  long long ans = 0, top = b[1];
  for (int i = 32; i >= 1; --i) {
    if (ans + er[i] > top) continue;
    int ca = enough(ans + er[i]);
    if (ca == 0)
      ans += er[i];
    else if (ca == 2)
      return ans + er[i];
  }
  return ans;
}
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; ++i) scanf("%lld", &b[i]);
  long long ans = get();
  if (enough(ans))
    printf("YES\n");
  else
    printf("NO\n");
}
signed main() {
  er[1] = 1;
  for (int i = 2; i < 100; ++i) er[i] = er[i - 1] * 2;
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
