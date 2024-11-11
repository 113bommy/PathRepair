#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct edge {
  int to, next;
} e[N * 2];
int head[N], tot, n;
int a[N], b[N], aa[N];
int dfn[N], ed[N], dep[N];
int fa[N][19], A[N], B[N];
int pos1, pos2, cnt;
void add(int x, int y) {
  e[++tot] = (edge){y, head[x]};
  head[x] = tot;
}
bool dfs(int x, int fa, int ed) {
  if (x == ed) return 1;
  for (int i = head[x]; i; i = e[i].next)
    if (e[i].to != fa)
      if (dfs(e[i].to, x, ed)) {
        ++cnt;
        swap(aa[e[i].to], aa[x]);
        return 1;
      }
  return 0;
}
void walk(int x, int y) { dfs(y, 0, x); }
bool OJBK() {
  for (int i = (int)(1); i <= (int)(n); i++)
    if (aa[i] != b[i]) return 0;
  return 1;
}
void dfs(int x) {
  dfn[x] = ++*dfn;
  for (int i = (int)(1); i <= (int)(17); i++)
    fa[x][i] = fa[fa[x][i - 1]][i - 1];
  for (int i = head[x]; i; i = e[i].next)
    if (e[i].to != fa[x][0]) {
      fa[e[i].to][0] = x;
      dep[e[i].to] = dep[x] + 1;
      dfs(e[i].to);
    }
  ed[x] = *dfn;
}
bool isfa(int x, int y) { return dfn[x] <= dfn[y] && ed[y] <= ed[x]; }
int LCA(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  int tmp = dep[x] - dep[y];
  for (int i = (int)(0); i <= (int)(17); i++)
    if (tmp & (1 << i)) x = fa[x][i];
  for (int i = (int)(17); i >= (int)(0); i--)
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  return x == y ? x : fa[x][0];
}
pair<int, int> merge(pair<int, int> x, int y) {
  if (!x.first) return pair<int, int>(y, y);
  int c[3];
  c[0] = x.first;
  c[1] = x.second;
  c[2] = y;
  int L = LCA(c[0], c[1]);
  if (isfa(L, c[2]) && (isfa(c[2], c[0]) || isfa(c[2], c[1])))
    return pair<int, int>(c[0], c[1]);
  L = LCA(c[0], c[2]);
  if (isfa(L, c[1]) && (isfa(c[1], c[0]) || isfa(c[1], c[2])))
    return pair<int, int>(c[0], c[2]);
  L = LCA(c[1], c[2]);
  if (isfa(L, c[0]) && (isfa(c[0], c[1]) || isfa(c[0], c[2])))
    return pair<int, int>(c[1], c[2]);
  puts("-1");
  exit(0);
}
long long solve(int x, int y) {
  int L = LCA(x, y);
  int l = 1, r = dep[x] + dep[y] - 2 * dep[L], len = r, at = l;
  for (; x != L; x = fa[x][0], ++l) A[l] = aa[x], B[l] = b[x];
  for (; y != L; y = fa[y][0], --r) A[r] = aa[y], B[r] = b[y];
  for (; A[1] != B[at]; ++at)
    ;
  for (int i = (int)(1); i <= (int)(len); i++)
    if (A[i] != B[(i + at - 2) % len + 1]) return 1ll << 55;
  return 1ll * min(at - 1, len + 1 - at) * (len + 1);
}
int main() {
  scanf("%d", &n);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", &a[i]);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", &b[i]);
  for (int i = (int)(1); i <= (int)(n); i++)
    if (!a[i]) pos1 = i;
  for (int i = (int)(1); i <= (int)(n); i++)
    if (!b[i]) pos2 = i;
  for (int i = (int)(1); i <= (int)(n - 1); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
  }
  dfs(pos2);
  memcpy(aa, a, sizeof(aa));
  walk(pos1, pos2);
  if (OJBK()) {
    printf("0 %d\n", cnt);
    return 0;
  }
  pair<int, int> tmp(0, 0);
  for (int i = (int)(1); i <= (int)(n); i++)
    if (aa[i] != b[i]) tmp = merge(tmp, i);
  if (dep[tmp.first] > dep[tmp.second]) swap(tmp.first, tmp.second);
  if (isfa(tmp.first, tmp.second)) tmp.first = fa[tmp.first][0];
  long long ans = 1ll << 60;
  cnt = 0;
  memcpy(aa, a, sizeof(aa));
  walk(pos1, tmp.first);
  swap(aa[tmp.first], aa[tmp.second]), ++cnt;
  walk(tmp.second, pos2);
  ans = min(ans, cnt + solve(tmp.first, tmp.second));
  cnt = 0;
  memcpy(aa, a, sizeof(aa));
  walk(pos1, tmp.second);
  swap(aa[tmp.second], aa[tmp.first]), ++cnt;
  walk(tmp.first, pos2);
  ans = min(ans, cnt + solve(tmp.first, tmp.second));
  if (ans > 1ll << 50)
    puts("-1");
  else {
    if (tmp.first > tmp.second) swap(tmp.first, tmp.second);
    printf("%d %d %lld\n", tmp.first, tmp.second, ans);
  }
}
