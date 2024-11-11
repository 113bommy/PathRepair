#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int nega = 1;
  while (!isdigit(ch)) {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  int ans = 0;
  while (isdigit(ch)) {
    ans = ans * 10 + ch - 48;
    ch = getchar();
  }
  if (nega == -1) return -ans;
  return ans;
}
void print(vector<int> x) {
  for (int i = 0; i < (int)x.size(); i++)
    printf("%d%c", x[i], " \n"[i == (int)x.size() - 1]);
}
int a[100005], b[100005], id[100005], n;
long long getval(int x, int id) { return 1LL * x * a[id] + b[id]; }
namespace Flow {
struct Edge {
  int v, cap, nxt;
};
Edge edge[100005 * 2];
int first[100005], cur[100005], ss, dep[100005];
inline void init() {
  memset(first, 0, sizeof(first));
  ss = 1;
}
inline void add(int u, int v, int w) {
  edge[++ss] = (Edge){v, w, first[u]};
  first[u] = ss;
  edge[++ss] = (Edge){u, 0, first[v]};
  first[v] = ss;
}
int q[100005], l, r;
int s, t;
bool bfs() {
  for (int i = 1; i <= t; i++) dep[i] = 0;
  int l = 1, r = 1;
  q[1] = s, dep[s] = 1;
  while (l <= r) {
    int u = q[l++];
    for (int i = first[u]; i != 0; i = edge[i].nxt) {
      if (!edge[i].cap) continue;
      int v = edge[i].v;
      if (!dep[v]) dep[v] = dep[u] + 1, q[++r] = v;
      if (v == t) return 1;
    }
  }
  return dep[t];
}
int dfs(int u, int flow) {
  if (u == t || flow == 0) return flow;
  int ans = 0;
  for (int &i = cur[u]; i != 0; i = edge[i].nxt) {
    if (!edge[i].cap) continue;
    int v = edge[i].v;
    if (dep[v] != dep[u] + 1) continue;
    int go = dfs(v, min(flow, edge[i].cap));
    if (go) {
      flow -= go, ans += go;
      edge[i].cap -= go, edge[i ^ 1].cap += go;
    }
    if (!flow) return ans;
  }
  return ans;
}
int dinic() {
  int ans = 0;
  while (bfs()) {
    for (int i = 1; i <= t; i++) cur[i] = first[i];
    ans += dfs(s, 0x3f3f3f3f);
  }
  return ans;
}
int cnt[100005], id[100005], rev[100005], premx[100005];
bool chk(int mid) {
  for (int i = 1; i <= n * 2; i++) cnt[i] = 0;
  for (int i = 1; i <= n * 2; i++) id[i] = i;
  sort(id + 1, id + n * 2 + 1,
       [&](int x, int y) { return getval(0, x) < getval(0, y); });
  for (int i = 1; i <= n * 2; i++) rev[id[i]] = i;
  premx[1] = id[1];
  for (int i = 2; i <= n * 2; i++) {
    if (getval(mid, premx[i - 1]) > getval(mid, id[i]))
      premx[i] = premx[i - 1];
    else
      premx[i] = id[i];
  }
  for (int i = n * 2 - 1; i >= 1; i--)
    if (b[id[i]] == b[id[i + 1]]) premx[i] = premx[i + 1];
  for (int i = 1; i <= n; i++) cnt[premx[rev[i]]]++;
  for (int i = 1; i <= n * 2; i++) id[i] = i;
  sort(id + 1, id + n * 2 + 1,
       [&](int x, int y) { return getval(mid, x) > getval(mid, y); });
  int cur = 0;
  for (int i = 1; i <= n * 2; i++) {
    cur += cnt[id[i]];
    if (id[i] > n) cur--;
    while (i < n * 2 && getval(mid, id[i]) == getval(mid, id[i + 1])) {
      i++;
      cur += cnt[id[i]];
      if (id[i] > n) cur--;
    }
    if (cur < 0) return 0;
  }
  return 1;
}
};  // namespace Flow
namespace COST_FLOW {
struct Edge {
  int v, w, cap, nxt;
};
Edge edge[100005 * 2];
int first[100005], ss;
void init() {
  memset(first, 0, sizeof(first));
  ss = 1;
}
void add(int u, int v, int w, int c) {
  edge[++ss] = (Edge){v, w, c, first[u]};
  first[u] = ss;
  edge[++ss] = (Edge){u, -w, 0, first[v]};
  first[v] = ss;
}
int dis[100005], fr[100005], fe[100005], q[100005 * 10], vis[100005], ql, qr, s,
    t;
bool spfa() {
  for (int i = 1; i <= t; i++) dis[i] = 0x3f3f3f3f;
  dis[s] = 0, ql = qr = 1, q[1] = s;
  while (ql <= qr) {
    int u = q[ql++];
    vis[u] = 0;
    for (int i = first[u]; i != 0; i = edge[i].nxt) {
      if (!edge[i].cap) continue;
      int v = edge[i].v;
      if (dis[v] > dis[u] + edge[i].w) {
        dis[v] = dis[u] + edge[i].w;
        fr[v] = u, fe[v] = i;
        if (!vis[v]) vis[v] = 1, q[++qr] = v;
      }
    }
  }
  return dis[t] != 0x3f3f3f3f;
}
int dinic() {
  int ans = 0;
  while (spfa()) {
    int cur = t;
    ans += dis[t];
    while (cur != s) {
      int ce = fe[cur];
      edge[ce].cap--, edge[ce ^ 1].cap++;
      cur = fr[cur];
    }
  }
  return ans;
}
int get(int mid) {
  s = n * 9 + 1, t = s + 1;
  init();
  for (int i = 1; i <= n; i++) add(s, i, 0, 1);
  for (int i = 1; i <= n * 2; i++) id[i] = i;
  sort(id + 1, id + n * 2 + 1,
       [&](int x, int y) { return getval(0, x) > getval(0, y); });
  for (int i = 1; i <= n * 2; i++) add(i, i + n * 2, 1, 1);
  for (int i = 1; i < n * 2; i++)
    add(id[i] + n * 2, id[i + 1] + n * 2, 0, 0x3f3f3f3f);
  for (int i = 1; i <= n * 2; i++) {
    int j = i;
    while (getval(0, id[i]) == getval(0, id[j + 1])) j++;
    if (j != i) add(id[j] + n * 2, id[i] + n * 2, 0, 0x3f3f3f3f), i = j;
  }
  for (int i = 1; i <= n * 2; i++) add(i, i + n * 4, 0, 0x3f3f3f3f);
  for (int i = 1; i <= n * 2; i++) add(i + n * 2, i + n * 4, 0, 0x3f3f3f3f);
  sort(id + 1, id + n * 2 + 1,
       [&](int x, int y) { return getval(mid, x) > getval(mid, y); });
  for (int i = 1; i <= n * 2; i++) add(i + n * 4, i + n * 6, 1, 0x3f3f3f3f);
  for (int i = 1; i < n * 2; i++)
    add(n * 6 + id[i], n * 6 + id[i + 1], 0, 0x3f3f3f3f);
  for (int i = 1; i <= n * 2; i++) {
    int j = i;
    while (getval(mid, id[i]) == getval(mid, id[j + 1])) j++;
    if (j != i) add(n * 6 + id[j], n * 6 + id[i], 0, 0x3f3f3f3f), i = j;
  }
  for (int i = n + 1; i <= n + n; i++) add(i + n * 4, i + n * 7, 0, 1);
  for (int i = n + 1; i <= n + n; i++) add(i + n * 6, i + n * 7, 0, 1);
  for (int i = n + 1; i <= n + n; i++) add(i + n * 7, t, 0, 1);
  int ans = dinic();
  return ans;
}
};  // namespace COST_FLOW
signed main() {
  cin >> n;
  for (int i = 1; i <= n * 2; i++) a[i] = read(), b[i] = read();
  int l = 0, r = 1e9, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (Flow::chk(mid))
      r = mid - 1, ans = mid;
    else
      l = mid + 1;
  }
  cerr << clock() << endl;
  if (ans == -1) return cout << "-1\n", 0;
  cout << ans << " ";
  cout << COST_FLOW::get(ans) << endl;
  return 0;
}
