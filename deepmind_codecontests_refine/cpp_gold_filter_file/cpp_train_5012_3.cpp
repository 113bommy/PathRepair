#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  register int data = 0, fu = 1;
  register char ch = 0;
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') fu = -1, ch = getchar();
  while ('0' <= ch && ch <= '9')
    data = (data << 1) + (data << 3) + (ch ^ 48), ch = getchar();
  return data * fu;
}
int ch[2][400005], fa[400005], sz[400005], cov[400005], col[400005],
    rev[400005], n, m, Q, stk[400005], Ans, nI, bit[400005];
vector<int> edge[400005];
inline void Insert(int x, int v) {
  while (x <= m) bit[x] += v, x += (x & -x);
}
inline int Query(int x) {
  int ret = 0;
  while (x) ret += bit[x], x -= (x & -x);
  return ret;
}
inline bool Son(int x) { return ch[1][fa[x]] == x; }
inline void Reverse(int x) {
  if (!x) return;
  swap(ch[0][x], ch[1][x]);
  rev[x] ^= 1;
}
inline void Cover(int x, int v) {
  if (!x) return;
  cov[x] = v;
  col[x] = v;
}
inline bool Isroot(int x) { return ch[0][fa[x]] != x && ch[1][fa[x]] != x; }
inline void PushUp(int x) { sz[x] = sz[ch[0][x]] + sz[ch[1][x]] + 1; }
inline void PushDown(int x) {
  if (cov[x]) Cover(ch[0][x], cov[x]), Cover(ch[1][x], cov[x]), cov[x] = 0;
  if (rev[x]) Reverse(ch[0][x]), Reverse(ch[1][x]), rev[x] ^= 1;
}
inline void Rot(int x) {
  int y = fa[x], z = fa[y], c = Son(x);
  if (!Isroot(y)) ch[Son(y)][z] = x;
  fa[x] = z;
  fa[ch[c][y] = ch[!c][x]] = y;
  fa[ch[!c][x] = y] = x;
  PushUp(y);
}
inline void Splay(int x) {
  stk[stk[0] = 1] = x;
  for (int y = x; !Isroot(y); y = fa[y]) stk[++stk[0]] = fa[y];
  while (stk[0]) PushDown(stk[stk[0]--]);
  for (int y = fa[x]; !Isroot(x); Rot(x), y = fa[x])
    if (!Isroot(y)) Son(x) ^ Son(y) ? Rot(x) : Rot(y);
  PushUp(x);
}
inline void Access(int x) {
  for (int y = 0; x; y = x, x = fa[x]) {
    Splay(x);
    Insert(col[x], -sz[ch[0][x]] - 1);
    ch[1][x] = y;
    PushUp(x);
  }
  return;
}
inline void MakeRoot(int x) {
  ++nI;
  Access(x);
  Splay(x);
  Cover(x, nI);
  Insert(nI, sz[x]);
  Reverse(x);
}
inline int GetAns(int x) {
  Splay(x);
  return sz[ch[1][x]] + 1 + Query(col[x] - 1);
}
void dfs(int u, int From) {
  for (auto v : edge[u])
    if (v != From) dfs(v, u), fa[v] = u;
}
int main() {
  n = gi();
  Q = gi();
  m = n + Q + 2;
  ++nI;
  Insert(nI, n);
  for (int i = 1; i <= n; i++) sz[i] = 1, col[i] = 1;
  for (int i = 1, u, v; i < n; i++)
    u = gi(), v = gi(), edge[u].push_back(v), edge[v].push_back(u);
  dfs(1, 0);
  for (int i = 2; i <= n; i++) MakeRoot(i);
  char op[10];
  int u, v;
  while (Q--) {
    scanf("%s", op);
    if (op[0] == 'u')
      v = gi(), MakeRoot(v);
    else if (op[0] == 'w')
      v = gi(), printf("%d\n", GetAns(v));
    else if (op[0] == 'c')
      u = gi(), v = gi(), printf("%d\n", GetAns(u) < GetAns(v) ? u : v);
  }
  return 0;
}
