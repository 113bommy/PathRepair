#include <bits/stdc++.h>
using namespace std;
int n, q;
const int N = (1 << 19) + 2, MOD = 1000000007LL;
struct Query {
  int x, y;
  char typ;
} queries[N];
struct segmentTree {
  int tree[N];
  int lazy[N];
  void push_down(int ni, int ns, int ne) {
    if (ns == ne || !lazy[ni]) return;
    int lf = 2 * ni + 1, rt = lf + 1;
    tree[lf] = max(lazy[ni], tree[lf]);
    tree[rt] = max(lazy[ni], tree[rt]);
    lazy[lf] = max(lazy[ni], lazy[lf]);
    lazy[rt] = max(lazy[ni], lazy[rt]);
    lazy[ni] = 0;
  }
  void update(int qs, int qe, int val, int ni = 0, int ns = 0, int ne = n - 1) {
    if (qs > ne || qe < ns) return;
    push_down(ni, ns, ne);
    if (ns >= qs && ne <= qe) {
      tree[ni] = max(tree[ni], val);
      lazy[ni] = val;
      return;
    }
    int lf = 2 * ni + 1, rt = lf + 1, mid = ns + (ne - ns) / 2;
    update(qs, qe, val, lf, ns, mid);
    update(qs, qe, val, rt, mid + 1, ne);
    tree[ni] = max(tree[lf], tree[rt]);
  }
  int query(int qs, int qe, int ni = 0, int ns = 0, int ne = n - 1) {
    if (qs > ne || qe < ns) return 0;
    push_down(ni, ns, ne);
    if (ns >= qs && ne <= qe) {
      return tree[ni];
    }
    int lf = 2 * ni + 1, rt = lf + 1, mid = ns + (ne - ns) / 2;
    return max(query(qs, qe, lf, ns, mid), query(qs, qe, rt, mid + 1, ne));
  }
};
segmentTree a, b;
int main() {
  scanf("%d%d", &n, &q);
  n = 2e5 + 2;
  vector<int> compo(q * 2);
  int idx = 0;
  for (int i = 0; i < q; i++) {
    scanf("%d%d %c", &queries[i].x, &queries[i].y, &queries[i].typ);
    compo[idx++] = queries[i].x;
    compo[idx++] = queries[i].y;
  }
  sort(compo.begin(), compo.end());
  auto it = unique(compo.begin(), compo.end());
  for (int i = 0; i < q; i++) {
    int X = lower_bound(compo.begin(), it, queries[i].x) - compo.begin();
    int Y = lower_bound(compo.begin(), it, queries[i].y) - compo.begin();
    if (queries[i].typ == 'U') {
      int ans = queries[i].y - a.query(X, X);
      cout << ans << endl;
      int st = lower_bound(compo.begin(), it, a.query(Y, Y)) - compo.begin();
      a.update(X, X, queries[i].y);
      b.update(st, Y, queries[i].x);
    } else {
      int ans = queries[i].x - b.query(Y, Y);
      cout << ans << endl;
      int st = lower_bound(compo.begin(), it, b.query(Y, Y)) - compo.begin();
      a.update(st, X, queries[i].y);
      b.update(Y, Y, queries[i].x);
    }
  }
  return 0;
}
