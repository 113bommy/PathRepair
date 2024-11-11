#include <bits/stdc++.h>
using namespace std;
namespace TYC {
const int N = 10010;
const int inf = 0x3f3f3f3f;
int n, s, t, ss, arr[N], Head[N], pre[N], dis[N], vis[N];
struct edge {
  int to, next, w, c;
} E[N * 20];
void add(int u, int v, int w, int c) {
  static int cnt = 1;
  E[++cnt] = (edge){v, Head[u], w, c};
  Head[u] = cnt;
  E[++cnt] = (edge){u, Head[v], 0, -c};
  Head[v] = cnt;
}
bool spfa() {
  queue<int> q;
  memset(pre, 0, sizeof(pre));
  for (int i = 1; i <= t; i++) dis[i] = -inf;
  q.push(s);
  dis[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = Head[u]; i; i = E[i].next) {
      int v = E[i].to;
      if (E[i].w && dis[v] < dis[u] + E[i].c) {
        dis[v] = dis[u] + E[i].c;
        pre[v] = i;
        if (!vis[v]) q.push(v), vis[v] = 1;
      }
    }
  }
  return dis[t] != -inf;
}
int mcmf() {
  int ans = 0;
  while (spfa()) {
    for (int i = pre[t]; i; i = pre[E[i ^ 1].to]) E[i].w--, E[i ^ 1].w++;
    ans += dis[t];
  }
  return ans;
}
void work() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
  s = n + n + 1, ss = s + 1, t = ss + 1;
  add(s, ss, 4, 0);
  for (int i = 1; i <= n; i++) {
    add(ss, i, 1, 0);
    add(i, i + n, 1, 1);
    add(i, i + n, inf, 0);
    for (int j = i + 1; j <= n; j++)
      if (arr[i] - arr[j] == 1) {
        add(i + n, j, inf, 0);
        break;
      }
    for (int j = i + 1; j <= n; j++)
      if (arr[j] - arr[i] == 1) {
        add(i + n, j, inf, 0);
        break;
      }
    for (int j = i + 1; j <= n; j++)
      if (arr[j] % 7 == arr[i] % 7) {
        add(i + n, j, inf, 0);
        break;
      }
    add(i + n, t, 1, 0);
  }
  printf("%d\n", mcmf());
}
}  // namespace TYC
int main() {
  TYC::work();
  return 0;
}
