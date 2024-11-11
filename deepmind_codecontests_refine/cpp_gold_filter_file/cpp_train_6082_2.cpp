#include <bits/stdc++.h>
using namespace std;
const int N = 7e3 + 10;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
int n, m, l[N], r[N];
struct Query {
  int t, d, l, r, val;
} a[N];
map<int, int> Map;
namespace FastIO {
template <typename tp>
inline void read(tp &x) {
  x = 0;
  register char c = getchar();
  register bool f = 0;
  for (; c < '0' || c > '9'; f |= (c == '-'), c = getchar())
    ;
  for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar())
    ;
  if (f) x = -x;
}
template <typename tp>
inline void write(tp x) {
  if (x == 0) return (void)(putchar('0'));
  if (x < 0) putchar('-'), x = -x;
  int pr[20];
  register int cnt = 0;
  for (; x; x /= 10) pr[++cnt] = x % 10;
  while (cnt) putchar(pr[cnt--] + '0');
}
template <typename tp>
inline void writeln(tp x) {
  write(x);
  putchar('\n');
}
}  // namespace FastIO
using namespace FastIO;
void Solve(int x) {
  memset(l, 0, sizeof(int) * (n + 1));
  memset(r, 0, sizeof(int) * (n + 1));
  int u = 1, v = 1, d1 = 1, d2 = 1;
  while ((u << 1) <= a[x].l - 1) u <<= 1, d1++;
  while ((v << 1) <= a[x].l) v <<= 1, d2++;
  if (a[x].l == 1) d1 = 0;
  int lt = a[x].l - 1, rt = a[x].l;
  for (int i = a[x].d; i <= n; i++) {
    l[i] = lt + 1;
    r[i] = rt;
    lt += d1;
    rt += d2;
    if (lt >= (u << 1)) u <<= 1, d1++;
    if (rt >= (v << 1)) v <<= 1, d2++;
  }
  int ans = 0;
  map<int, int>().swap(Map);
  for (int i = 1; i < x; i++)
    if (a[i].t == 1 && a[i].d >= a[x].d) {
      int d = a[i].d, t = a[i].val;
      if (Map[t]) continue;
      if (l[d] <= a[i].l && a[i].l <= r[d])
        Map[t] = 1, ans++;
      else if (r[d] >= a[i].r && a[i].r >= l[d])
        Map[t] = 1, ans++;
      else if (l[d] <= a[i].l && r[d] >= a[i].r)
        Map[t] = 1, ans++;
      else if (l[d] >= a[i].l && r[d] <= a[i].r)
        Map[t] = 1, ans++;
    }
  writeln(ans);
}
int main() {
  read(n);
  read(m);
  for (int i = 1; i <= m; i++) {
    read(a[i].t);
    if (a[i].t == 1) {
      read(a[i].d);
      read(a[i].l);
      read(a[i].r);
      read(a[i].val);
    }
    if (a[i].t == 2) {
      read(a[i].d);
      read(a[i].l);
      Solve(i);
    }
  }
  return 0;
}
