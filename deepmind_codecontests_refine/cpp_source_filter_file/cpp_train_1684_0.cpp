#include <bits/stdc++.h>
using namespace std;
char buf[1 << 21], *p1 = buf, *p2 = buf;
namespace wode {
template <typename T>
inline void read(T &x) {
  static char ch;
  bool f = 1;
  for (x = 0,
      ch = (p1 == p2 &&
                    (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
                ? EOF
                : *p1++);
       !isdigit(ch);
       ch = (p1 == p2 &&
                     (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
                 ? EOF
                 : *p1++))
    if (ch == '-') f = 0;
  for (; isdigit(ch);
       x = (x << 1) + (x << 3) + (ch ^ 48),
       ch = (p1 == p2 &&
                     (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
                 ? EOF
                 : *p1++))
    ;
  x = f ? x : -x;
}
template <typename T>
inline void print(T x, char ch = 0) {
  if (!x) {
    putchar(48);
    if (ch) putchar(ch);
    return;
  }
  if (x < 0) putchar('-'), x = -x;
  static int Stack[sizeof(T) * 3], top = -1;
  for (; x; Stack[++top] = x % 10, x /= 10)
    ;
  for (; ~top; putchar(Stack[top--] + 48))
    ;
  if (ch) putchar(ch);
}
template <typename T>
inline T max(T x, T y) {
  return x < y ? y : x;
}
template <typename T>
inline T min(T x, T y) {
  return x < y ? x : y;
}
template <typename T>
inline void chkmax(T &x, T y) {
  x = x < y ? y : x;
}
template <typename T>
inline void chkmin(T &x, T y) {
  x = x < y ? x : y;
}
}  // namespace wode
using wode::chkmax;
using wode::chkmin;
using wode::print;
using wode::read;
map<pair<int, int>, int> id;
struct node {
  int l, r, id;
  bool operator<(const node &b) const {
    return r < b.r || (r == b.r && l < b.l);
  }
} a[100001];
int x[100001], y[100001], n, m, k, sum, c[300001], tot[100001], pre[300001],
    ans, ver[300001], nxt[300001], head[300001];
inline void modify(int b, int d) {
  for (; b <= sum; c[b] += d, b += ((b) & -(b)))
    ;
}
inline int query(int b) {
  int tot = 0;
  for (; b; tot += c[b], b -= ((b) & -(b)))
    ;
  return tot;
}
inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline void add(int x, int y) {
  ver[++ans] = y, nxt[ans] = head[x], head[x] = ans;
}
int main() {
  read(n);
  for (register int i = 1; i <= n; ++i) {
    read(k);
    for (register int j = 1; j <= k; ++j) read(x[j]), read(y[j]);
    for (register int j = 1; j <= k; ++j) {
      int xx = x[j % k + 1] - x[j], yy = y[j % k + 1] - y[j];
      int gc = abs(gcd(xx, yy));
      xx /= gc, yy /= gc;
      pair<int, int> now = make_pair(xx, yy);
      int &p = id[now];
      if (!p) p = ++sum;
      add(i, p);
    }
  }
  read(m);
  for (register int i = 1; i <= m; ++i) read(a[i].l), read(a[i].r), a[i].id = i;
  sort(a + 1, a + 1 + m);
  int p = 1;
  for (register int i = 1; i <= m; ++i) {
    for (; p <= a[i].r; ++p)
      for (register int j = head[p]; j; j = nxt[j]) {
        if (pre[ver[j]]) modify(pre[ver[j]], -1);
        pre[ver[j]] = p, modify(p, 1);
      }
    tot[a[i].id] = query(a[i].r) - query(a[i].l - 1);
  }
  for (register int i = 1; i <= m; ++i) print(tot[i], '\n');
  return 0;
}
