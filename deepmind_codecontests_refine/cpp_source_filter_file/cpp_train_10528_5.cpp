#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
char buf[1 << 25], *p1 = buf, *p2 = buf;
inline int read() {
  int x = 0, f = 1;
  char ch;
  while (!isdigit(
      ch = (p1 == p2 &&
                    (p2 = (p1 = buf) + fread(buf, 1, 1 << 25, stdin), p1 == p2)
                ? EOF
                : *p1++)))
    if (ch == '-') f = -1;
  x = ch - '0';
  while (isdigit(
      ch = (p1 == p2 &&
                    (p2 = (p1 = buf) + fread(buf, 1, 1 << 25, stdin), p1 == p2)
                ? EOF
                : *p1++)))
    x = x * 10 + ch - '0';
  return x * f;
}
const int N = 5e5 + 100;
int n, m, k, vis[N], ban[N], cnt, a[N], b[N], VL;
vector<int> cir[N];
vector<int> e[N];
vector<int> ans;
int dfs(int u, int dep = 1) {
  if (dep >= VL) {
    ans.push_back(u);
    return 1;
  }
  for (auto v : e[u]) {
    if (vis[v]) continue;
    vis[v] = 1;
    if (dfs(v, dep + 1)) {
      ans.push_back(u);
      return 1;
    }
  }
  return 0;
}
inline void sv1() {
  for (int i = 1; i <= 3; i++) {
    memset(vis, 0, sizeof vis);
    vis[a[i]] = 1;
    if (dfs(a[i])) {
      reverse(ans.begin(), ans.end());
      printf("PATH\n");
      printf("%d\n", ans.size());
      for (auto x : ans) printf("%d ", x);
      exit(0);
    }
  }
  memset(vis, 0, sizeof vis);
}
int dfs2(int st, int u, int dep = 1) {
  if (ban[u] || cnt > k || dep > 5) return 0;
  for (auto v : e[u]) {
    if (ban[v]) continue;
    if (v == st && (dep == 4 || dep == 5)) {
      ban[st] = 1;
      cir[++cnt].push_back(st);
      cir[cnt].push_back(u);
      return 1;
    }
    if (vis[v]) continue;
    vis[v] = 1;
    if (dfs2(st, v, dep + 1)) {
      vis[v] = 0;
      if (u == st) return 1;
      cir[cnt].push_back(u);
      vis[v] = 0;
      return 1;
    }
    vis[v] = 0;
  }
  return 0;
}
inline void sv2() {
  for (int i = 1; i <= n && cnt <= k; i++) {
    int f = 1;
    vis[a[i]] = 1;
    f = dfs2(a[i], a[i]);
    vis[a[i]] = 0;
  }
  if (cnt > k) {
    printf("CYCLES\n");
    for (int i = 1; i <= k; i++) {
      int sz = cir[i].size();
      printf("%d\n", sz);
      for (auto x : cir[i]) printf("%d ", x);
      printf("\n");
    }
    exit(0);
  }
}
int main() {
  n = read();
  m = read();
  k = read();
  VL = max(n, n / k + 1);
  for (int i = 1; i <= n; i++) a[i] = i;
  shuffle(a + 1, a + 1 + n, default_random_engine(233));
  for (int i = 1; i <= n; i++) b[a[i]] = i;
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    e[u].push_back(v);
    e[v].push_back(u);
  }
  sv1();
  sv2();
  printf("-1");
  return 0;
}
