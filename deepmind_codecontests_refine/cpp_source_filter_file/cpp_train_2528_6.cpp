#include <bits/stdc++.h>
using namespace std;
int n, m;
struct qq {
  int l, r, id;
} q[100010];
bool cmp(qq a, qq b) { return a.r < b.r; }
set<int> s;
int ans[100010], anss;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &q[i].l, &q[i].r);
    q[i].l = n + 1 - q[i].l;
    q[i].id = i;
  }
  sort(q + 1, q + m + 1, cmp);
  int st = 1;
  for (int i = 1; i <= n; i++) s.insert(i);
  for (int i = 1; i <= m; i++) {
    set<int>::iterator it = s.lower_bound(q[i].l);
    if (it != s.end() && *it <= q[i].r) s.erase(it), ans[++anss] = q[i].id;
  }
  printf("%d\n", anss);
  sort(ans + 1, ans + anss + 1);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
