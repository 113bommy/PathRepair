#include <bits/stdc++.h>
using namespace std;
int U[1000100], V[1000100];
int n, m;
struct edge {
  int v, next;
} e[1000100];
int head[1000100], tot, in[1000100], vis[1000100];
void init() {
  memset((head), (-1), sizeof(head));
  memset((in), (0), sizeof(in));
  tot = 0;
}
void Add(int u, int v) {
  e[tot].v = v;
  e[tot].next = head[u];
  head[u] = tot++;
}
bool judge(int x) {
  init();
  for (int i = 1; i <= x; i++) {
    Add(U[i], V[i]);
    in[V[i]]++;
  }
  queue<int> qu;
  for (int i = 1; i <= n; i++) {
    if (in[i] == 0) qu.push(i);
  }
  while (!qu.empty()) {
    int now = qu.front();
    qu.pop();
    if (qu.size() > 0) return false;
    for (int i = head[now]; i != -1; i = e[i].next) {
      int v = e[i].v;
      in[v]--;
      if (in[v] == 0) {
        qu.push(v);
      }
    }
  }
  return true;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) scanf("%d%d", &U[i], &V[i]);
  int l = 1, r = m, mid, ans = -1;
  while (l < r) {
    mid = (l + r) / 2;
    if (judge(mid)) {
      r = mid;
      ans = mid;
    } else
      l = mid + 1;
  }
  cout << ans << endl;
  return 0;
}
