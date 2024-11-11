#include <bits/stdc++.h>
using namespace std;
struct Node {
  long long a, b;
  int id;
  void in() { cin >> a >> b; }
} p[100010];
bool cmp(Node a, Node b) {
  if (a.a == b.a) return a.b > b.b;
  return a.a > b.a;
}
struct ask {
  int l, r;
  long long t;
  int id;
  void in() { cin >> l >> r >> t; }
} Q[100010];
bool cmpask(ask a, ask b) { return a.t < b.t; }
Node pp1[100010];
int qq1;
Node pp2[100010];
int qq2;
bool flag[100010];
void change() {
  sort(pp1, pp1 + qq1, cmp);
  for (int i = 0; i < qq1; i++) flag[i] = true;
  long long now = pp1[0].b;
  for (int i = 1; i < qq1; i++) {
    if (pp1[i].b <= now) flag[i] = false;
    now = max(now, pp1[i].b);
  }
  qq2 = 0;
  for (int i = 0; i < qq1; i++)
    if (flag[i]) pp2[qq2++] = pp1[i];
  qq1 = 0;
  for (int i = 0; i < qq2; i++) {
    while (qq1 > 1) {
      long long a1 = pp1[qq1 - 2].a;
      long long b1 = pp1[qq1 - 2].b;
      long long a2 = pp1[qq1 - 1].a;
      long long b2 = pp1[qq1 - 1].b;
      long long a3 = pp2[i].a;
      long long b3 = pp2[i].b;
      if ((b3 - b1) * (a1 - a2) < (b2 - b1) * (a1 - a3)) break;
      qq1--;
    }
    pp1[qq1++] = pp2[i];
  }
}
vector<Node> f[100010 * 3];
int len[100010 * 3];
void build(int l, int r, int root) {
  qq1 = 0;
  for (int i = l; i <= r; i++) pp1[qq1++] = p[i];
  change();
  f[root].clear();
  for (int i = 0; i < qq1; i++) f[root].push_back(pp1[i]);
  reverse(f[root].begin(), f[root].end());
  len[root] = f[root].size();
  if (l == r) return;
  int m = (l + r) >> 1;
  build(l, m, root << 1);
  build(m + 1, r, root << 1 | 1);
}
pair<long long, int> query(int L, int R, long long t, int l, int r, int root) {
  if (L <= l && r <= R) {
    int le = len[root];
    while (le > 1 && f[root][le - 1].a + f[root][le - 1].b * t <=
                         f[root][le - 2].a + f[root][le - 2].b * t)
      le--;
    len[root] = le;
    return make_pair(f[root][le - 1].a + f[root][le - 1].b * t,
                     f[root][le - 1].id);
  }
  int m = (l + r) >> 1;
  pair<long long, int> ret = make_pair(-1, -1);
  if (L <= m) {
    pair<long long, int> now = query(L, R, t, l, m, root << 1);
    if (now.first > ret.first) ret = now;
  }
  if (R > m) {
    pair<long long, int> now = query(L, R, t, m + 1, r, root << 1 | 1);
    if (now.first > ret.first) ret = now;
  }
  return ret;
}
int ans[100010];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    p[i].in();
    p[i].id = i;
  }
  for (int i = 1; i <= m; i++) {
    Q[i].in();
    Q[i].id = i;
  }
  sort(Q + 1, Q + m + 1, cmpask);
  build(1, n, 1);
  for (int i = 1; i <= m; i++) {
    pair<long long, int> ret = query(Q[i].l, Q[i].r, Q[i].t, 1, n, 1);
    ans[Q[i].id] = ret.second;
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
