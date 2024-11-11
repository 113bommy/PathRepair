#include <bits/stdc++.h>
using namespace std;
int n;
class node {
 public:
  int id, l, r;
  bool operator<(const node &t) const {
    if (r != t.r) return r < t.r;
    return l < t.l;
  }
} a[2010];
int ans[2010], lst[2010], tmp[2010];
bool inter[2010][2010], flag[2010];
bool check(int v) {
  fill(lst + 1, lst + n + 1, n);
  fill(ans + 1, ans + n + 1, 0);
  int cur = 1;
  for (int i = 1; i <= n; i++) {
    ans[i] = a[cur].id;
    lst[cur] = i;
    for (int j = 1; j <= n; j++) {
      if (inter[j][cur]) {
        lst[j] = min(lst[j], i + v);
      }
    }
    fill(tmp + 1, tmp + n + 1, 0);
    for (int j = 1; j <= n; j++) tmp[lst[j]]++;
    for (int j = 1; j <= n; j++) tmp[j] += tmp[j - 1];
    for (int j = 1; j <= n; j++) {
      if (tmp[j] > j) return 0;
    }
    int tk = -1;
    for (int j = i + 1; j <= n; j++) {
      if (tmp[j] == j) {
        tk = j;
        break;
      }
    }
    for (int j = 1; j <= n; j++) {
      if (lst[j] > i && lst[j] <= tk) {
        cur = j;
        break;
      }
    }
  }
  return 1;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].l, &a[i].r), a[i].id = i;
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (a[j].l <= a[i].r) inter[i][j] = inter[j][i] = 1;
    }
  }
  int l = 0, r = n, ret = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      ret = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  check(ret);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
