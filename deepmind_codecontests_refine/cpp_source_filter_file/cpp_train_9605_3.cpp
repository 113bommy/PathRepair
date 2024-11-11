#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, maxm = 2e5 + 5;
int head[maxn], nume;
struct edge {
  int v, w, c, next;
} e[maxm];
inline void init_edge() {
  memset(head, -1, sizeof head);
  nume = 0;
}
inline void add_edge(int u, int v, int w = 0, int c = 0) {
  e[nume].v = v;
  e[nume].w = w;
  e[nume].c = c;
  e[nume].next = head[u];
  head[u] = nume++;
}
int sz[maxn];
void dfs(int u, int f) {
  sz[u] = 1;
  for (int i = head[u]; ~i; i = e[i].next) {
    int v = e[i].v;
    if (v != f) {
      dfs(v, u);
      sz[u] += sz[v];
    }
  }
}
int s[maxn];
int dn[maxn], ed[maxn];
int DFS(int u, int f) {
  int g = 0;
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 less<pair<int, int> > >
      q;
  for (int i = head[u]; ~i; i = e[i].next) {
    int v = e[i].v;
    if (v != f) {
      int xx = DFS(v, u);
      int yy = s[v];
      if (s[v] > 0) {
        q.push(make_pair(yy, xx));
      }
      g += s[v];
    }
  }
  g++;
  ed[u] = u;
  q.push(make_pair(1, u));
  while (g > s[u]) {
    pair<int, int> p1, p2;
    p1 = q.top();
    q.pop();
    p2 = q.top();
    q.pop();
    printf("%d %d\n", p1.second, p2.second);
    if (p1.first > 1) {
      ed[dn[p1.second]] = ed[p1.second];
      p1.first--;
      p1.second = dn[p1.second];
      q.push(p1);
    }
    if (p2.first > 1) {
      ed[dn[p2.second]] = ed[p2.second];
      p2.first--;
      p2.second = dn[p2.second];
      q.push(p2);
    }
    g -= 2;
  }
  if (q.empty()) {
    return 0;
  } else {
    pair<int, int> pa = q.top();
    q.pop();
    int xx = pa.second;
    while (!q.empty()) {
      pair<int, int> pir = q.top();
      q.pop();
      dn[ed[xx]] = pir.second;
      ed[xx] = ed[pir.second];
    }
    return xx;
  }
}
int n;
int maxx[maxn];
long long k;
int main() {
  scanf("%d%lld", &n, &k);
  init_edge();
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v);
    add_edge(v, u);
  }
  dfs(1, 0);
  long long K = k, he = 0;
  for (int i = 2; i <= n; i++) {
    if (sz[i] & 1) {
      K--;
    }
    maxx[i] = min(sz[i], n - sz[i]) / 2;
    he += maxx[i] * 2;
  }
  if (K < 0 || K % 2 == 1 || K > he) {
    printf("NO");
    return 0;
  }
  K /= 2;
  printf("YES\n");
  int l = 0, r = n;
  if (l < r) {
    int m = l + r + 1 >> 1;
    long long sum = 0;
    for (int i = 2; i <= n; i++) {
      sum += min(m, maxx[i]);
    }
    if (sum < K)
      l = m;
    else
      r = m - 1;
  }
  for (int i = 2; i <= n; i++) {
    s[i] = min(l, maxx[i]);
    K -= s[i];
  }
  for (int i = 2; i <= n && K; i++) {
    if (s[i] < maxx[i] && (sz[i] & 1) == 0) {
      s[i]++;
      K--;
    }
  }
  for (int i = 2; i <= n && K; i++) {
    if (s[i] < maxx[i] && (sz[i] & 1) == 1) {
      s[i]++;
      K--;
    }
  }
  for (int i = 2; i <= n; i++) {
    s[i] = 2 * s[i] + (sz[i] & 1);
  }
  DFS(1, 0);
}
