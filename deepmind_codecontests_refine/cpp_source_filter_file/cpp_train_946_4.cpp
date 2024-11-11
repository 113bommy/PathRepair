#include <bits/stdc++.h>
using namespace std;
int n, h[100005], cnt;
double p[100005], ans = 0;
struct Edge {
  int to, next;
} w[200005];
void add(int x, int y) {
  w[++cnt] = (Edge){y, h[x]};
  h[x] = cnt;
}
void dfs(int x, int fa) {
  ans += (1 - p[x]);
  for (int i = h[x]; i; i = w[i].next) {
    int to = w[i].to;
    if (to == fa) continue;
    dfs(to, x);
    ans -= (1 - p[x]) * (1 - p[to]);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lf", &p[i]);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
  }
  dfs(1, 0);
  int m;
  scanf("%d", &m);
  while (m--) {
    int x;
    double v;
    scanf("%d%lf", &x, &v);
    ans -= 1 - p[x];
    ans += 1 - v;
    for (int i = h[x]; i; i = w[i].next) {
      int to = w[i].to;
      ans += (1 - p[x]) * (1 - p[to]);
      ans -= (1 - v) * (1 - p[to]);
    }
    p[x] = v;
    printf("%0.4lf\n", ans);
  }
}
