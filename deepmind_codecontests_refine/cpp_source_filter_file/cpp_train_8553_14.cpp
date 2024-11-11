#include <bits/stdc++.h>
using namespace std;
int n, tot, vis[200005], tree[200005];
long long ans;
struct node {
  int x, y, rank;
} a[200005];
bool cmpx(node a, node b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }
bool cmpy(node a, node b) { return a.y == b.y ? a.x < b.x : a.y < b.y; }
void add(int x) {
  for (int i = x; i <= n; i += i & (-i)) tree[i]++;
}
int query(int x) {
  int ret = 0;
  for (int i = x; i > 0; i -= i & (-i)) ret += tree[i];
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].x, &a[i].y);
  sort(a + 1, a + 1 + n, cmpx);
  for (int i = 1; i <= n;) {
    int j = i;
    while (j <= n && a[i].x == a[j].x) a[j].rank = i, j++;
    i = j;
  }
  sort(a + 1, a + 1 + n, cmpy);
  for (int i = 1; i <= n;) {
    int j = i;
    while (j <= n && a[i].y == a[j].y) j++;
    for (int k = i; k < j; k++) {
      if (!vis[a[k].rank]) {
        vis[a[k].rank] = 1;
        tot++;
        add(a[k].rank);
      }
    }
    int last = 0;
    for (int k = i; k < j; k++) {
      ans += 1ll * (query(a[k].rank - 1) - query(last) + 1) *
             (tot - query(a[k].rank) + 1);
      last = a[k].rank;
    }
    i = j;
  }
  printf("%lld\n", ans);
  return 0;
}
