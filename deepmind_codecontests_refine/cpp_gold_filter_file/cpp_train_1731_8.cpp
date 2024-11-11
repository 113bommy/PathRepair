#include <bits/stdc++.h>
using namespace std;
namespace IO {
const int maxn(1 << 21 | 1);
char ibuf[maxn], *iS, *iT, c;
int f;
inline char Getc() {
  return iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, maxn, stdin),
                     (iS == iT ? EOF : *iS++))
                  : *iS++;
}
template <class Int>
inline void In(Int &x) {
  for (f = 1, c = Getc(); c < '0' || c > '9'; c = Getc()) f = c == '-' ? -1 : 1;
  for (x = 0; c >= '0' && c <= '9'; c = Getc())
    x = (x << 1) + (x << 3) + (c ^ 48);
  x *= f;
}
}  // namespace IO
using IO ::In;
const int maxn(2e5 + 5);
int n, m, to[2][maxn], w[maxn], fa[maxn], id[maxn], cir[maxn];
long long ans;
inline bool Cmp(int x, int y) { return w[x] > w[y]; }
inline int Find(int x) { return fa[x] == x ? x : fa[x] = Find(fa[x]); }
int main() {
  In(n), In(m);
  for (int i = 1; i <= m; ++i) In(to[0][i]), In(to[1][i]), In(w[i]), id[i] = i;
  sort(id + 1, id + m + 1, Cmp);
  for (int i = 1; i <= n; ++i) fa[i] = i;
  for (int i = 1; i <= m; ++i) {
    int fx = Find(to[0][id[i]]), fy = Find(to[1][id[i]]);
    if (fx != fy && (!cir[fx] || !cir[fy]))
      cir[fx] |= cir[fy], ans += w[id[i]], fa[fy] = fx;
    else if (fx == fy && !cir[fx])
      ans += w[id[i]], cir[fx] = 1;
  }
  printf("%lld\n", ans);
}
