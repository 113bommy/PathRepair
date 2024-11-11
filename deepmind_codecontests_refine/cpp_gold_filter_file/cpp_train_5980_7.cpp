#include <bits/stdc++.h>
const int N = 2e5 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-9;
using namespace std;
namespace fast_IO {
long long read() {
  long long x = 0;
  char c;
  bool flag = false;
  while ((c = getchar()) == ' ' || c == '\n' || c == '\r')
    ;
  if (c == '-')
    flag = true;
  else
    x = c ^ 48;
  while ((c = getchar()) >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48);
  if (flag) return -x;
  return x;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 ^ 48);
}
}  // namespace fast_IO
char s[2][N];
struct Dist {
  long long d1, d2, d3, d4;
  Dist() {}
  Dist(int d1, int d2, int d3, int d4) : d1(d1), d2(d2), d3(d3), d4(d4) {}
};
struct Node {
  int l, r;
  Dist d;
} tree[N << 2];
void pushup(int x) {
  tree[x].d.d1 = min(tree[x << 1].d.d1 + tree[x << 1 | 1].d.d1,
                     tree[x << 1].d.d2 + tree[x << 1 | 1].d.d3) +
                 1;
  tree[x].d.d2 = min(tree[x << 1].d.d1 + tree[x << 1 | 1].d.d2,
                     tree[x << 1].d.d2 + tree[x << 1 | 1].d.d4) +
                 1;
  tree[x].d.d3 = min(tree[x << 1].d.d3 + tree[x << 1 | 1].d.d1,
                     tree[x << 1].d.d4 + tree[x << 1 | 1].d.d3) +
                 1;
  tree[x].d.d4 = min(tree[x << 1].d.d4 + tree[x << 1 | 1].d.d4,
                     tree[x << 1].d.d3 + tree[x << 1 | 1].d.d2) +
                 1;
}
void build(int x, int l, int r) {
  tree[x].l = l, tree[x].r = r;
  if (l == r) {
    if (s[0][l] != 'X')
      tree[x].d.d1 = 0;
    else
      tree[x].d.d1 = INF;
    if (s[1][l] != 'X')
      tree[x].d.d4 = 0;
    else
      tree[x].d.d4 = INF;
    if (s[0][l] != 'X' && s[1][l] != 'X')
      tree[x].d.d2 = tree[x].d.d3 = 1;
    else
      tree[x].d.d2 = tree[x].d.d3 = INF;
    return;
  }
  int mid = l + r >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  pushup(x);
}
Dist query(int x, int l, int r) {
  if (tree[x].l == l && tree[x].r == r) return tree[x].d;
  int mid = tree[x].l + tree[x].r >> 1;
  if (r <= mid) return query(x << 1, l, r);
  if (l > mid) return query(x << 1 | 1, l, r);
  Dist le = query(x << 1, l, mid), ri = query(x << 1 | 1, mid + 1, r);
  Dist ans;
  ans.d1 = min(le.d1 + ri.d1, le.d2 + ri.d3) + 1;
  ans.d2 = min(le.d1 + ri.d2, le.d2 + ri.d4) + 1;
  ans.d3 = min(le.d3 + ri.d1, le.d4 + ri.d3) + 1;
  ans.d4 = min(le.d4 + ri.d4, le.d3 + ri.d2) + 1;
  return ans;
}
int main() {
  int n = fast_IO::read(), m = fast_IO::read();
  scanf("%s%s", s[0] + 1, s[1] + 1);
  build(1, 1, n);
  while (m--) {
    int x = fast_IO::read(), y = fast_IO::read();
    if ((x > n ? x - n : x) > (y > n ? y - n : y)) swap(x, y);
    int dx = x > n, dy = y > n;
    long long ans;
    if (!dx && !dy)
      ans = query(1, x, y).d1;
    else if (!dx && dy)
      ans = query(1, x, y - n).d2;
    else if (dx && !dy)
      ans = query(1, x - n, y).d3;
    else
      ans = query(1, x - n, y - n).d4;
    if (ans > INF)
      puts("-1");
    else
      printf("%lld\n", ans);
  }
  return 0;
}
