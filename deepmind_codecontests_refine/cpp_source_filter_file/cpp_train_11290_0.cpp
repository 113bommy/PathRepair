#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;
int n;
unsigned long long Pow[N];
struct segmentTree {
  struct info1 {
    unsigned long long hs;
    int len;
    info1 operator+(const info1 &rhs) {
      return info1{hs + rhs.hs * Pow[len], len + rhs.len};
    }
  } a[N << 2];
  struct info2 {
    unsigned long long hs;
    int len;
    info2 operator+(const info2 &rhs) {
      return info2{rhs.hs + hs * Pow[rhs.len], len + rhs.len};
    }
  } b[N << 2];
  void build(int l, int r, int rt) {
    if (l == r) {
      a[rt] = info1{0, 1};
      b[rt] = info2{0, 1};
      return;
    }
    int mid = l + r >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    a[rt] = a[rt << 1] + a[rt << 1 | 1];
    b[rt] = b[rt << 1] + b[rt << 1 | 1];
  }
  void update(int p, int l, int r, int rt) {
    if (l == r) {
      a[rt] = info1{1, 1};
      b[rt] = info2{1, 1};
      return;
    }
    int mid = l + r >> 1;
    if (p <= mid)
      update(p, l, mid, rt << 1);
    else
      update(p, mid + 1, r, rt << 1 | 1);
    a[rt] = a[rt << 1] + a[rt << 1 | 1];
    b[rt] = b[rt << 1] + b[rt << 1 | 1];
  }
  info1 querya(int L, int R, int l, int r, int rt) {
    if (l >= L && r <= R) return a[rt];
    int mid = l + r >> 1;
    if (R <= mid)
      return querya(L, R, l, mid, rt << 1);
    else if (L > mid)
      return querya(L, R, mid + 1, r, rt << 1 | 1);
    else
      return querya(L, R, l, mid, rt << 1) +
             querya(L, R, mid + 1, r, rt << 1 | 1);
  }
  info2 queryb(int L, int R, int l, int r, int rt) {
    if (l >= L && r <= R) return b[rt];
    int mid = l + r >> 1;
    if (R <= mid)
      return queryb(L, R, l, mid, rt << 1);
    else if (L > mid)
      return queryb(L, R, mid + 1, r, rt << 1 | 1);
    else
      return queryb(L, R, l, mid, rt << 1) +
             queryb(L, R, mid + 1, r, rt << 1 | 1);
  }
} seg;
int main() {
  for (int i = Pow[0] = 1; i < N; i++) Pow[i] = Pow[i - 1] * 10;
  scanf("%d", &n);
  seg.build(1, n, 1);
  bool flag = false;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    int len = min(x - 1, n - x);
    if (len && seg.querya(x - len, x - 1, 1, n, 1).hs !=
                   seg.queryb(x + 1, x + len, 1, n, 1).hs)
      flag = true;
    seg.update(x, 1, n, 1);
  }
  if (flag)
    puts("YES");
  else
    puts("NO");
  return 0;
}
