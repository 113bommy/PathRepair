#include <bits/stdc++.h>
using namespace std;
int n;
struct edge {
  int v, next;
} e[500100];
int head[100100], tot = 0;
void Add(int u, int v) {
  e[tot].v = v;
  e[tot].next = head[u];
  head[u] = tot++;
}
int res[100100];
int deep[100100];
int vis[100100];
void DFS(int u) {
  vis[u] = 1;
  for (int i = head[u]; i != -1; i = e[i].next) {
    int v = e[i].v;
    if (deep[v] <= 2 && !vis[v]) DFS(v);
  }
}
int main() {
  memset((head), (-1), sizeof(head));
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    Add(u, v);
    Add(v, u);
    deep[u]++;
    deep[v]++;
  }
  for (int i = 1; i <= n; i++) {
    if (deep[i] == 1) DFS(i);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      for (int j = head[i]; j != -1; j = e[j].next) {
        int v = e[j].v;
        if (vis[v]) {
          res[i] = min(res[i] + 1, 2);
        }
      }
    }
  }
  for (int u = 1; u <= n; u++) {
    if (!vis[u]) {
      int cnt = 0;
      for (int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if (!vis[v] && deep[v] - res[v] > 1) cnt++;
      }
      if (cnt > 2) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
