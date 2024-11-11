#include <bits/stdc++.h>
using namespace std;
int n;
long long t;
int a, b, c, d, e, ad;
long long S1(int a, int b) { return 1ll * (a + b - 3) * (a + b - 3 + 1) / 2; }
struct point {
  int x, y;
  point(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
};
long long G, S, H;
point zs, yx, zx, ys;
long long jia(int a, int b) { return 1ll * (a + b) * (b - a + 1) / 2; }
int suan(point a, point b) { return abs(a.x - b.x) + abs(a.y - b.y); }
bool can(long long A, long long B, long long C, long long D, point now) {
  if (now.x == n && now.y == n) return 1;
  if (now.x > yx.x) {
    long long A_ = 0;
    if (now.y < zs.y)
      A_ +=
          jia(suan(zs, point(now.x, zs.y)), suan(zs, point(now.x, now.y + 1)));
    A_ += jia(suan(zs, point(now.x + 1, max(now.y, zs.y))),
              suan(zs, point(n, n)));
    if (A_ > A) return 0;
    long long B_ = 0;
    if (now.y < yx.y)
      B_ +=
          jia(suan(yx, point(now.x, yx.y)), suan(yx, point(now.x, now.y + 1)));
    B_ += jia(suan(yx, point(now.x + 1, max(now.y, yx.y))),
              suan(yx, point(n, n)));
    if (B_ > B) return 0;
    long long C_ = 0;
    if (now.y < zx.y)
      C_ +=
          jia(suan(zx, point(now.x, zx.y)), suan(zx, point(now.x, now.y + 1)));
    C_ += jia(suan(zx, point(now.x + 1, max(now.y, zx.y))),
              suan(zx, point(n, n)));
    if (C_ > C) return 0;
    long long D_ = 0;
    if (now.y < ys.y)
      D_ +=
          jia(suan(ys, point(now.x, ys.y)), suan(ys, point(now.x, now.y + 1)));
    D_ += jia(suan(ys, point(now.x + 1, max(now.y, ys.y))),
              suan(ys, point(n, n)));
    if (D_ > D) return 0;
    return 1;
  } else if (now.y >= yx.y && now.y <= zs.y) {
    if (A < H || B < H) return 0;
    A -= H, B -= H;
    long long SUM = 1ll * (zs.y - now.y + yx.x - now.x) * ad;
    long long Min, Max;
    Min = jia(1, zs.y - now.y - 1) + 1ll * (zs.y - now.y) * (now.x - zs.x) +
          jia(now.x - zs.x + 1, c - 1);
    Max = jia(now.x - zs.x + 1, c - 1) + 1ll * (c - 1) * (zs.y - now.y) +
          1ll * (yx.x - now.x) * (zs.y - now.y) + jia(1, zs.y - now.y - 1);
    if (A < Min) return 0;
    if ((A - Min) & 1)
      Min = min(A - 1, Max);
    else
      Min = min(A, Max);
    SUM -= Min;
    if (B < SUM) return 0;
    A = jia(suan(zx, point(now.x, now.y + 1)), suan(zx, point(n, n)));
    if (A > C) return 0;
    A = S1(ys.x - now.x + 1, ys.y - now.y + 1) + jia(1, suan(ys, point(n, n)));
    if (A > D) return 0;
    return 1;
  } else if (now.y > zs.y) {
    long long A_ =
        jia(suan(zs, point(now.x + 1, now.y)), suan(zs, point(n, n)));
    if (A_ > A) return 0;
    long long C_ =
        jia(suan(zx, point(now.x + 1, now.y)), suan(zx, point(n, n)));
    if (C_ > C) return 0;
    long long B_;
    if (now.x < yx.x)
      B_ = jia(suan(yx, point(yx.x, now.y)), suan(yx, point(now.x + 1, now.y)));
    if (now.y < n)
      B_ = jia(suan(yx, point(yx.x, now.y + 1)), suan(yx, point(n, n)));
    if (B_ > B) return 0;
    long long D_;
    if (now.x < ys.x)
      D_ = jia(suan(ys, point(ys.x, now.y)), suan(ys, point(now.x + 1, now.y)));
    if (now.y < n)
      D_ = jia(suan(ys, point(ys.x, now.y + 1)), suan(ys, point(n, n)));
    if (D_ > D) return 0;
    return 1;
  } else {
    long long A_ =
        jia(suan(zs, point(now.x, yx.y)), suan(zs, point(now.x, now.y + 1)));
    if (A_ > A) return 0;
    A -= A_;
    long long B_ =
        jia(suan(yx, point(now.x, yx.y)), suan(yx, point(now.x, now.y + 1)));
    if (B_ > B) return 0;
    B -= B_;
    long long C_ =
        jia(suan(zx, point(now.x, zx.y)), suan(zx, point(now.x, now.y + 1)));
    if (C_ > C) return 0;
    C -= C_;
    long long D_ =
        jia(suan(ys, point(now.x, ys.y)), suan(ys, point(now.x, now.y + 1)));
    if (D_ > D) return 0;
    D -= D_;
    return can(A, B, C, D, point(now.x, yx.y));
  }
}
int main() {
  scanf("%d%lld%d%d%d", &n, &t, &a, &b, &c);
  d = a + c - 1, e = b + c - 1, ad = 2 * c - 2;
  zs = point(a, e), yx = point(d, b);
  zx = point(a, b), ys = point(d, e);
  G = S1(a, b) + 1ll * (c - 1) * (a + b - 2);
  H = S1(n - d + 1, n - e + 1) + 1ll * (c - 1) * (n - d + n - e) +
      (n - d + n - e);
  if (ad >= 1) S = 1ll * (ad - 1) * ((ad - 1) >> 1) + c;
  if ((ad - 1) & 1) S += c - 1;
  G += S + H;
  long long WW =
      max(S1(a, b) + S1(n - a + 1, n - b + 1) + suan(point(a, b), point(n, n)),
          S1(d, e) + S1(n - d + 1, n - e + 1) + suan(point(d, e), point(n, n)));
  if (WW > t || G > t)
    cout << "Impossible";
  else {
    long long AA = t;
    if (zs.x >= 2) AA -= jia(suan(zs, point(zs.x, 1)), suan(zs, point(2, 1)));
    long long BB = t;
    if (zs.x >= 2) BB -= jia(suan(yx, point(zs.x, 1)), suan(yx, point(2, 1)));
    long long CC = t;
    if (zs.x >= 2) CC -= jia(suan(zx, point(zs.x, 1)), suan(zx, point(2, 1)));
    long long DD = t;
    if (zs.x >= 2) DD -= jia(suan(ys, point(zs.x, 1)), suan(ys, point(2, 1)));
    point NOW = point(zs.x, 1);
    for (int i = 1; i <= zs.x - 1; i++) cout << "R";
    while (1) {
      if (NOW.x == n && NOW.y == n) break;
      if (NOW.x == n) {
        while (NOW.y < n) cout << "U", NOW.y++;
        break;
      }
      if (NOW.y == n) {
        while (NOW.x < n) cout << "R", NOW.x++;
        break;
      }
      point tt = NOW;
      tt.x++;
      int A_ = suan(tt, zs);
      int B_ = suan(tt, yx);
      int C_ = suan(tt, zx);
      int D_ = suan(tt, ys);
      if (AA >= A_ && BB >= B_ && CC >= C_ && DD >= D_ &&
          can(AA - A_, BB - B_, CC - C_, DD - D_, tt)) {
        AA -= A_, BB -= B_, CC -= C_, DD -= D_;
        NOW = tt;
        cout << "R";
      } else {
        NOW.y++;
        AA -= suan(NOW, zs);
        BB -= suan(NOW, yx);
        CC -= suan(NOW, zx);
        DD -= suan(NOW, ys);
        cout << "U";
      }
    }
  }
  return 0;
}
