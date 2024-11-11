#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long w = 0, x = 0;
  char c = getchar();
  while (!isdigit(c)) w |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return w ? -x : x;
}
namespace star {
const long long maxn = 1005, maxm = 2e5 + 10, delta = 3e8 + 10,
                INF = 0x3f3f3f3f3f3f3f3f;
long long ecnt = 1, n, head[maxn], to[maxm], nxt[maxm], v[maxm], S, T, ans;
inline void addedge(long long a, long long b, long long val) {
  to[++ecnt] = b, nxt[ecnt] = head[a], head[a] = ecnt, v[ecnt] = val;
  to[++ecnt] = a, nxt[ecnt] = head[b], head[b] = ecnt, v[ecnt] = 0;
}
long long dep[maxn];
inline bool bfs() {
  memset(dep, -1, sizeof dep);
  queue<long long> q;
  dep[S] = 0;
  q.push(S);
  while (!q.empty()) {
    long long x = q.front();
    q.pop();
    for (long long i = head[x]; i; i = nxt[i]) {
      long long u = to[i];
      if (v[i] and dep[u] == -1) dep[u] = dep[x] + 1, q.push(u);
    }
  }
  return dep[T] != -1;
}
long long dfs(long long x, long long flow) {
  if (x == T) return flow;
  long long w = 0, used = 0;
  for (long long i = head[x]; i; i = nxt[i]) {
    long long u = to[i];
    if (v[i] and dep[u] == dep[x] + 1) {
      w = dfs(u, min(v[i], flow - used));
      used += w;
      v[i] -= w, v[i ^ 1] += w;
      if (used == flow) return flow;
    }
  }
  if (!used) dep[x] = -1;
  return used;
}
inline void work() {
  n = read();
  S = n * 2 + 1, T = n * 2 + 2;
  for (long long i = 1; i <= n; i++) {
    long long x = read();
    while (x--) {
      long long u = read();
      addedge(i, n + u, INF);
    }
  }
  for (long long tmp, i = 1; i <= n; i++)
    addedge(S, i, tmp = delta - read()), ans += tmp;
  for (long long i = 1; i <= n; i++) addedge(i + n, T, delta);
  while (bfs()) ans -= dfs(S, INF);
  printf("%lld\n", min(0LL, -ans));
}
}  // namespace star
signed main() {
  star::work();
  return 0;
}
