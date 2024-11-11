#include <bits/stdc++.h>
using namespace std;
int h, w, n;
int ans[400005];
struct mem {
  int u, l, r, s;
} q[400005];
struct event {
  int id, op, height;
} e[400005];
struct node {
  int h, id;
  bool operator<(const node t) const { return h > t.h; }
} qans;
set<node> s[400005];
void modify(int x, int L, int R, int qL, int qR, int tp, node B) {
  if (qL <= L && R <= qR) {
    if (tp == 0)
      s[x].erase(B);
    else
      s[x].insert(B);
    return;
  }
  int mid = (L + R) / 2;
  if (qL <= mid) modify(x * 2, L, mid, qL, qR, tp, B);
  if (mid < qR) modify(x * 2 + 1, mid + 1, R, qL, qR, tp, B);
}
void get(int x, int loc, int L, int R) {
  if (!s[x].empty()) {
    node tmp = *s[x].begin();
    if (tmp < qans) qans = tmp;
  }
  if (L == R) return;
  int mid = (L + R) / 2;
  if (loc <= mid)
    get(x * 2, loc, L, mid);
  else
    get(x * 2 + 1, loc, mid + 1, R);
}
int query(int loc) {
  qans.id = -1;
  qans.h = -1;
  get(1, loc, 1, w);
  if (qans.id == -1) return 1;
  return ans[qans.id];
}
bool cmp(event A, event B) {
  if (A.height == B.height) return A.op < B.op;
  return A.height <= B.height;
}
int main() {
  scanf("%d %d %d", &h, &w, &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d %d", &q[i].u, &q[i].l, &q[i].r, &q[i].s);
    e[i].id = i;
    e[i].op = 1;
    e[i].height = q[i].u;
    e[i + n].id = i;
    e[i + n].op = -1;
    e[i + n].height = q[i].u + q[i].s + 1;
  }
  sort(e + 1, e + n + n + 1, cmp);
  for (int i = 1; i <= 2 * n; i++) {
    if (e[i].height > h + 1) break;
    if (e[i].op == -1) {
      node B;
      B.h = q[e[i].id].u;
      B.id = e[i].id;
      modify(1, 1, w, q[e[i].id].l, q[e[i].id].r, 0, B);
    } else {
      mem A = q[e[i].id];
      if (A.l == 1)
        ans[e[i].id] = (long long)query((A.r + 1)) * 2 % 1000000007;
      else if (A.r == w)
        ans[e[i].id] = (long long)query(A.l - 1) * 2 % 1000000007;
      else {
        ans[e[i].id] = ((long long)query(A.l - 1) + (long long)query(A.r + 1)) %
                       1000000007;
      }
      node B;
      B.h = q[e[i].id].u;
      B.id = e[i].id;
      modify(1, 1, w, q[e[i].id].l, q[e[i].id].r, 1, B);
    }
  }
  int ret = 0;
  for (int i = 1; i <= w; i++) {
    int ww = query(i);
    ret = ((long long)ret + ww) % 1000000007;
  }
  printf("%d\n", ret);
  return 0;
}
