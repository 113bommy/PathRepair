#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int n, m, i, j, t, k, s, head[maxn], N, in[maxn], b[maxn], sg[maxn];
long long a[maxn], val[maxn];
bool vis[maxn];
struct Edge {
  int nxt, aim;
} edge[maxn];
inline void add_edge(int x, int y) {
  edge[++N] = (Edge){head[x], y};
  head[x] = N;
}
queue<int> Q;
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  for (i = 1; i <= m; ++i) {
    scanf("%d%d", &t, &k);
    add_edge(t, k);
    ++in[k];
  }
  for (i = 1; i <= n; ++i)
    if (!in[i]) Q.push(i);
  k = 0;
  while (!Q.empty()) {
    t = Q.front();
    Q.pop();
    b[++k] = t;
    for (i = head[t]; i; i = edge[i].nxt) {
      int des = edge[i].aim;
      --in[des];
      if (!in[des]) Q.push(des);
    }
  }
  for (i = n; i > 0; --i) {
    for (j = head[b[i]]; j; j = edge[j].nxt) vis[sg[edge[j].aim]] = 1;
    t = 0;
    while (vis[t]) ++t;
    sg[b[i]] = t;
    val[t] ^= a[b[i]];
    for (j = head[b[i]]; j; j = edge[j].nxt) vis[sg[edge[j].aim]] = 0;
  }
  t = -1;
  for (i = 1; i <= n; ++i)
    if (val[i] > 0) t = i;
  if (t == -1) {
    printf("LOSE\n");
    return 0;
  }
  printf("WIN\n");
  for (i = 1; i <= n; ++i)
    if (sg[i] == t && (a[i] ^ val[sg[i]]) < a[i]) {
      a[i] ^= val[sg[i]];
      val[sg[i]] = 0;
      for (j = head[i]; j; j = edge[j].nxt) {
        a[edge[j].aim] ^= val[sg[edge[j].aim]];
        val[sg[edge[j].aim]] = 0;
      }
      break;
    }
  for (i = 1; i <= n; ++i) printf("%lld%c", a[i], (i == n ? '\n' : ' '));
  return 0;
}
