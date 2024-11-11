#include <bits/stdc++.h>
using namespace std;
struct node {
  int from;
  int to;
  int l;
  int r;
  int next;
} e[100000];
int cont;
int ok;
int vis[4000];
int head[100000];
int L[1000000];
int n, m;
void add(int from, int to, int l, int r) {
  e[cont].to = to;
  e[cont].l = l;
  e[cont].r = r;
  e[cont].next = head[from];
  head[from] = cont++;
}
void Dfs(int u, int LL, int RR) {
  vis[u] = 1;
  if (u == n) {
    ok = 1;
    return;
  }
  for (int i = head[u]; i != -1; i = e[i].next) {
    int v = e[i].to;
    if (LL >= e[i].l && RR <= e[i].r) {
      if (vis[v] == 0) Dfs(v, LL, RR);
    }
  }
}
int main() {
  while (~scanf("%d%d", &n, &m)) {
    cont = 0;
    memset(head, -1, sizeof(head));
    for (int i = 0; i < m; i++) {
      int x, y, l, r;
      scanf("%d%d%d%d", &x, &y, &l, &r);
      add(x, y, l, r);
      add(y, x, l, r);
      L[i] = i;
    }
    int ans = -1;
    for (int i = 0; i < m; i++) {
      int pos = -1;
      int l = L[i];
      int r = 1000000;
      while (r - l >= 0) {
        ok = 0;
        int mid = (l + r) / 2;
        memset(vis, 0, sizeof(vis));
        Dfs(1, L[i], mid);
        if (ok == 1) {
          pos = mid;
          l = mid + 1;
        } else
          r = mid - 1;
      }
      if (pos == -1) continue;
      ans = max(ans, pos - L[i] + 1);
    }
    if (ans == -1)
      printf("Nice work, Dima!\n");
    else
      printf("%d\n", ans);
  }
}
