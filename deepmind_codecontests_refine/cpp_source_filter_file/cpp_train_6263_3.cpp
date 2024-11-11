#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int x = 0, f = 1;
  register char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = 0;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + (ch ^ '0');
    ch = getchar();
  }
  return f ? x : -x;
}
const int N = 4.4e3 + 5, M = N << 2, inf = 0x3f3f3f3f;
int n, m, a[N], b[N], s1[N], s2[N], mid, cnt[N];
int s, t, tot, head[M], num = 1, flow[M], dis[M], id[M], pre[M], ans;
struct edge {
  int to, val, flo, next;
} e[M * 20];
inline void add(int u, int v, int w, int f) {
  e[++num] = (edge){v, w, f, head[u]}, head[u] = num;
  e[++num] = (edge){u, -w, 0, head[v]}, head[v] = num;
}
inline long long cal(int x) { return 1ll * mid * a[x] + b[x]; }
inline bool cmp_0(int x, int y) {
  return b[x] == b[y] ? a[x] > a[y] : b[x] < b[y];
}
inline bool cmp_T(int x, int y) { return cal(x) < cal(y); }
inline bool Bfs() {
  memset(dis, inf, sizeof(dis));
  deque<int> q;
  dis[s] = 0, flow[s] = inf;
  q.push_back(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop_front();
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].to;
      if (!e[i].flo || dis[v] <= dis[u] + e[i].val) continue;
      dis[v] = dis[u] + e[i].val;
      id[v] = i, pre[v] = u, flow[v] = min(flow[u], e[i].flo);
      if (e[i].val)
        q.push_back(v);
      else
        q.push_front(v);
    }
  }
  return dis[t] < inf;
}
inline void Work() {
  ans += dis[t] * flow[t];
  int p = t;
  while (p ^ s)
    e[id[p]].flo -= flow[t], e[id[p] ^ 1].flo += flow[t], p = pre[p];
}
inline void mcmf() {
  while (Bfs()) Work();
  printf("%d\n", ans);
}
int main() {
  n = read();
  m = n + n;
  for (int i = (1), _ed = (m); i <= _ed; ++i) a[i] = read(), b[i] = read();
  for (int i = (1), _ed = (m); i <= _ed; ++i) s1[i] = s2[i] = i;
  sort(s1 + 1, s1 + m + 1, cmp_0);
  int l = 0, r = 1e9, res = -1;
  while (l <= r) {
    mid = (l + r) >> 1;
    memset(cnt, 0, sizeof cnt);
    for (int i = 1, mx = 0; i <= m; ++i) {
      if (!mx || cal(s1[i]) > cal(mx)) mx = s1[i];
      cnt[mx] += s1[i] <= n;
    }
    int t = 0;
    sort(s2 + 1, s2 + m + 1, cmp_T);
    for (int i = m, j; i; i = j - 1) {
      j = i;
      while (j > 1 && cal(s2[i]) == cal(s2[j - 1])) --j;
      for (int k = (i), _ed = (j); k <= _ed; ++k) t += cnt[s2[k]];
      for (int k = (i), _ed = (j); k <= _ed; ++k) t -= s2[k] > n;
      if (t < 0) break;
    }
    if (t < 0)
      l = mid + 1;
    else
      r = mid - 1, res = mid;
  }
  printf("%d ", res);
  if (!~res) return puts(""), 0;
  mid = res;
  sort(s2 + 1, s2 + m + 1, cmp_T);
  s = m + m + 1, t = tot = s + 1;
  for (int i = (1), _ed = (m); i <= _ed; ++i) add(i, m + i, 0, inf);
  for (int i = (1), _ed = (n); i <= _ed; ++i) add(s, i, 0, 1);
  for (int i = (n + 1), _ed = (m); i <= _ed; ++i) add(i + m, t, 0, 1);
  for (int i = 1, j, las = ++tot; i <= m; i = j + 1) {
    j = i;
    while (j < m && b[s1[i]] == b[s1[j + 1]]) ++j;
    ++tot;
    add(tot, las, 0, inf);
    las = tot;
    for (int k = (i), _ed = (j); k <= _ed; ++k)
      add(s1[k], tot, 1, inf), add(tot, s1[k], 0, inf);
  }
  for (int i = 1, j, las = ++tot; i <= m; i = j + 1) {
    j = i;
    while (j < m && cal(s2[i]) == cal(s2[j + 1])) ++j;
    ++tot;
    add(tot, las, 0, inf);
    las = tot;
    for (int k = (i), _ed = (j); k <= _ed; ++k)
      add(s2[k] + m, tot, 1, inf), add(tot, s2[k] + m, 0, inf);
  }
  mcmf();
  return 0;
}
