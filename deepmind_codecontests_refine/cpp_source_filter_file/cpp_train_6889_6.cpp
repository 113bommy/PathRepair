#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005000;
const int inf = 1e9;
int n, m;
long long ans[maxn];
int a[maxn], L[maxn], R[maxn];
pair<int, int> stl[maxn], str[maxn];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int sz, x, topl = 0, topr = 0;
    scanf("%d", &sz);
    for (int j = 1; j <= sz; j++) scanf("%d", &a[j]);
    for (int j = 1; j <= sz; j++) {
      while (topl && stl[topl].first <= a[j]) R[stl[topl].second] = j, topl--;
      stl[++topl] = {a[j], j};
    }
    while (topl) R[stl[topl].second] = m + 1, topl--;
    for (int j = sz; j >= 1; j--) {
      while (topr && str[topr].first <= a[j]) L[str[topr].second] = j, topr--;
      str[++topr] = {a[j], j};
    }
    while (topr) L[str[topr].second] = -inf, topr--;
    for (int j = 1; j <= sz; j++) {
      int l = max(L[j] + m - sz + 1, j);
      int r = min(j + m - sz, R[j] - 1);
      if (l <= r) {
        if (a[j] >= 0)
          ans[l] += a[j], ans[r + 1] -= a[j];
        else {
          l = max(l, m - sz + 1);
          r = min(r, sz);
          if (l <= r) ans[l] += a[j], ans[r + 1] -= a[j];
        }
      }
    }
    for (int j = 1; j <= sz; j++) L[j] = R[j] = 0;
  }
  for (int i = 1; i <= n; i++) ans[i] += ans[i - 1];
  for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
  return 0;
}
