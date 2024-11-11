#include <bits/stdc++.h>
const int MAXN = 2e4 + 10, INF = 1e8, RP = 1000, QY = 3;
int n, m, now, last, top;
int X[MAXN], Y[MAXN], q[MAXN];
inline int ask(int x, int y) {
  int ans;
  printf("0 %d %d\n", x, y);
  fflush(stdout);
  scanf("%d", &ans);
  return ans;
}
inline int RP_x(int k) {
  for (int i = 1; i <= QY; ++i)
    if (ask(rand() % ((INF << 1) + 1) - INF, k)) return 0;
  return 1;
}
inline int RP_y(int k) {
  for (int i = 1; i <= QY; ++i)
    if (ask(k, rand() % ((INF << 1) + 1) - INF)) return 0;
  return 1;
}
int main() {
  srand(time(0));
  for (now = -INF; now <= INF;) {
    int ans = ask(now, now);
    if (!ans) {
      q[++top] = now;
      if (now + RP <= 1e8 && ask(now + RP, now + RP) == RP)
        now += RP;
      else
        ++now;
    } else {
      last = now;
      now += ans;
    }
  }
  for (int i = 1; i <= top; ++i) {
    if (!ask(last, q[i])) Y[++m] = q[i];
    if (!ask(q[i], last)) X[++n] = q[i];
  }
  printf("1 %d %d\n", m, n);
  for (int i = 1; i < m; ++i) printf("%d ", Y[i]);
  printf("%d\n", Y[m]);
  for (int i = 1; i < n; ++i) printf("%d ", X[i]);
  printf("%d\n", X[n]);
  return 0;
}
