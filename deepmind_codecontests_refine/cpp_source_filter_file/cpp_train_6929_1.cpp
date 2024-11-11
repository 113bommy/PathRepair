#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
int gcd(int x, int y) {
  while (y) {
    int t = x % y;
    x = y;
    y = t;
  }
  return x;
}
int vis[2000010], fst[2000010], nxt[2000100], vv[2000100], id[2000100], e;
int fa[2000010], dep[2000010], fae[2000010];
int n, m, s, t;
int dir[2000100], su[2000100], sv[2000100], son[2000010];
int fst1[2000010], nxt1[2000100], vv1[2000100], id1[2000100], e1;
void init() {
  e1 = e = 0;
  for (int i = 1; i <= n; i++) fst[i] = fst1[i] = -1, vis[i] = 0;
  for (int i = 1; i <= m; i++) dir[i] = -1;
}
void add(int u, int v, int i) {
  vv[e] = v, nxt[e] = fst[u], id[e] = i, fst[u] = e++;
  vv[e] = u, nxt[e] = fst[v], id[e] = i, fst[v] = e++;
}
void add1(int u, int v, int i) {
  vv1[e1] = v, nxt1[e1] = fst1[u], id1[e1] = i, fst1[u] = e1++;
}
void dfs(int u) {
  vis[u] = 1;
  for (int i = fst[u]; ~i; i = nxt[i]) {
    int v = vv[i];
    if (v == fa[u]) continue;
    if (!vis[v]) {
      fae[v] = id[i];
      dep[v] = dep[u] + 1;
      fa[v] = u;
      son[u] = v;
      dfs(v);
    } else if (dep[v] < dep[u]) {
      add1(son[v], u, id[i]);
    }
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    init();
    for (int i = 1; i <= m; i++) {
      scanf("%d%d", &su[i], &sv[i]);
      add(su[i], sv[i], i);
    }
    fa[s] = dep[s] = 0;
    dfs(s);
    queue<pair<int, int> > que;
    que.push(make_pair(t, 0));
    while (!que.empty()) {
      int u(que.front().first), d(que.front().second);
      que.pop();
      while (fa[u] && dir[fae[u]] == -1) {
        dir[fae[u]] = d;
        for (int i = fst1[u]; ~i; i = nxt[i]) {
          int v = vv[i];
          dir[id[i]] = d;
          que.push(make_pair(v, d ^ 1));
        }
        u = fa[u];
      }
    }
    int flag = 0;
    for (int i = 1; i <= m; i++)
      if (dir[i] == -1) {
        flag = 1;
        break;
      }
    if (flag)
      puts("No");
    else {
      puts("Yes");
      for (int i = 1; i <= m; i++) {
        if ((dep[su[i]] < dep[sv[i]]) == dir[i]) swap(su[i], sv[i]);
        printf("%d %d\n", su[i], sv[i]);
      }
    }
  }
  return 0;
}
