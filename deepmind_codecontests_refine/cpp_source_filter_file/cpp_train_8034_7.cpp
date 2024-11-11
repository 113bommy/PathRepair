#include <bits/stdc++.h>
const int N = 2e5 + 10;
const int mod = 998244353;
using namespace std;
pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
  if (a.first < b.first) {
    if (a.second > b.first) a.second = b.first;
    return a;
  } else {
    if (b.second > a.first) b.second = a.first;
    return b;
  }
}
struct Seg {
  static const int N = ::N << 2;
  pair<int, int> mi[N], ans;
  void init(int n) {
    for (int i = n << 2 | 1; i >= 0; --i) mi[i] = {0x3f3f3f3f, 0x3f3f3f3f};
  }
  void Query(int L, int R, int l, int r, int rt) {
    if (L <= l && R >= r) {
      ans = mi[rt] + ans;
      return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid) Query(L, R, l, mid, rt << 1);
    if (R > mid) Query(L, R, mid + 1, r, rt << 1 | 1);
  }
  pair<int, int> query(int L, int R, int l, int r, int rt) {
    ans = {0x3f3f3f3f, 0x3f3f3f3f};
    Query(L, R, l, r, rt);
    return ans;
  }
  void update(int p, int val, int l, int r, int rt) {
    if (l == r) {
      mi[rt] = {val, 0x3f3f3f3f};
      return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid)
      update(p, val, l, mid, rt << 1);
    else
      update(p, val, mid + 1, r, rt << 1 | 1);
    mi[rt] = mi[rt << 1] + mi[rt << 1 | 1];
  }
} seg[9];
int n, m;
void update(int p, int x) {
  for (int i = 0, k = x; k > 0; ++i, k /= 10) {
    if (k % 10)
      seg[i].update(p, x, 1, n, 1);
    else
      seg[i].update(p, 0x3f3f3f3f, 1, n, 1);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < 9; ++i) seg[i].init(n);
  for (int i = 1, x; i <= n; ++i) scanf("%d", &x), update(i, x);
  while (m--) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1)
      update(x, y);
    else {
      int ans = 0x3f3f3f3f + 0x3f3f3f3f;
      for (int i = 0; i < 9; ++i) {
        pair<int, int> p = seg[i].query(x, y, 1, n, 1);
        if (p.first != 0x3f3f3f3f && p.second != 0x3f3f3f3f)
          ans = min(ans, p.first + p.second);
      }
      if (ans != 0x3f3f3f3f + 0x3f3f3f3f)
        printf("%d\n", ans);
      else
        puts("-1");
    }
  }
  return 0;
}
