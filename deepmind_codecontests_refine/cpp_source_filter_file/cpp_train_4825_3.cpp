#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
const int mod = 1e9 + 7;
int n, k, a, b, c, d;
pair<int, int> p[maxn];
int tot = 1;
struct Tr {
  int l, r, x, lson, rson;
  pair<int, int> v;
} tree[maxn];
int newnode(int &x) { return x = ++tot; }
pair<int, int> deal(pair<int, int> a, pair<int, int> b) {
  return make_pair(a.second + b.second,
                   max(a.first + b.second, a.second + b.first) + 1);
}
void build_tree(int l, int r, int x) {
  int high = -1, id = l;
  for (int i = l; i <= r; i++)
    if (p[i].second > high) high = p[i].second, id = i;
  tree[x].l = p[l].first, tree[x].r = p[r].first, tree[x].x = p[id].first;
  if (id > l) build_tree(l, id - 1, newnode(tree[x].lson));
  if (id < r) build_tree(id + 1, r, newnode(tree[x].rson));
  tree[x].v = deal(tree[tree[x].lson].v, tree[tree[x].rson].v);
}
pair<int, int> query(int l, int r, int x) {
  if (x == 0 || l > tree[x].r || r < tree[x].l) return make_pair(-1, 0);
  if (l <= tree[x].l && r >= tree[x].r) return tree[x].v;
  if (r < tree[x].x) return query(l, r, tree[x].lson);
  if (l > tree[x].x) return query(l, r, tree[x].rson);
  return deal(query(l, r, tree[x].lson), query(l, r, tree[x].rson));
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < k; i++) scanf("%d%d", &p[i].first, &p[i].second);
  scanf("%d%d%d%d", &a, &b, &c, &d);
  for (int i = k; i < n; i++)
    p[i] = make_pair((1LL * p[i - 1].first * a + b) % mod,
                     (1LL * p[i - 1].second * c + d) % mod);
  sort(p, p + n);
  tree[0].v = make_pair(-1, 0);
  build_tree(0, n - 1, 1);
  int m;
  scanf("%d", &m);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", query(a, b, 1).second);
  }
}
