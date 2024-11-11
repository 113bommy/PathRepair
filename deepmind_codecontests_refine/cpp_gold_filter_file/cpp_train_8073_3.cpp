#include <bits/stdc++.h>
int L, n, p, t;
int front, tail, ans;
int f[(100010)], g[(100010)];
void push(int ff, int gg) {
  f[tail] = ff;
  g[tail++] = gg;
}
void update(int &nf, int &ng, int lf, int l, int r) {
  if (lf + (r - l) / p > nf) {
    nf = lf + (r - l) / p;
    ng = l + (r - l) / p * p;
  } else if (lf + (r - l) / p == nf && l + (r - l) / p * p < ng) {
    ng = l + (r - l) / p * p;
  }
}
int main() {
  scanf("%d%d%d%d", &L, &n, &p, &t);
  push(0, -t);
  while (n--) {
    int l, r;
    int now_f = 0, now_g = 0;
    scanf("%d%d", &l, &r);
    if (front) front--;
    while (front < tail) {
      if (g[front] + t > r) break;
      update(now_f, now_g, f[front], std::max(l, g[front] + t), r);
      ++front;
    }
    if (ans < now_f) {
      ans = now_f;
      push(now_f, now_g);
    }
  }
  printf("%d\n", ans);
  return 0;
}
