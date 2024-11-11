#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 200000;
const int MAX_E = 2005000;
struct {
  int to, next;
} G[MAX_E];
int head[MAX_V], si;
int val[MAX_V], fa[MAX_V];
void add_edge(int s, int t) {
  G[si].to = t;
  G[si].next = head[s];
  head[s] = si++;
}
void dfs(int v, int f) {
  fa[v] = f;
  for (int i = head[v]; i != -1; i = G[i].next) {
    if (G[i].to == f) continue;
    dfs(G[i].to, v);
  }
}
int gcd(int a, int b) {
  int mid;
  while (b != 0) {
    mid = b;
    b = a % b;
    a = mid;
  }
  return a;
}
int main() {
  int n, q, s, t, kind;
  memset(head, -1, sizeof(head));
  si = 0;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &s, &t);
    add_edge(s, t);
    add_edge(t, s);
  }
  dfs(1, -1);
  while (q--) {
    scanf("%d", &kind);
    if (kind == 1) {
      scanf("%d", &s);
      t = fa[s];
      while (t != -1) {
        if (gcd(val[s], val[t]) > 1) break;
        t = fa[t];
      }
      printf("%d\n", t);
    } else {
      scanf("%d%d", &s, &t);
      val[s] = t;
    }
  }
}
