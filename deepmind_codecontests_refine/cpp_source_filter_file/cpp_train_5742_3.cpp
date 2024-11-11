#include <bits/stdc++.h>
using namespace std;
int n, m, k;
const int MAXN = 200005;
struct edge {
  int v, id, next;
} e[MAXN << 1];
int head[MAXN], cnt, ans, col[MAXN], res[MAXN];
int du[MAXN];
inline void add(int u, int v, int id) {
  e[cnt] = (edge){v, id, head[u]}, head[u] = cnt++;
}
int main() {
  memset(head, -1, sizeof head);
  scanf("%d%d", &n, &k);
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d %d", &u, &v);
    add(u, v, i);
    add(v, u, i);
    du[u]++, du[v]++;
  }
  int rt = 0;
  for (int i = 1; i <= n; i++)
    if (du[i] > du[rt]) rt = i;
  sort(du + 1, du + 1 + n, greater<int>());
  printf("%d\n", ans = du[k + 1]);
  queue<int> que;
  que.push(rt);
  while (que.size()) {
    int d = que.front();
    que.pop();
    int cnt = col[d];
    for (int i = head[d]; ~i; i = e[i].next) {
      if (col[e[i].v]) continue;
      ++cnt;
      if (cnt > ans) cnt -= ans;
      col[e[i].v] = cnt;
      res[e[i].id] = cnt;
      que.push(e[i].v);
    }
  }
  for (int i = 1; i < n; i++) printf("%d ", res[i]);
  return 0;
}
