#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 20;
const long long MAXN = 1e9 + 9;
const long long MOD = 1e9 + 7;
int n;
long long h, w;
char ch[N];
int opr[N];
int l[5] = {0, 1, -1, 0, 0};
int r[5] = {0, 0, 0, 1, -1};
long long ans;
struct Square {
  long long x, y;
  long long lx, ly;
  long long rx, ry;
  long long h, w;
  Square() { x = y = lx = ly = rx = ry = h = w = 0; }
  void reset(int mov) {
    x += l[mov];
    y += r[mov];
    lx = min(x, lx), ly = min(y, ly);
    rx = max(x, rx), ry = max(y, ry);
    h = rx - lx + 1;
    w = ry - ly + 1;
  }
} p[N], pn, pi, pni;
void init() {
  scanf("%d%I64d%I64d", &n, &h, &w);
  scanf("%s", ch);
  for (int i = 1; i <= n; i++) {
    switch (ch[i - 1]) {
      case 'U':
        opr[i] = 1;
        break;
      case 'D':
        opr[i] = 2;
        break;
      case 'R':
        opr[i] = 3;
        break;
      case 'L':
        opr[i] = 4;
        break;
      default:
        break;
    }
  }
  ans = w * h;
}
Square trans(Square A) {
  Square B;
  B.lx = 1 - A.lx;
  B.ly = 1 - A.ly;
  B.rx = h - A.rx;
  B.ry = w - A.ry;
  return B;
}
Square add(Square A, Square B) {
  Square C;
  C.lx = max(A.lx, B.lx), C.ly = max(A.ly, B.ly);
  C.rx = min(A.rx, B.rx), C.ry = min(A.ry, B.ry);
  C.h = C.rx - C.lx + 1;
  C.w = C.ry - C.ly + 1;
  return C;
}
bool pd(Square A) { return (A.lx <= A.rx && A.ly <= A.ry); }
void work() {
  p[0].x = p[0].y = p[0].lx = p[0].ly = p[0].rx = p[0].ry = 0;
  p[0].w = p[0].h = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1];
    p[i].reset(opr[i]);
  }
  long long dx, dy, cir, cirx, ciry;
  bool one;
  dx = abs(p[n].x), dy = abs(p[n].y);
  if (dx == 0 && dy == 0 && p[n].h <= h && p[n].w <= w) {
    printf("-1\n");
    return;
  }
  pn = trans(p[n]);
  one = pd(pn);
  if (one) {
    pn.lx += p[n].x, pn.ly += p[n].y;
    pn.rx += p[n].x, pn.ry += p[n].y;
  }
  for (int i = 1; i <= n; i++) {
    long long h1 = h - p[i].h + 1, w1 = w - p[i].w + 1;
    if (h1 <= 0 || w1 <= 0) continue;
    ans += w1 * h1;
    if (ans >= MOD) ans %= MOD;
    if (one) {
      pi = trans(p[i]);
      if (pd(pi)) {
        pni = add(pn, pi);
        if (pd(pni)) {
          long long h0, w0, cir0;
          h0 = pni.h, w0 = pni.w;
          cirx = dx == 0 ? MAXN : h0 / dx;
          ciry = dy == 0 ? MAXN : w0 / dy;
          cir0 = min(cirx, ciry);
          h0 -= dx * cir0, w0 -= dy * cir0, cir0++;
          ans += w0 * h0 * cir0;
          if (ans >= MOD) ans %= MOD;
          ans += ((cir0 * (cir0 - 1LL) / 2LL * dx) % MOD) * w0 +
                 ((cir0 * (cir0 - 1LL) / 2LL * dy) % MOD) * h0;
          if (ans >= MOD) ans %= MOD;
          ans +=
              (((((cir0 - 1LL) * cir0 * (2LL * cir0 - 1LL) / 6LL) % MOD) * dx) %
               MOD) *
              dy;
          if (ans >= MOD) ans %= MOD;
        }
      }
    }
  }
  printf("%I64d\n", ans);
}
int main() {
  init();
  work();
  return 0;
}
