#include <bits/stdc++.h>
namespace data {
int val[105], mag[105], lev[105], num, lit;
}
namespace init {
inline void in(int &justval) {
  int if_z = 1;
  justval = 0;
  char Cget = getchar();
  while (Cget > '9' || Cget < '0') {
    if (Cget == '-') if_z = -1;
    Cget = getchar();
  }
  while (Cget >= '0' && Cget <= '9') {
    justval = justval * 10 + Cget - '0';
    Cget = getchar();
  }
  justval *= if_z;
}
}  // namespace init
namespace solve {
struct EdgeType {
  int v, f;
  EdgeType *next, *another;
};
struct EdgeType *head[105], e[200005];
int que[200005], sum, prime[200005 * 10], num, cnt, s, t, deep[105];
bool p_[200005 * 10 - 1];
inline void edge_add(int u, int v, int f) {
  e[++cnt].v = v, e[cnt].f = f, e[cnt].next = head[u], head[u] = &e[cnt];
  e[++cnt].v = u, e[cnt].f = 0, e[cnt].next = head[v], head[v] = &e[cnt];
  e[cnt].another = &e[cnt - 1], e[cnt - 1].another = &e[cnt];
}
int min(const int &tops_, const int &tops__) {
  if (tops_ < tops__)
    return tops_;
  else
    return tops__;
}
inline bool bfs() {
  t = data::num + 1, s = 0;
  int h = 0, tail = 1;
  que[h] = s;
  for (int i = s; i <= t; i++) deep[i] = -1;
  deep[s] = 0;
  while (h < tail) {
    int now = que[h++];
    for (EdgeType *i = head[now]; i != NULL; i = i->next) {
      if (deep[i->v] < 0 && i->f) {
        deep[i->v] = deep[now] + 1;
        if (i->v == t) return true;
        que[tail++] = i->v;
      }
    }
  }
  return false;
}
int flowing(int now, int flow) {
  if (now == t || flow <= 0) return flow;
  int oldflow = 0;
  for (EdgeType *i = head[now]; i != NULL; i = i->next) {
    if (deep[i->v] == deep[now] + 1 && i->f) {
      int pos = flowing(i->v, min(i->f, flow));
      flow -= pos, oldflow += pos, i->f -= pos, i->another->f += pos;
      if (!flow) return oldflow;
    }
  }
  if (!oldflow) deep[now] = -1;
  return oldflow;
}
bool dinic(int res, int lit) {
  while (bfs()) res -= flowing(s, 0x7fffffff);
  return res >= lit;
}
void ouler(int limit) {
  for (int i = 2; i <= limit; i++) {
    if (!p_[i]) prime[++num] = i;
    for (int j = 1; prime[j] * i <= limit && j <= num; j++) {
      p_[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
}
bool check(int x) {
  int n = data::num, k = data::lit, res = 0;
  s = 0, t = n + 1, cnt = 1;
  for (int i = s; i <= t; i++) head[i] = NULL;
  int idx__ = -1;
  for (int i = 1; i <= n; i++) {
    if (data::lev[i] > x) continue;
    if (data::mag[i] == 1 && data::val[i] > data::val[idx__]) idx__ = i;
  }
  for (int i = 1; i <= n; i++) {
    if (data::lev[i] > x || (data::mag[i] == 1 && idx__ == i)) continue;
    res += data::val[i];
    if (data::mag[i] & 1) {
      edge_add(s, i, data::val[i]);
      for (int j = 1; j <= n; j++) {
        if (data::lev[j] > x || i == j) continue;
        if (!(data::mag[j] & 1)) {
          if (!p_[data::mag[i] + data::mag[j]]) edge_add(i, j, 0x7fffffff);
        } else if (data::mag[i] + data::mag[j] == 2)
          edge_add(i, j, 0x7fffffff);
      }
    } else
      edge_add(i, t, data::val[i]);
  }
  return dinic(res, k);
}
void binary() {
  ouler(200005 * 10 - 1);
  int l = 1, r = data::num, ans = -1;
  while (l <= r) {
    int mid = l + r >> 1;
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%d\n", ans);
}
}  // namespace solve
int main() {
  init::in(data::num), init::in(data::lit);
  for (int i = 1; i <= data::num; i++) {
    init::in(data::val[i]);
    init::in(data::mag[i]);
    init::in(data::lev[i]);
  }
  solve::binary();
  return 0;
}
