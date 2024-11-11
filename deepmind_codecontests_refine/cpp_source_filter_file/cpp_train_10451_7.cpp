#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
int n;
struct iii {
  int first, second, td;
  iii() {}
  iii(int u, int v, int w) : first(u), second(v), td(w) {}
  bool operator<(const iii &a) const { return first < a.first; }
} d[maxn];
int pos[maxn], s[maxn], dln[maxn], cnt[maxn];
bool check(int spa) {
  int i, j, r, sum, tp;
  for (i = 1; i <= n; i++) dln[i] = n, pos[i] = 0;
  for (i = 1; i <= n; i++) {
    memset(cnt, 0, sizeof cnt);
    for (j = 1; j <= n; j++) cnt[dln[j]]++;
    for (sum = 0, r = i; r <= n; r++) {
      sum += cnt[i];
      if (sum > r - i + 1) return 0;
      if (sum == r - i + 1) break;
    }
    for (tp = 1; tp <= n; tp++)
      if (!pos[tp] && dln[tp] <= r) break;
    pos[tp] = i;
    s[i] = d[tp].td;
    dln[tp] = 0;
    for (j = 1; j <= n; j++)
      if (!pos[j] && !(d[j].second < d[tp].first) &&
          !(d[tp].second < d[j].first))
        dln[j] = min(dln[j], i + spa);
  }
  return 1;
}
int main() {
  int i, u, v;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &u, &v);
    d[i] = iii(v, u, i);
  }
  sort(d + 1, d + n + 1);
  for (i = 1; i <= n; i++) swap(d[i].first, d[i].second);
  int l = 0, r = n - 1, res, mid;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (check(mid))
      res = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  check(res);
  for (i = 1; i <= n; i++) printf("%d ", s[i]);
  return 0;
}
