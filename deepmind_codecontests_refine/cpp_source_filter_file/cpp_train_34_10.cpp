#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int head[5009], tot, du[5009], n, cnt;
double ans;
int vis[5009];
inline int rd() {
  int x = 0;
  char c = getchar();
  bool f = 0;
  while (!isdigit(c)) {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return f ? -x : x;
}
struct edge {
  int n, to;
} e[5009 << 1];
inline void add(int u, int v) {
  e[++tot].n = head[u];
  e[tot].to = v;
  head[u] = tot;
}
inline void tpsort() {
  for (int i = 1; i <= n; ++i)
    if (du[i] == 1) q.push(i);
  cnt = n;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    cnt--;
    for (int i = head[u]; i; i = e[i].n) {
      int v = e[i].to;
      du[v]--;
      if (du[v] == 1) q.push(v);
    }
  }
}
void dfs(int u, int h, int l) {
  if (h <= 1)
    ans += (double)1 / (double)l;
  else
    ans += (double)1 / (double)l + (double)1 / ((double)(cnt - h + 2) + l - h) -
           (double)1 / ((double)cnt + l - h);
  for (int i = head[u]; i; i = e[i].n)
    if (vis[u] != vis[e[i].to]) {
      int v = e[i].to;
      ;
      vis[e[i].to] = vis[u];
      dfs(v, h + (du[v] != 1), l + 1);
    }
}
int main() {
  n = rd();
  int x, y;
  for (int i = 1; i <= n; ++i) {
    x = rd() + 1;
    y = rd() + 1;
    du[x]++;
    du[y]++;
    add(x, y);
    add(y, x);
  }
  tpsort();
  for (int i = 1; i <= n; ++i) {
    vis[i] = i;
    dfs(i, du[i] != 1, 1);
  }
  printf("%.12lf", ans);
  return 0;
}
