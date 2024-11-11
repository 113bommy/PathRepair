#include <bits/stdc++.h>
const int MAXN = 1e6 + 5;
int n, c;
std::vector<int> G[MAXN][2];
inline void stop() {
  puts("IMPOSSIBLE");
  exit(0);
}
int ch[MAXN][2];
inline void print(int v) {
  if (!v) return;
  print(ch[v][0]);
  printf("%d ", v);
  print(ch[v][1]);
}
int tot = 1;
inline void work(int v, int t) {
  for (int i = 0; i <= 1; ++i) std::sort(G[v][i].begin(), G[v][i].end());
  if (!G[v][0].empty()) {
    int n = ++tot;
    ch[v][0] = n;
    work(n, G[v][0].back());
  }
  if (!G[v][1].empty() && tot >= G[v][1].front()) stop();
  if (!G[v][1].empty()) t = std::max(t, G[v][1].back());
  if (tot < t) {
    int n = ++tot;
    ch[v][1] = n;
    work(n, t);
  }
}
int main() {
  scanf("%d%d", &n, &c);
  for (int i = 1; i <= c; ++i) {
    int u, v;
    char str[23];
    scanf("%d%d%s", &u, &v, str + 1);
    if (u >= v) stop();
    G[u][str[1] == 'R'].push_back(v);
  }
  work(1, n);
  print(1);
  return 0;
}
