#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char c = getchar();
  long long x = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return x;
}
long long n, m;
struct edge {
  long long to, nxt, w;
} e[100005 << 1];
long long tot, head[100005];
inline void adde(long long u, long long v, long long w) {
  e[++tot] = (edge){v, head[u], w};
  head[u] = tot;
}
double res;
long long sz[100005], wsz[100005];
inline bool cmp(long long a, long long b) {
  return wsz[a] * sz[b] < wsz[b] * sz[a];
}
void dfs(long long u, long long pa) {
  vector<long long> o;
  sz[u] = 1;
  for (long long i = head[u]; i; i = e[i].nxt) {
    long long v = e[i].to;
    if (v == pa) continue;
    dfs(v, u);
    o.push_back(v);
    res += e[i].w * sz[v];
    sz[u] += sz[v];
    wsz[v] += e[i].w * 2;
    wsz[u] += wsz[v];
  }
  sort(o.begin(), o.end(), cmp);
  long long now = sz[u] - 1;
  for (auto v : o) {
    now -= sz[v];
    res += wsz[v] * now;
  }
}
signed main() {
  n = read();
  for (register long long i = (2); i <= (n); ++i) {
    long long u = read(), v = read(), w = read();
    adde(u, v, w), adde(v, u, w);
  }
  dfs(1, 0);
  printf("%.12lf", 1.0 * res / (n - 1));
  return 0;
}
