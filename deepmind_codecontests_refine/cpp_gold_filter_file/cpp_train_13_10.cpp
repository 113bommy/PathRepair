#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[200005];
struct edge {
  int to, nxt;
} e[200005];
int hed[200005], cnt;
inline void add(int u, int v) {
  e[++cnt] = (edge){v, hed[u]};
  hed[u] = cnt;
}
int num[200005], ru[200005];
int sg[200005], tag[200005], dep[200005];
inline void topo() {
  queue<int> q;
  for (int i = 1; i <= n; ++i)
    if (!ru[i]) q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < a[u].size(); ++i) tag[dep[a[u][i]]] = u;
    while (tag[dep[u]] == u) dep[u]++;
    sg[dep[u]] ^= num[u];
    for (int i = hed[u]; i; i = e[i].nxt) {
      int v = e[i].to;
      if (--ru[v] == 0) q.push(v);
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", num + i);
  int u, v;
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &u, &v);
    a[u].push_back(v), add(v, u), ru[u]++;
  }
  topo();
  for (int i = n; i >= 0; --i) {
    if (sg[i] == 0) continue;
    for (int j = 1; j <= n; ++j) {
      if (dep[j] == i && num[j] > (num[j] ^ sg[i])) {
        u = j;
        break;
      }
    }
    num[u] ^= sg[i];
    for (int j = 0; j < a[u].size(); ++j) {
      int v = a[u][j];
      num[v] ^= sg[dep[v]], sg[dep[v]] = 0;
    }
    printf("WIN\n");
    for (int j = 1; j <= n; ++j) printf("%d ", num[j]);
    return 0;
  }
  printf("LOSE");
  return 0;
}
