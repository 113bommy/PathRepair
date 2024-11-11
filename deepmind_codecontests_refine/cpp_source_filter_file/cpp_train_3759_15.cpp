#include <bits/stdc++.h>
using namespace std;
int n, m, a[200010], b[200010];
map<int, int> d;
int main() {
  int mn = 1200000000, mx = 0;
  scanf("%d%*d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    mn = min(mn, a[i]);
    mx = max(mx, a[i]);
  }
  scanf("%d%*d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
    mn = min(mn, a[i]);
    mx = max(mx, a[i]);
  }
  int ans = 0;
  for (unsigned s = 1; s <= 1200000000; s <<= 1) {
    d.clear();
    for (int i = 1; i <= n; i++) {
      if (d.count(a[i] % (s * 2)) == 0) {
        d[a[i] % (s * 2)] = 1;
      } else {
        d[a[i] % (s * 2)]++;
      }
    }
    for (int i = 1; i <= m; i++) {
      if (d.count((b[i] + s) % (s * 2)) == 0) {
        d[(b[i] + s) % (s * 2)] = 1;
      } else {
        d[(b[i] + s) % (s * 2)]++;
      }
    }
    int now = 0;
    for (auto i : d) {
      now = max(now, i.second);
    }
    ans = max(now, ans);
  }
  printf("%d\n", ans);
}
