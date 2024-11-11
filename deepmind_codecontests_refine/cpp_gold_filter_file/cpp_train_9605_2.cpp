#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && (c != '-')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
const int N = 1e5 + 10;
int n;
long long k;
vector<int> e[N];
inline void GG() {
  puts("NO");
  exit(0);
}
int rt, L, siz[N], mx[N];
long long R;
inline void dfs(int u, int fa) {
  siz[u] = 1;
  for (auto v : e[u])
    if (v != fa) {
      dfs(v, u), siz[u] += siz[v], mx[u] = max(mx[u], siz[v]);
    }
  mx[u] = max(mx[u], n - siz[u]);
  L += (siz[u] & 1), R += min(siz[u], n - siz[u]);
  if (mx[u] < mx[rt]) rt = u;
}
int fa[N], Rt[N], dep[N], deg[N];
multiset<pair<int, int> > s[N];
multiset<pair<int, int> > S;
inline void Dfs(int u, int fa, int rt) {
  Rt[u] = rt;
  ::fa[u] = fa, dep[u] = dep[fa] + 1, siz[u] = 1, deg[u] = 0;
  for (auto v : e[u])
    if (v != fa) Dfs(v, u, rt), siz[u] += siz[v], ++deg[u];
  if (deg[u] >= 1) s[rt].insert(make_pair(dep[u], u));
}
bool vis[N];
int cnt, p[N];
vector<int> vec[N];
inline void Dfs2(int u, int fa, int k) {
  if (!vis[u]) vec[k].push_back(u);
  for (auto v : e[u])
    if (v != fa) Dfs2(v, u, k);
}
inline void solve() {
  for (auto v : e[rt]) ++cnt, p[cnt] = cnt, Dfs2(v, rt, cnt);
  vec[++cnt].push_back(rt), p[cnt] = cnt;
  sort(p + 1, p + 1 + cnt, [](int a, int b) {
    return ((int)(vec[a]).size()) > ((int)(vec[b]).size());
  });
  int x = ((int)(vec[p[1]]).size()), y = 0;
  for (register int i = (2); i <= (cnt); i++) y += ((int)(vec[p[i]]).size());
  int l = 2, r = cnt;
  while (vec[p[r]].empty()) --r;
  while (y > x) {
    printf("%d %d\n", vec[p[l]].back(), vec[p[r]].back());
    vec[p[l]].pop_back(), vec[p[r]].pop_back();
    y -= 2;
    if (vec[p[l]].empty()) ++l;
    if (vec[p[r]].empty()) --r;
  }
  for (auto i : vec[p[1]]) {
    printf("%d %d\n", i, vec[p[l]].back());
    vec[p[l]].pop_back();
    if (vec[p[l]].empty()) ++l;
  }
}
int main() {
  n = read(), k = read();
  for (register int i = (1); i < (n); i++) {
    int x = read(), y = read();
    e[x].push_back(y), e[y].push_back(x);
  }
  mx[0] = 1e9, dfs(1, 0);
  if (k < L || k > R || k % 2 != L % 2) GG();
  puts("YES");
  if (k == R) return solve(), 0;
  for (auto v : e[rt]) Dfs(v, rt, v), S.insert(make_pair(siz[v], v));
  while (233) {
    int u = (*--S.end()).second;
    S.erase(--S.end());
    if (s[u].empty()) return solve(), 0;
    pair<int, int> tmp = *--s[u].end();
    int dep = tmp.first, p = tmp.second;
    if (k + 2 * dep < R) {
      if (deg[p] == 1) {
        vis[p] = 1;
        for (auto v : e[p])
          if (v != fa[p] && !vis[v]) {
            vis[v] = 1, printf("%d %d\n", p, v);
            break;
          }
        k--, L--, R--;
        s[u].erase(make_pair(::dep[p], p));
        if (p != u) {
          s[u].erase(make_pair(::dep[fa[p]], fa[p]));
          deg[fa[p]]--;
          if (deg[fa[p]] >= 1) s[u].insert(make_pair(::dep[fa[p]], fa[p]));
        }
      } else {
        int a = 0, b = 0;
        for (auto v : e[p])
          if (v != fa[p] && !vis[v]) {
            if (!a)
              a = v;
            else {
              b = v;
              break;
            }
          }
        printf("%d %d\n", a, b), vis[a] = vis[b] = 1;
        s[u].erase(make_pair(::dep[p], p));
        deg[p] -= 2, k -= 2, L -= 2, R -= 2;
        if (deg[p] >= 1) s[u].insert(make_pair(::dep[p], p));
      }
      siz[u] -= 2;
      if (siz[u] > 1) S.insert(make_pair(siz[u], u));
      R -= 2 * dep;
    } else {
      pair<int, int> tmp = *s[u].lower_bound(make_pair((R - k) / 2, 0));
      int a = tmp.second, b = 0;
      for (auto v : e[a])
        if (v != fa[a] && !vis[v]) {
          b = v;
          break;
        }
      vis[a] = vis[b] = 1, printf("%d %d\n", a, b);
      return solve(), 0;
    }
  }
}
