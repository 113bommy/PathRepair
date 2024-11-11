#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) {
    if (ch == '-') f = -1;
  }
  for (; isdigit(ch); ch = getchar()) {
    x = x * 10 + ch - 48;
  }
  return x * f;
}
const int mxN = 2e5;
struct Edge {
  int v, nxt;
} e[(mxN << 1) + 3];
int fe[mxN + 3];
int a[mxN + 3];
int f[mxN + 3], sg[mxN + 3];
int ind[mxN + 3];
bool vis[mxN + 3];
int n, m, en;
void addedge(int u, int v) {
  en++;
  e[en].v = v;
  e[en].nxt = fe[u];
  fe[u] = en;
}
void dfs(int u) {
  if (vis[u]) return;
  vis[u] = true;
  vector<int> apr;
  for (int i = fe[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    dfs(v);
    apr.push_back(f[v]);
  }
  sort(apr.begin(), apr.end());
  f[u] = 0;
  for (int i = 0; i < apr.size(); i++) {
    if (apr[i] == f[u]) {
      f[u]++;
    } else if (apr[i] > f[u]) {
      break;
    }
  }
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    ind[v]++;
    addedge(u, v);
  }
  for (int i = 1; i <= n; i++) {
    if (ind[i] == 0) {
      dfs(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    sg[f[i]] ^= a[i];
  }
  for (int i = n; i >= 0; i--)
    if (sg[i]) {
      puts("WIN");
      for (int u = 1; u <= n; u++)
        if (f[u] == i && (a[u] ^ sg[i]) < a[u]) {
          a[u] ^= sg[i];
          for (int o = fe[u]; o; o = e[o].nxt) {
            int v = e[o].v;
            a[v] ^= sg[f[v]];
            sg[v] = 0;
          }
          break;
        }
      for (int u = 1; u <= n; u++) printf("%d ", a[u]);
      puts("");
      return 0;
    }
  puts("LOSE");
  return 0;
}
