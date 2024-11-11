#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &s) {
  s = 0;
  char ch = getchar();
  bool flag = 0;
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) s = ((s + (s << 2)) << 1) + ch - '0', ch = getchar();
  s = flag ? -s : s;
}
long long n, m, hed[210000], ed[210000], nxt[210000], tl, k, p[210000],
    dis[210000], Min, Max;
vector<long long> V[210000];
inline void Line(long long u, long long v) {
  nxt[++tl] = hed[u], hed[u] = tl, ed[tl] = v;
}
queue<long long> Q;
inline void BFS() {
  memset(dis, 0x3f3f3f3f, sizeof(dis)), Q.push(p[k]), dis[p[k]] = 0;
  while (!Q.empty()) {
    long long T = Q.front();
    Q.pop();
    for (long long i = hed[T]; i; i = nxt[i])
      if (dis[ed[i]] > dis[T] + 1) dis[ed[i]] = dis[T] + 1, Q.push(ed[i]);
  }
}
signed main() {
  read(n), read(m);
  for (long long i = 1, u, v; i <= m; ++i)
    read(u), read(v), Line(v, u), V[u].push_back(v);
  read(k);
  for (long long i = 1; i <= k; ++i) read(p[i]);
  BFS();
  for (long long i = 1; i < k; ++i) {
    if (dis[p[i]] != dis[p[i + 1]] + 1)
      Min++, Max++;
    else {
      long long cnt = 0;
      for (auto x : V[p[i]])
        if (dis[p[i]] == dis[x] + 1) cnt++;
      if (cnt > 1) Max++;
    }
  }
  printf("%lld %lld\n", Min, Max);
  return 0;
}
