#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
int f[N], ch[N][2], siz[N], sum[N], n, Q, fa[N];
long long s[N], ans;
long long get_s(int rt) { return (long long)siz[rt] * siz[rt]; }
void PushUp(int rt) { siz[rt] = siz[ch[rt][0]] + siz[ch[rt][1]] + sum[rt] + 1; }
void rotate(int rt) {
  int x = f[rt], y = f[x], k = (ch[f[rt]][0] != rt);
  if (!(ch[f[x]][0] != x && ch[f[x]][1] != x)) ch[y][ch[y][0] != x] = rt;
  ch[x][k] = ch[rt][!k], f[ch[x][k]] = x;
  ch[rt][!k] = x, f[x] = rt, f[rt] = y;
  PushUp(x), PushUp(rt);
}
void Splay(int rt) {
  for (; !(ch[f[rt]][0] != rt && ch[f[rt]][1] != rt); rotate(rt))
    if (!(ch[f[f[rt]]][0] != f[rt] && ch[f[f[rt]]][1] != f[rt]))
      rotate((ch[f[rt]][0] != rt) == (ch[f[f[rt]]][0] != f[rt]) ? f[rt] : rt);
}
void access(int rt) {
  for (int t = 0; rt; t = rt, rt = f[rt])
    Splay(rt), sum[rt] += siz[ch[rt][1]], s[rt] += get_s(ch[rt][1]),
        ch[rt][1] = t, sum[rt] -= siz[ch[rt][1]], s[rt] -= get_s(ch[rt][1]),
        PushUp(rt);
}
int find(int rt) {
  access(rt);
  Splay(rt);
  while (ch[rt][0]) rt = ch[rt][0];
  return Splay(rt), rt;
}
void Link(int rt, int x) {
  Splay(rt);
  ans -= get_s(ch[rt][1]) + s[rt], access(rt);
  int y = find(x);
  Splay(y), ans -= get_s(ch[y][1]);
  f[rt] = x;
  Splay(x);
  s[x] += get_s(rt), sum[x] += siz[rt];
  PushUp(x), access(rt), Splay(y);
  ans += get_s(ch[y][1]);
}
void cut(int rt, int x) {
  access(rt), ans += s[rt];
  int y = find(x);
  access(rt);
  Splay(y), ans -= get_s(ch[y][1]);
  Splay(rt);
  f[ch[rt][0]] = 0, ch[rt][0] = 0;
  PushUp(rt);
  Splay(y), ans += get_s(ch[y][1]);
}
struct node {
  int to, next;
} e[N << 1];
int head[N], cnt;
void add(int x, int y) {
  e[cnt] = (node){y, head[x]};
  head[x] = cnt++;
}
void dfs(int x, int from) {
  fa[x] = from;
  for (int i = head[x]; i != -1; i = e[i].next)
    if (e[i].to != from) dfs(e[i].to, x);
}
vector<pair<int, int> > p[N];
int c[N];
long long out[N];
bool used[N];
int main() {
  scanf("%d%d", &n, &Q);
  memset(head, -1, sizeof(head));
  for (int i = 1; i <= n + 1; i++) siz[i] = 1;
  for (int i = 1; i <= n; i++)
    scanf("%d", &c[i]), p[c[i]].push_back(make_pair(i, 0));
  for (int i = 1, x, y; i < n; i++) scanf("%d%d", &x, &y), add(x, y), add(y, x);
  dfs(1, n + 1);
  for (int i = 1, x, y; i <= Q; i++)
    scanf("%d%d", &x, &y), p[c[x]].push_back(make_pair(x, i)),
        c[x] = y, p[c[x]].push_back(make_pair(x, i));
  for (int i = 1; i <= n; i++) Link(i, fa[i]);
  for (int i = 1; i <= n; i++) {
    long long lst = 0;
    if (!p[i].size()) {
      out[0] += (long long)n * n;
      continue;
    }
    if (p[i][0].second)
      out[0] += (long long)n * n, lst = (long long)n * n;
    else
      lst = 0;
    for (int j = 0; j < p[i].size(); j++) {
      int x = p[i][j].first, y = p[i][j].second;
      if (used[x] ^= 1)
        cut(x, fa[x]);
      else
        Link(x, fa[x]);
      if (j == p[i].size() - 1 || y != p[i][j + 1].second)
        out[y] += ans - lst, lst = ans;
    }
    for (int j = p[i].size() - 1, x; ~j; j--)
      if (used[x = p[i][j].first] ^= 1)
        cut(x, fa[x]);
      else
        Link(x, fa[x]);
  }
  ans = (long long)n * n * n;
  for (int i = 0; i <= Q; i++) ans -= out[i], printf("%lld\n", ans);
}
