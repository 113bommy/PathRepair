#include <bits/stdc++.h>
using namespace std;
struct segment_tree {
  int t[400000];
  int n;
  segment_tree(int n) : n(n) { memset(t, -1, sizeof t); }
  void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
      t[v] = val;
      return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(v * 2, tl, tm, pos, val);
    else
      update(v * 2 + 1, tm + 1, tr, pos, val);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
  void set(int pos, int val) { update(1, 0, n - 1, pos, val); }
  int get(int v, int tl, int tr, int l, int r) {
    if (l > r) return 1e9;
    if (tl == l && tr == r) return t[v];
    int tm = (tl + tr) / 2;
    int res_left = get(v * 2, tl, tm, l, min(tm, r));
    int res_right = get(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
    return min(res_left, res_right);
  }
  int get(int l, int r) { return get(1, 0, n - 1, l, r); }
};
struct query {
  int x;
  int y;
  int lx;
  int ly;
  int id;
  query(int x, int y) : x(x), y(y), lx(-1), ly(-1) {}
  query(int lx, int ly, int rx, int ry, int id)
      : x(rx), y(ry), lx(lx), ly(ly), id(id) {}
  static bool comp_x(const query& a, const query& b) {
    if (a.y != b.y) return a.y < b.y;
    if (a.x != b.x) return a.x < b.x;
    return a.lx < b.lx;
  }
  static bool comp_y(const query& a, const query& b) {
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
    return a.ly < b.ly;
  }
};
vector<query> queries;
int n, m, k, q;
int ans[200000];
void read_input() {
  scanf("%d%d%d%d", &n, &m, &k, &q);
  for (int i = 0; i < k; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    queries.push_back(query(--x, --y));
  }
  for (int i = 0; i < q; i++) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    queries.push_back(query(--x1, --y1, --x2, --y2, i));
  }
}
void write_output() {
  char* output[] = {"NO\n", "YES\n"};
  for (int i = 0; i < q; i++) printf("%s", output[ans[i]]);
}
void solve() {
  read_input();
  segment_tree tree_x(n), tree_y(m);
  sort(queries.begin(), queries.end(), query::comp_x);
  for (auto it = queries.begin(); it != queries.end(); it++) {
    if (it->lx == -1)
      tree_x.set(it->x, it->y);
    else if (tree_x.get(it->lx, it->x) >= it->ly)
      ans[it->id] = 1;
  }
  sort(queries.begin(), queries.end(), query::comp_y);
  for (auto it = queries.begin(); it != queries.end(); it++) {
    if (it->ly >= 0 && ans[it->id]) continue;
    if (it->ly == -1)
      tree_y.set(it->y, it->x);
    else if (tree_y.get(it->ly, it->y) >= it->lx)
      ans[it->id] = 1;
  }
  write_output();
}
int main() {
  solve();
  return 0;
}
