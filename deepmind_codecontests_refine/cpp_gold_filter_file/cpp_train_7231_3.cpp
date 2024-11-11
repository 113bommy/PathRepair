#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct node {
  int id, l, r, k;
} a[N], b[N];
multiset<node> s;
int n, m, v[N], ans;
bool operator<(node x, node y) { return x.l < y.l; }
bool cmp(node x, node y) { return x.r < y.r; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &b[i].l, &b[i].r), b[i].id = i;
  scanf("%d", &m);
  for (int i = 1; i <= m; i++)
    scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].k), a[i].id = i;
  sort(b + 1, b + 1 + n, cmp);
  sort(a + 1, a + 1 + m, cmp);
  int z = 1;
  for (int i = 1; i <= m; i++) {
    while (z <= n && b[z].r <= a[i].r) s.insert(b[z++]);
    set<node>::iterator it = s.lower_bound(a[i]);
    while (a[i].k && it != s.end()) {
      node k = *it;
      ans++;
      a[i].k--;
      v[k.id] = a[i].id;
      s.erase(it);
      it = s.lower_bound(a[i]);
    }
  }
  if (ans != n)
    printf("NO");
  else {
    printf("YES\n");
    for (int i = 1; i <= n; i++) printf("%d ", v[i]);
  }
}
