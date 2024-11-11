#include <bits/stdc++.h>
int n;
std::pair<int, int> x[300005], y[300005];
bool fx[300005], fy[300005];
long long ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x[i].first, &y[i].first);
    x[i].second = y[i].second = i;
  }
  std::sort(x + 1, x + n + 1), std::sort(y + 1, y + n + 1);
  int mid = (n + 1) >> 1;
  for (int i = 1; i <= n; i++) fx[x[i].second] = fy[y[i].second] = i <= mid;
  if ((n & 1) && x[mid].second != y[mid].second) {
    for (int i = 1; i < mid; i++) ans -= 2ll * (x[i].first + y[i].first);
    for (int i = mid + 1; i <= n; i++) ans += 2ll * (x[i].first + y[i].first);
  } else {
    if (n & 1) {
      for (int i = 1; i < mid; i++) ans -= 2ll * (x[i].first + y[i].first);
      for (int i = mid + 1; i <= n; i++) ans += 2ll * (x[i].first + y[i].first);
      bool f1 = 0, f2 = 0;
      for (int i = 1; i <= n; i++) {
        if (i == x[mid].second) continue;
        if (fx[i] == fy[i])
          f1 = 1;
        else
          f2 = 1;
      }
      if (f1 && f2)
        ans -= 2ll * std::min(std::min(x[mid + 1].first - x[mid].first,
                                       x[mid].first - x[mid - 1].first),
                              std::min(y[mid + 1].first - y[mid].first,
                                       y[mid].first - y[mid - 1].first));
    } else {
      for (int i = 1; i <= mid; i++) ans -= 2ll * (x[i].first + y[i].first);
      for (int i = mid + 1; i <= n; i++) ans += 2ll * (x[i].first + y[i].first);
      bool f1 = 0, f2 = 0;
      for (int i = 1; i <= n; i++) {
        if (fx[i] == fy[i])
          f1 = 1;
        else
          f2 = 1;
      }
      if (f1 && f2)
        ans -= 2ll * std::min(x[mid + 1].first - x[mid].first,
                              y[mid + 1].first - y[mid].first);
    }
  }
  printf("%lld\n", ans);
}
