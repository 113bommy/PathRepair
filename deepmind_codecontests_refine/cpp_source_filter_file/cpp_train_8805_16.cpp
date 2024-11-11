#include <bits/stdc++.h>
using namespace std;
const int N = 205;
const int inf = 0x3f3f3f3f;
struct node {
  int to, next, w, c;
} num[N * 10];
queue<int> q;
int cnt = 1, sc, S, T, dis[N], head[N], n, a[N], c[N], ans, k, pre[N], prevv[N],
    preve[N], t[1000005];
void add(int x, int y, int w, int c) {
  num[++cnt].to = y;
  num[cnt].next = head[x];
  num[cnt].w = w;
  num[cnt].c = c;
  head[x] = cnt;
  num[++cnt].to = x;
  num[cnt].next = head[y];
  num[cnt].w = -w;
  num[cnt].c = 0;
  head[y] = cnt;
}
void build() {
  for (int i = 1; i < n; i++) add(i, i + 1, 0, k - 1);
  for (int i = 1; i <= n; i++)
    if (pre[i] && pre[i] != i - 1) {
      add(S, pre[i], 0, 1);
      add(pre[i], ++sc, 0, 1);
      add(i, sc, -c[a[i]], 1);
      add(sc, T, 0, 1);
    }
}
void spfa() {
  q.push(S);
  memset(dis, inf, sizeof(dis));
  dis[S] = 0;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int i = head[now]; i; i = num[i].next)
      if (num[i].c && dis[num[i].to] > dis[now] + num[i].w) {
        dis[num[i].to] = dis[now] + num[i].w, q.push(num[i].to);
        prevv[num[i].to] = now;
        preve[num[i].to] = i;
      }
  }
}
void solve() {
  while (1 == 1) {
    spfa();
    if (dis[T] == inf) break;
    int sum = 0;
    for (int i = T, it; i != S; i = prevv[i])
      it = preve[i], sum += num[it].w, num[it].c--, num[it ^ 1].c++;
    ans += sum;
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
  for (int i = 1; i <= n; i++) {
    pre[i] = t[a[i]];
    t[a[i]] = i;
    if (i == 1 || pre[i] != i - 1) ans += c[a[i]];
  }
  S = n + 1;
  T = sc = S + 1;
  build();
  solve();
  printf("%d\n", ans);
  return 0;
}
