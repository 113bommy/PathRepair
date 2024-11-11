#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10, mod = 1e9 + 7, INF = 0x3f3f3f3f, B = 133597;
struct HT {
  const static int M = 29847577;
  bool a[M];
  int buf[maxn], tot;
  inline void ins(long long x) { a[buf[++tot] = x % M] = 1; }
  inline bool find(long long x) { return a[x % M]; }
  inline void clear() {
    for (int i = 1; i <= tot; ++i) a[buf[i]] = 0;
    tot = 0;
  }
} ht;
inline long long Hash(long long x, long long y) {
  if (x > y) swap(x, y);
  return x * B + y;
}
vector<int> e[maxn];
int deg[maxn], inq[maxn], vis[maxn], buf[maxn], tot;
vector<int> ans;
inline bool check(int u, int k) {
  buf[tot = 1] = u;
  for (auto v : e[u]) {
    if (vis[v]) continue;
    for (int i = 1; i <= tot; ++i)
      if (!ht.find(Hash(buf[i], v))) return 0;
    buf[++tot] = v;
  }
  if (tot < k) return 0;
  for (int i = 1; i <= tot; ++i) ans.push_back(buf[i]);
  return 1;
}
inline void tupo(int n, int k) {
  queue<int> q;
  for (int i = 1; i <= n; ++i)
    if (deg[i] < k) q.push(i), vis[i] = 1;
  while (int(q.size())) {
    int u = q.front();
    q.pop();
    for (auto v : e[u]) {
      deg[v]--;
      if (!vis[v] && deg[v] < k) q.push(v), vis[v] = 1;
    }
  }
}
int sol(int n, int k) {
  tupo(n, k - 1);
  queue<int> q;
  for (int i = 1; i <= n; ++i)
    if (!vis[i] && deg[i] < k) q.push(i), inq[i] = 1;
  while (int(q.size())) {
    int u = q.front();
    q.pop();
    if (check(u, k)) return 2;
    vis[u] = 1;
    for (auto v : e[u]) {
      deg[v]--;
      if (!vis[v] && !inq[v] && deg[v] < k) q.push(v), inq[v] = 1;
    }
  }
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) ans.push_back(i);
  return int(ans.size()) ? 1 : 0;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    ans.clear();
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) vis[i] = deg[i] = inq[i] = 0, e[i].clear();
    for (int i = 1; i <= m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      e[u].push_back(v);
      e[v].push_back(u);
      deg[u]++;
      deg[v]++;
      ht.ins(Hash(u, v));
    }
    int res = sol(n, k);
    if (!res)
      printf("-1\n");
    else {
      if (res == 1)
        printf("1 %d\n", int(ans.size()));
      else
        printf("2\n");
      for (int i = 0; i < int(ans.size()); ++i)
        printf("%d%c", ans[i], " \n"[i == int(ans.size()) - 1]);
    }
    ht.clear();
  }
  return 0;
}
