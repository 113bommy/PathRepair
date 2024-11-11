#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
set<int> y[N];
struct Query {
  int op, x, y;
} q[N];
int has[N], tot, mx[N << 2];
void pushup(int id) { mx[id] = max(mx[id << 1], mx[id << 1 | 1]); }
void update(int id, int l, int r, int pos, int val, int op) {
  if (l == r) {
    if (!op)
      y[l].insert(val);
    else
      y[l].erase(val);
    if (y[l].size() == 0)
      mx[id] = -1;
    else
      mx[id] = (*(--y[l].end()));
    return;
  }
  int mid = l + r >> 1;
  if (pos <= mid)
    update(id << 1, l, mid, pos, val, op);
  else
    update(id << 1 | 1, mid + 1, r, pos, val, op);
  pushup(id);
}
pair<int, int> query(int id, int l, int r, int L, int R, int val) {
  if (L <= l && R >= r) {
    if (mx[id] <= val) return make_pair(-1, -1);
  }
  if (l == r) {
    auto w = y[l].upper_bound(val);
    if (w == y[l].end())
      return make_pair(-1, -1);
    else
      return make_pair(l, *w);
  }
  int mid = l + r >> 1;
  pair<int, int> ret = make_pair(-1, -1);
  if (L <= mid) ret = query(id << 1, l, mid, L, R, val);
  if (ret.first != -1) return ret;
  if (R > mid) ret = query(id << 1 | 1, mid + 1, r, L, R, val);
  return ret;
}
int main() {
  int n;
  scanf("%d", &n);
  memset(mx, -1, sizeof(mx));
  char str[10];
  for (int i = 1; i <= n; i++) {
    scanf("%s%d%d", str, &q[i].x, &q[i].y);
    if (str[0] == 'a')
      q[i].op = 0;
    else if (str[0] == 'r')
      q[i].op = 1;
    else
      q[i].op = 2;
    has[++tot] = q[i].x;
  }
  sort(has + 1, has + 1 + tot);
  tot = unique(has + 1, has + 1 + tot) - has - 1;
  for (int i = 1; i <= n; i++) {
    int pos = upper_bound(has + 1, has + 1 + tot, q[i].x) - has;
    if (q[i].op <= 1)
      update(1, 1, tot, pos, q[i].y, q[i].op);
    else {
      if (pos > tot) {
        puts("-1");
        continue;
      }
      pair<int, int> ans = query(1, 1, tot, pos, tot, q[i].y);
      if (ans.first == -1) {
        puts("-1");
      } else {
        printf("%d %d\n", has[ans.first], ans.second);
      }
    }
  }
  return 0;
}
