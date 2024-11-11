#include <bits/stdc++.h>
using namespace std;
const int Maxx = 100005;
inline int read() {
  int res = 0, bj = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') bj |= (ch == '-'), ch = getchar();
  while (ch >= '0' && ch <= '9')
    res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
  return bj ? -res : res;
}
int tot, rt, fa[Maxx], ch[Maxx][2], sz[Maxx];
long long ad[Maxx], dt[Maxx];
inline bool Son(int x) { return ch[fa[x]][1] == x; }
inline void Pr(int x, long long v) {
  if (x) ad[x] += v, dt[x] += v;
}
inline void Pushdown(int x) {
  if (ad[x]) Pr(ch[x][0], ad[x]), Pr(ch[x][1], ad[x]), ad[x] = 0;
}
void All(int x) {
  if (fa[x]) All(fa[x]);
  Pushdown(x);
}
inline void Updata(int x) { sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1; }
inline void Rotate(int x) {
  int f = fa[x], g = fa[f];
  bool bj = Son(x);
  if ((fa[x] = g)) ch[g][Son(f)] = x;
  if ((ch[f][bj] = ch[x][!bj])) fa[ch[f][bj]] = f;
  Updata(ch[fa[f] = x][!bj] = f), Updata(x);
}
inline void Splay(int x, int f = 0) {
  static int y;
  for (All(x); (y = fa[x]) != f; Rotate(x))
    if (fa[y] != f) Rotate(Son(y) == Son(x) ? y : x);
  Updata(x), rt = f ? rt : x;
}
inline void Insert(int x) {
  int p = rt, ls = 0;
  bool bj;
  Pushdown(p);
  while (ch[p][bj = (long long)x * (ls + sz[ch[p][0]] + 1) <= dt[p]])
    bj && (ls += sz[ch[p][0]] + 1), Pushdown(p), p = ch[p][bj];
  Pushdown(p);
  if (bj) ls += sz[ch[p][0]] + 1;
  dt[ch[p][bj] = ++tot] = (long long)x * ls;
  fa[tot] = p, Splay(tot), Pr(ch[tot][1], x);
}
long long nw, Ans;
void Dfs(int x) {
  Pushdown(x);
  if (ch[x][0]) Dfs(ch[x][0]);
  nw += dt[x], Ans = max(Ans, nw);
  if (ch[x][1]) Dfs(ch[x][1]);
}
int main() {
  int n = read();
  dt[tot = rt = 1] = 0, sz[1] = 1;
  for (int i = 1; i <= n; ++i) Insert(read());
  nw = 0, Dfs(rt), cout << Ans << "\n";
  return 0;
}
