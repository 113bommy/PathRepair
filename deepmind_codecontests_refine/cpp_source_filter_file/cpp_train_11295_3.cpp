#include <bits/stdc++.h>
namespace shit {
const int N = 5010, M = 101000;
struct node {
  int val;
  node *lt, *rt;
  node() { val = 0, lt = rt = NULL; }
  void cklt() {
    if (!lt) lt = new node;
  }
  void ckrt() {
    if (!rt) rt = new node;
  }
  void upd() { val = (lt ? lt->val : 0) + (rt ? rt->val : 0); }
  void modify(int x, int y, int L = -N, int R = N * 2) {
    val += y;
    if (L == R) return;
    if (x <= ((L + R) >> 1))
      cklt(), lt->modify(x, y, L, ((L + R) >> 1));
    else
      ckrt(), rt->modify(x, y, ((L + R) >> 1) + 1, R);
  }
  int query(int lim, int L = -N, int R = N * 2) {
    if (R <= lim) return val;
    if (L > lim) return 0;
    return (lt ? lt->query(lim, L, ((L + R) >> 1)) : 0) +
           (rt ? rt->query(lim, ((L + R) >> 1) + 1, R) : 0);
  }
};
struct Bit {
  node s[N];
  int lowbit(int x) { return x & (-x); }
  void modify(int y, int x, int z) {
    for (; x < N; x += lowbit(x)) s[x].modify(y, z);
  }
  int query(int y, int x) {
    int ret = 0;
    for (; x; x -= lowbit(x)) ret += s[x].query(y);
    return ret;
  }
} T0, T1, T2;
int n, Q;
void proc1(int x, int y, int len) {
  T0.modify(x, y, 1);
  T1.modify(x + len + (y), y, -1);
  T1.modify(x - 1 + (y + len + 1), y + len + 1, 1);
  T0.modify(x, y + len + 1, -1);
}
void proc2(int x, int y, int len) {
  T0.modify(x, y - len + 1, 1);
  T2.modify(x + 1 - (y - len + 1), y - len + 1, -1);
  T0.modify(x, y + 1, -1);
  T2.modify(x + len + 1 - (y + 1), y + 1, 1);
}
void proc3(int x, int y, int len) {
  T2.modify(x - len + 1 - (y), y, 1);
  T0.modify(x + 1, y, -1);
  T0.modify(x + 1, y + len + 1, 1);
  T2.modify(x + 2 - (y + len + 1), y + len + 1, -1);
}
void proc4(int x, int y, int len) {
  T1.modify(x + (y - len + 1), y - len + 1, 1);
  T1.modify(x - len - (y + 1), y + 1, -1);
  T0.modify(x + 1, y - len + 1, -1);
  T0.modify(x + 1, y + 1, 1);
}
void test() {
  proc4(5, 5, 4);
  for (int y = 10; y; y--, printf("\n"))
    for (int x = 1; x <= 10; x++)
      printf("%d", T0.query(x, y) + T1.query(x + y, y) + T2.query(x - y, y));
}
void solve() {
  scanf("%d%d", &n, &Q);
  int ty, dir, x, y, len;
  while (Q--) {
    scanf("%d", &ty);
    if (ty == 1) {
      scanf("%d%d%d%d", &dir, &x, &y, &len), len++;
      if (dir == 1)
        proc1(x, y, len);
      else if (dir == 2)
        proc2(x, y, len);
      else if (dir == 3)
        proc3(x, y, len);
      else
        proc4(x, y, len);
    } else {
      scanf("%d%d", &x, &y);
      printf("%d\n", T0.query(x, y) + T1.query(x + y, y) + T2.query(x - y, y));
    }
  }
}
}  // namespace shit
int main() {
  shit::solve();
  return 0;
}
