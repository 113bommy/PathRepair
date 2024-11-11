#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int inf = 0x3f3f3f3f;
struct Node {
  int x, c;
  bool operator<(const Node& A) const { return x < A.x; }
} e1[N], e2[N];
struct Node2 {
  int x, y, c;
  bool operator<(const Node2& A) const { return x < A.x; }
} e3[N];
int Max[N << 2], lazy[N << 2], l[N << 2], r[N << 2];
void pushup(int rt) { Max[rt] = max(Max[rt << 1], Max[rt << 1 | 1]); }
void pushdown(int rt) {
  if (!lazy[rt]) return;
  lazy[rt << 1] += lazy[rt];
  lazy[rt << 1 | 1] += lazy[rt];
  Max[rt << 1] += lazy[rt];
  Max[rt << 1 | 1] += lazy[rt];
  lazy[rt] = 0;
}
void build(int L, int R, int rt) {
  l[rt] = L;
  r[rt] = R;
  if (L == R) return;
  int mid = (L + R) >> 1;
  build(L, mid, rt << 1);
  build(mid + 1, R, rt << 1 | 1);
  pushup(rt);
}
void update(int L, int R, int rt, int x) {
  if (L > r[rt] || l[rt] > R) return;
  if (L <= l[rt] && r[rt] <= R) {
    lazy[rt] += x;
    Max[rt] += x;
    return;
  }
  pushdown(rt);
  update(L, R, rt << 1, x);
  update(L, R, rt << 1 | 1, x);
  pushup(rt);
}
int query(int L, int R, int rt) {
  if (L > r[rt] || l[rt] > R) return -inf;
  if (L <= l[rt] && r[rt] <= R) return Max[rt];
  pushdown(rt);
  return max(query(L, R, rt << 1), query(L, R, rt << 1 | 1));
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m, p;
  cin >> n >> m >> p;
  for (int i = 1; i <= n; i++) cin >> e1[i].x >> e1[i].c;
  for (int i = 1; i <= m; i++) cin >> e2[i].x >> e2[i].c;
  for (int i = 1; i <= p; i++) cin >> e3[i].x >> e3[i].y >> e3[i].c;
  sort(e1 + 1, e1 + n + 1), sort(e2 + 1, e2 + 1 + m), sort(e3 + 1, e3 + 1 + p);
  build(1, m, 1);
  for (int i = 1; i <= m; i++) update(i, i, 1, -e2[i].c);
  int pos = 1, ans = -inf;
  for (int i = 1; i <= n; i++) {
    while (pos <= p && e3[pos].x < e1[i].x) {
      int po = upper_bound(e2 + 1, e2 + 1 + m, Node{e3[pos].y}) - e2;
      update(po, m, 1, e3[pos].c);
      pos++;
    }
    ans = max(ans, query(1, m, 1) - e1[i].c);
  }
  cout << ans << endl;
  return 0;
}
