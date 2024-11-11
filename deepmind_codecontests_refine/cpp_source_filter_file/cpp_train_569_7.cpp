#include <bits/stdc++.h>
using namespace std;
int n, t[100005], ans[100005];
pair<pair<int, int>, int> a[100005];
void Upd(int pos, int val) {
  pos += n;
  t[pos] = val;
  while (pos > 0) pos >>= 1, t[pos] = max(t[pos + pos], t[pos + pos + 1]);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d%d", &a[i].first.first, &a[i].first.second), a[i].second = i;
  sort(a, a + n);
  Upd(n - 1, n - 1);
  ans[a[n - 1].second] = 1;
  for (int i = n - 2; i >= 0; --i) {
    int l = i, r = n - 1, m, p = -1, p2 = -1;
    while (l <= r) {
      m = (l + r) >> 1;
      if (a[m].first.first <= a[i].first.first + a[i].first.second - 1) {
        l = m + 1;
        p = m;
      } else
        r = m - 1;
    }
    assert(p != -1);
    l = i + 1, r = p;
    while (l <= r) {
      if (l & 1) p2 = max(p2, t[l]);
      if (!(r & 1)) p2 = max(t[r], p2);
      l = (l + 1) >> 1;
      r = (r - 1) >> 1;
    }
    ans[a[i].second] = p2 != -1 ? p2 - i + 1 : p - i + 1;
    Upd(i, p2 != -1 ? p2 : p);
  }
  for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
  return 0;
}
