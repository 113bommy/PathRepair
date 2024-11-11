#include <bits/stdc++.h>
int ans = 0;
double H = 100, len = 100000;
int F[110000], T[110000], FF[110000], TT[110000];
bool vis[110000];
int judge(bool fuck, double st, double t) {
  int ret = 0;
  int top, flo;
  double point = st;
  memset(vis, 0, sizeof(vis));
  while (point < len) {
    top = (int)ceil(point);
    flo = (int)floor(point);
    if (fuck) {
      if (T[top] < 0 || T[flo] < 0 || T[top] != T[flo]) {
        return -1;
      }
      if (vis[TT[top]] == 1) return -1;
      ret += T[top];
      vis[TT[top]] = 1;
      fuck = !fuck;
    } else {
      if (F[top] < 0 || F[flo] < 0 || F[top] != F[flo]) {
        return -1;
      }
      if (vis[FF[top]] == 1) return -1;
      ret += F[top];
      vis[FF[top]] = 1;
      fuck = !fuck;
    }
    point += t;
  }
  if (ans < ret) ans = ret;
  return ret;
}
int work() {
  int n, i, j, val, x, y;
  char c;
  double A, B, t;
  double hl, hr;
  scanf("%lf%lf%d", &hl, &hr, &n);
  memset(T, -1, sizeof(T));
  memset(F, -1, sizeof(F));
  for (i = 1; i <= n; i++) {
    scanf("%d %c%d%d", &val, &c, &x, &y);
    if (c == 'T') {
      for (j = x; j <= y; j++) T[j] = val, TT[j] = i;
    } else {
      for (j = x; j <= y; j++) F[j] = val, FF[j] = i;
    }
  }
  A = hl / H;
  B = hr / H;
  for (i = 0; i <= 100; i++) {
    if ((i & 1) == 0) {
      t = len / (A + B + i);
      judge(0, A * t, t);
    }
    if ((i & 1) == 1) {
      t = len / ((1 - A) + B + i);
      judge(1, (1 - A) * t, t);
    }
    if ((i & 1) == 1) {
      t = len / (A + (1 - B) + i);
      judge(0, A * t, t);
    }
    if ((i & 1) == 0) {
      t = len / ((1 - A) + (1 - B) + i);
      judge(1, (1 - A) * t, t);
    }
  }
  printf("%d\n", ans);
  return 1;
}
int main() {
  work();
  return 0;
}
