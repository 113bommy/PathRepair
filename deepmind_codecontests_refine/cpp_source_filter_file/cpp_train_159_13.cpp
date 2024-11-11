#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
int ans, c[N], v[N], g[N], n, k, s, t;
struct Node {
  int pri, cap;
  void Read() { scanf("%d%d", &pri, &cap); }
  bool operator<(const Node& b) const {
    if (pri == b.pri) return cap > b.cap;
    return pri < b.pri;
  }
} a[N];
int Check2(int l, int r, int d, int v) {
  int ret = -1;
  while (l <= r) {
    int mid = l + r >> 1;
    int x = mid;
    int y = d - x;
    if (x * 2 + y <= v) {
      ret = x + 2 * y;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return ret;
}
bool Check(int v) {
  int sum = 0;
  for (int i = 1; i <= k + 1; i++) {
    int d = g[i] - g[i - 1];
    int cur = Check2(0, d, d, v);
    if (cur < 0) return 0;
    sum += cur;
  }
  return sum <= t;
}
int main() {
  scanf("%d%d%d%d", &n, &k, &s, &t);
  for (int i = 0; i < n; i++) a[i].Read();
  sort(a, a + n);
  int m = 0;
  for (int i = 1; i < n; i++) {
    if (a[i].cap <= a[m].pri) continue;
    a[++m] = a[i];
  }
  n = ++m;
  for (int i = 1; i <= k; i++) scanf("%d", g + i);
  sort(g + 1, g + k + 1);
  g[0] = 0;
  g[k + 1] = s;
  int l = 0, r = n - 1, ans = -1;
  while (l <= r) {
    int mid = l + r >> 1;
    if (Check(a[mid].cap)) {
      ans = a[mid].pri;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  printf("%d\n", ans);
  return 0;
}
