#include <bits/stdc++.h>
using namespace std;
struct node {
  int id, day;
  friend bool operator<(node a, node b) { return a.day < b.day; }
} s[10005];
int n, m, a[10005], b[10005], sign[10005];
int judge(int mid) {
  int i, j, tmp;
  memset(sign, 0, sizeof(sign));
  for (i = 1; i <= mid; i++) {
    if (a[i] == 0) continue;
    s[a[i]].id = a[i];
    s[a[i]].day = i;
    sign[a[i]] = 1;
  }
  sort(s + 1, s + m + 1);
  tmp = s[0].day = 0;
  for (i = 1; i <= m; i++) {
    if (sign[i] == 0) return 0;
    tmp += (s[i].day - s[i - 1].day - 1);
    if (tmp < b[s[i].id]) return 0;
    tmp -= b[s[i].id];
  }
  return 1;
}
int main() {
  int i, j, l, r, ans, mid;
  while (scanf("%d%d", &n, &m) != EOF) {
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (i = 1; i <= m; i++) scanf("%d", &b[i]);
    ans = -1;
    l = 1, r = n;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (judge(mid)) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
