#include <bits/stdc++.h>
using namespace std;
int f[2100];
pair<int, int> a[123456];
int main() {
  f[0] = 0;
  for (int i = 1; i < 2100; i++) {
    if (i & 1)
      f[i] = i * (i - 1) / 2 + 1;
    else
      f[i] = i * i / 2;
  }
  for (int i = 1; i < 2100; i++) {
    assert(f[i] >= f[i - 1]);
  }
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) scanf("%d%d", &a[i].second, &a[i].first);
  sort(a, a + m);
  n = upper_bound(f, f + 2100, n) - f - 1;
  long long ans = 0;
  for (int i = m - 1; n-- && i >= 0; i--) {
    ans += a[i].first;
  }
  cout << ans << endl;
}
