#include <bits/stdc++.h>
using namespace std;
int n, k, s, t, ans;
int a[105], c[105];
struct edge {
  int t, v, f, nxt;
} e[20005];
int head[105], tot = 1;
void add(int st, int t, int v, int f) {
  e[++tot].nxt = head[st], e[tot].t = t, e[tot].v = v, e[tot].f = f,
  head[st] = tot;
  e[++tot].nxt = head[t], e[tot].t = st, e[tot].v = -v, e[tot].f = 0,
  head[t] = tot;
}
int pr[100005], L, R, vis[105], dis[105], pre[105];
bool spfa(int n, int s, int t) {
  int tp = 0;
  for (int i = 1; i <= n; i++) vis[i] = 0, dis[i] = 1e9;
  L = R = 0, pr[++R] = s, dis[s] = 0;
  do {
    int p = pr[++L];
    vis[p] = 0;
    for (int i = head[p]; i; i = e[i].nxt) {
      int to = e[i].t;
      if (!e[i].f) continue;
      if (dis[to] > dis[p] + e[i].v) {
        if (to == t) tp = 1;
        dis[to] = dis[p] + e[i].v, pre[to] = i;
        if (!vis[to]) vis[to] = 1, pr[++R] = to;
      }
    }
  } while (L < R);
  if (!tp) return 0;
  int p = t, Mf = 1e9;
  while (p != s) {
    Mf = min(Mf, e[pre[p]].f);
    p = e[pre[p] ^ 1].t;
  }
  p = t;
  while (p != s) {
    ans += Mf * e[pre[p]].v;
    e[pre[p]].f -= Mf, e[pre[p] ^ 1].f += Mf;
    p = e[pre[p] ^ 1].t;
  }
  return 1;
}
int las[105];
int main() {
  cin >> n >> k;
  s = n + 2, t = s + 1;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> c[i];
  for (int i = 1; i <= n; i++) {
    if (!las[a[i]])
      add(s, i, c[i], 1);
    else
      add(las[a[i]] + 1, i, c[i], 1);
    las[a[i]] = i, add(i, i + 1, 0, k);
  }
  for (int i = 1; i <= n; i++)
    if (las[i]) add(las[i] + 1, t, 0, 1);
  while (spfa(t, s, t))
    ;
  cout << ans << '\n';
  return 0;
}
