#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MV = 300008;
const int ME = 1000006;
const int MOD = 1000000007;
struct E {
  int a1, a2, a3, l, r;
};
char str[ME];
struct T {
  E e[ME << 2];
  void push_up(int rt) {
    int t1 = min(e[(rt << 1)].a1, e[(rt << 1 | 1)].a2);
    e[rt].a3 = e[(rt << 1)].a3 + e[(rt << 1 | 1)].a3 + t1;
    e[rt].a1 = e[(rt << 1)].a1 + e[(rt << 1 | 1)].a1 - t1;
    e[rt].a2 = e[(rt << 1 | 1)].a2 + e[(rt << 1 | 1)].a2 - t1;
  }
  void build(int l, int r, int rt) {
    e[rt].l = l;
    e[rt].r = r;
    e[rt].a1 = e[rt].a2 = e[rt].a3 = 0;
    if (l == r) {
      if (str[l - 1] == '(') {
        e[rt].a1 = 1;
      } else
        e[rt].a2 = 1;
      return;
    }
    int mid = (e[rt].l + e[rt].r) >> 1;
    build(l, mid, (rt << 1));
    build(mid + 1, r, (rt << 1 | 1));
    push_up(rt);
  }
  E query(int ul, int ur, int rt) {
    if (ul <= e[rt].l && ur >= e[rt].r) return e[rt];
    int mid = (e[rt].l + e[rt].r) >> 1;
    if (ur <= mid)
      return query(ul, ur, (rt << 1));
    else if (ul > mid)
      return query(ul, ur, (rt << 1 | 1));
    else {
      E e1, e2, ans;
      e1 = query(ul, ur, (rt << 1));
      e2 = query(ul, ur, (rt << 1 | 1));
      int t1 = min(e1.a1, e2.a2);
      ans.a3 = e1.a3 + e2.a3 + t1;
      ans.a1 = e1.a1 + e2.a1 - t1;
      ans.a2 = e1.a2 + e2.a2 - t1;
      return ans;
    }
  }
} tr;
int main() {
  while (~scanf("%s", str)) {
    int n = strlen(str);
    tr.build(1, n, 1);
    int q;
    scanf("%d", &q);
    while (q--) {
      int l, r;
      scanf("%d%d", &l, &r);
      E ans = tr.query(l, r, 1);
      printf("%d\n", (ans.a3) * 2);
    }
  }
  return 0;
}
