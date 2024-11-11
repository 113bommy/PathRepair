#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, d, e, ad;
inline long long S1(int a, int b) {
  return 1ll * (a + b - 3) * (a + b - 3 + 1) / 2;
}
struct point {
  int x, y;
  point(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
};
long long G, S, H, t;
point zs, yx, zx, ys;
long long jia(int a, int b) { return 1ll * (a + b) * (b - a + 1) / 2; }
int suan(point a, point b) { return abs(a.x - b.x) + abs(a.y - b.y); }
long long work1(point now, point st) {
  long long A = 0;
  if (now.y < st.y)
    A += jia(suan(st, point(now.x, st.y)), suan(st, point(now.x, now.y + 1)));
  A += jia(suan(st, point(now.x + 1, max(now.y, st.y))), suan(st, point(n, n)));
  return A;
}
long long work2(point now, point st) {
  long long A = 0;
  if (now.x < st.x)
    A += jia(suan(st, point(st.x, now.y)), suan(st, point(now.x + 1, now.y)));
  if (now.y < n)
    A += jia(suan(st, point(st.x, now.y + 1)), suan(st, point(n, n)));
  return A;
}
bool can(long long A, long long B, long long C, long long D, point now) {
  if (now.x == n && now.y == n) return 1;
  if (now.x > yx.x) {
    A -= work1(now, zs);
    if (A < 0) return 0;
    B -= work1(now, yx);
    if (B < 0) return 0;
    C -= work1(now, zx);
    if (C < 0) return 0;
    D -= work1(now, ys);
    if (D < 0) return 0;
    return 1;
  } else if (now.y >= yx.y && now.y <= zs.y) {
    A -= H, B -= H;
    if (A < 0 || B < 0) return 0;
    long long SUM = 1ll * (zs.y - now.y + yx.x - now.x) * ad;
    long long Min = jia(1, zs.y - now.y - 1) +
                    1ll * (zs.y - now.y) * (now.x - zs.x) +
                    jia(now.x - zs.x + 1, c - 1);
    long long Max =
        jia(now.x - zs.x + 1, c - 1) + 1ll * (c - 1) * (zs.y - now.y) +
        1ll * (yx.x - now.x) * (zs.y - now.y) + jia(1, zs.y - now.y - 1);
    if (A < Min) return 0;
    if ((A - Min) & 1)
      Min = min(A - 1, Max);
    else
      Min = min(A, Max);
    SUM -= Min;
    if (B < SUM) return 0;
    if (C < jia(suan(zx, point(now.x, now.y + 1)), suan(zx, point(n, n))))
      return 0;
    if (D <
        S1(ys.x - now.x + 1, ys.y - now.y + 1) + jia(1, suan(ys, point(n, n))))
      return 0;
    return 1;
  } else if (now.y > zs.y) {
    A -= jia(suan(zs, point(now.x + 1, now.y)), suan(zs, point(n, n)));
    if (A < 0) return 0;
    C -= jia(suan(zx, point(now.x + 1, now.y)), suan(zx, point(n, n)));
    if (C < 0) return 0;
    B -= work2(now, yx);
    if (B < 0) return 0;
    D -= work2(now, ys);
    if (D < 0) return 0;
    return 1;
  } else {
    A -= jia(suan(zs, point(now.x, yx.y)), suan(zs, point(now.x, now.y + 1)));
    if (A < 0) return 0;
    B -= jia(suan(yx, point(now.x, yx.y)), suan(yx, point(now.x, now.y + 1)));
    if (B < 0) return 0;
    C -= jia(suan(zx, point(now.x, yx.y)), suan(zx, point(now.x, now.y + 1)));
    if (C < 0) return 0;
    D -= jia(suan(ys, point(now.x, yx.y)), suan(ys, point(now.x, now.y + 1)));
    if (D < 0) return 0;
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
  G += H;
  if (ad >= 1) G += 1ll * (ad - 1) * ((ad - 1) >> 1) + c;
  if ((ad - 1) & 1) G += c - 1;
  long long WW =
      max(S1(a, b) + S1(n - a + 1, n - b + 1) + suan(point(a, b), point(n, n)),
          S1(d, e) + S1(n - d + 1, n - e + 1) + suan(point(d, e), point(n, n)));
  if (WW > t || G > t)
    cout << "Impossible";
  else {
    long long AA = t, BB = t, CC = t, DD = t;
    if (zs.x >= 2) AA -= jia(suan(zs, point(zs.x, 1)), suan(zs, point(2, 1)));
    if (zs.x >= 2) BB -= jia(suan(yx, point(zs.x, 1)), suan(yx, point(2, 1)));
    if (zs.x >= 2) CC -= jia(suan(zx, point(zs.x, 1)), suan(zx, point(2, 1)));
    if (zs.x >= 2) DD -= jia(suan(ys, point(zs.x, 1)), suan(ys, point(2, 1)));
    point NOW = point(zs.x, 1);
    for (int i = 1; i <= zs.x - 1; i++) cout << "R";
    while (1) {
      if (NOW.x == n && NOW.y == n) break;
      if (NOW.x == n)
        cout << "U", NOW.y++;
      else if (NOW.y == n)
        cout << "R", NOW.x++;
      else {
        point tt = NOW;
        tt.x++;
        int A_ = suan(tt, zs), B_ = suan(tt, yx), C_ = suan(tt, zx),
            D_ = suan(tt, ys);
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
  }
  return 0;
}
