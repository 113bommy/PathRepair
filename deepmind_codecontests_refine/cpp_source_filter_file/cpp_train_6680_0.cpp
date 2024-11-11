#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
const int M = 6000005;
pair<int, int> pts[N];
int tree[M << 2], lazy[M << 2];
inline void push(int v, int s, int e) {
  if (lazy[v]) {
    tree[v] += lazy[v];
    if (s != e) {
      lazy[2 * v] += lazy[v];
      lazy[2 * v + 1] += lazy[v];
    }
    lazy[v] = 0;
  }
}
void update(int v, int s, int e, int l, int r, int xx) {
  if (l <= s && e <= r) {
    lazy[v] += xx;
    push(v, s, e);
    return;
  }
  push(v, s, e);
  if (e < l || r < s || r < l) return;
  int m = (s + e) >> 1;
  int v1 = v << 1;
  int v2 = v1 | 1;
  update(v1, s, m, l, r, xx);
  update(v2, m + 1, e, l, r, xx);
  tree[v] = max(tree[v1], tree[v2]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, r;
  cin >> n >> r;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    int nx = x + y;
    int ny = x - y;
    nx += 3000000;
    ny += 3000000;
    pts[i] = {nx, ny};
  }
  int r2 = r << 1;
  sort(pts, pts + n);
  memset(tree, 0, sizeof(tree));
  memset(lazy, 0, sizeof(lazy));
  int ans = 0;
  for (int i = 0, j = -1; i < n; i++) {
    while (j + 1 < n && pts[j].first <= pts[i].first + r2) {
      ++j;
      update(1, 0, M, pts[j].second - r, pts[j].second + r, 1);
    }
    ans = max(ans, tree[1]);
    update(1, 0, M, pts[i].second - r, pts[i].second + r, -1);
  }
  cout << ans << '\n';
  return 0;
}
