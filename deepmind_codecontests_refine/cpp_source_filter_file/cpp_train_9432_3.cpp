#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const long long inf = 1e18;
template <typename T>
inline int getmin(T &x, T y) {
  return x > y ? x = y, 1 : 0;
}
template <typename T>
inline int getmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
template <typename T>
inline void read(T &x) {
  x = 0;
  T f = 1, ch = getchar();
  while (!isdigit(ch) && ch ^ '-') ch = getchar();
  if (ch == '-') f = -1, ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  x *= f;
}
int ver[maxn << 1], edge[maxn << 1], Next[maxn << 1], head[maxn], len = -1;
inline void add(int x, int y, int z) {
  ver[++len] = y, edge[len] = z, Next[len] = head[x], head[x] = len;
}
int cnt;
inline int pre(int x) { return x == 1 ? cnt : x - 1; }
inline int nxt(int x) { return x == cnt ? 1 : x + 1; }
bool vis[maxn];
int cir[maxn];
long long sum[maxn];
inline int dfs(int x, int fa) {
  if (vis[x]) return x;
  int tmp;
  vis[x] = 1;
  for (int i = head[x]; ~i; i = Next[i])
    if (i ^ fa)
      if (tmp = dfs(ver[i], i ^ 1)) {
        if (tmp == -1) return -1;
        cir[++cnt] = x;
        sum[cnt] = edge[i];
        return tmp == x ? -1 : tmp;
      }
  return 0;
}
long long dist[maxn], mxdist;
int id;
inline void bfs(int s, int ban1, int ban2) {
  queue<pair<int, int> > q;
  mxdist = dist[s] = 0ll;
  id = 0;
  q.push(make_pair(s, 0));
  while (!q.empty()) {
    int x = q.front().first, u = q.front().second;
    q.pop();
    if (getmax(mxdist, dist[x])) id = x;
    for (int i = head[x]; ~i; i = Next[i]) {
      int y = ver[i], z = edge[i];
      if (i ^ u && y ^ ban1 && y ^ ban2) {
        dist[y] = dist[x] + z;
        q.push(make_pair(y, i ^ 1));
      }
    }
  }
}
long long dep[maxn], mx, ans, tmp;
long long p1[maxn], p2[maxn];
long long s1[maxn], s2[maxn];
long long m1[maxn], m2[maxn];
int main() {
  int n;
  read(n);
  memset(head, 0xff, sizeof(head));
  for (register int i = 1; i <= n; ++i) {
    int x, y, z;
    read(x);
    read(y);
    read(z);
    add(x, y, z);
    add(y, x, z);
  }
  dfs(1, -1);
  for (register int i = 1; i <= cnt; ++i) {
    sum[i] += sum[i - 1];
    bfs(cir[i], cir[pre(i)], cir[nxt(i)]);
    dep[i] = mxdist;
    bfs(id, cir[pre(i)], cir[nxt(i)]);
    getmax(mx, mxdist);
  }
  ans = inf;
  p1[0] = p2[0] = s1[cnt + 1] = s2[cnt + 1] = s2[cnt + 2] = -inf;
  for (register int i = 1; i <= cnt; ++i) {
    m1[i] = max(m1[i - 1], dep[i] + sum[i] + p1[i - 1]);
    p1[i] = max(p1[i - 1], dep[i] - sum[i]);
    p2[i] = max(p2[i - 1], dep[i] + sum[i]);
  }
  for (register int i = cnt; i; --i) {
    m2[i] = max(m2[i + 1], dep[i + 1] - sum[i + 1] + s2[i + 2]);
    s1[i] = max(s1[i + 1], dep[i] - sum[i]);
    s2[i] = max(s2[i + 1], dep[i] + sum[i]);
  }
  for (register int i = 1; i < cnt; ++i) {
    tmp = 0ll;
    getmax(tmp, m1[i]);
    getmax(tmp, m2[i]);
    getmax(tmp, sum[cnt] + s1[i + 1] + p2[i]);
    getmin(ans, tmp);
  }
  tmp = 0ll;
  for (register int i = 2; i <= cnt; ++i)
    getmax(tmp, dep[i] + sum[i] + p1[i - 1]);
  getmin(ans, tmp);
  getmax(ans, mx);
  printf("%lld\n", ans);
  return 0;
}
