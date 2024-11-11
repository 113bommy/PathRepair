#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int sum[MAXN << 2], a[MAXN];
struct node {
  int val, pos;
  node() {}
  node(int _val, int _pos) : val(_val), pos(_pos) {}
  bool operator<(const node &a) const {
    if (val == a.val) return pos > a.pos;
    return val > a.val;
  }
};
priority_queue<node> Q;
void push_up(int rt) { sum[rt] = sum[rt << 1] + sum[rt << 1 | 1]; }
void build(int l, int r, int rt) {
  if (l == r) {
    sum[rt] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, rt << 1);
  build(mid + 1, r, rt << 1 | 1);
  push_up(rt);
}
void update(int pos, int val, int l, int r, int rt) {
  if (l == r) {
    sum[rt] = val;
    return;
  }
  int mid = (l + r) >> 1;
  if (mid >= pos) {
    update(pos, val, l, mid, rt << 1);
  }
  if (mid < pos) {
    update(pos, val, mid + 1, r, rt << 1 | 1);
  }
  push_up(rt);
}
int query(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) {
    return sum[rt];
  }
  int mid = (l + r) >> 1;
  int ret = 0;
  if (L <= mid) {
    ret += query(L, R, l, mid, rt << 1);
  }
  if (mid < R) {
    ret += query(L, R, mid + 1, r, rt << 1 | 1);
  }
  return ret;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    Q.push(node(a[i], i));
  }
  build(0, n - 1, 1);
  int now = 0;
  long long ans = 0;
  while (!Q.empty()) {
    node top = Q.top();
    Q.pop();
    if (now > top.pos) {
      top.pos += n;
      Q.push(top);
      continue;
    }
    top.pos %= n;
    if (now <= top.pos)
      ans += query(now, top.pos, 0, n - 1, 1);
    else
      ans += query(0, top.pos, 0, n - 1, 1) + query(now, n - 1, 0, n - 1, 1);
    update(top.pos, 0, 0, n - 1, 1);
    now = top.pos;
    now %= n;
  }
  printf("%lld\n", ans);
  return 0;
}
