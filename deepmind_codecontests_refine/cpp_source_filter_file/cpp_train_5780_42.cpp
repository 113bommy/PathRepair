#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, num[100010], w[100010];
int x[100010], y[100010];
struct edge {
  int w, f, id;
} e[100010];
inline bool operator<(edge a, edge b) { return a.w < b.w; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &e[i].w, &e[i].f);
    e[i].id = i;
  }
  sort(e + 1, e + m + 1);
  for (int i = 1; i <= m; i++) {
    if (e[i].f) {
      cnt++;
      num[cnt] = cnt - 1;
      w[cnt] = e[i].w;
      x[e[i].id] = cnt;
      y[e[i].id] = cnt + 1;
    }
  }
  int now = cnt;
  for (int i = m; i >= 1; i--) {
    if (e[i].f) continue;
    while (w[now] >= e[i].w && now) now--;
    if (now == 0 || now == 1) {
      puts("-1");
      return 0;
    }
    y[e[i].id] = now + 1;
    x[e[i].id] = num[now];
    num[now]--;
    if (num[now] == 0) now--;
  }
  for (int i = 1; i <= m; i++) {
    printf("%d %d\n", x[i], y[i]);
  }
  return 0;
}
