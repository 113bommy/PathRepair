#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
struct pnt {
  long long x, y;
  pnt(long long _x = 0, long long _y = 0) {
    x = _x;
    y = _y;
  }
  pnt operator+(const pnt &a) { return pnt(x + a.x, y + a.y); }
  friend pnt operator-(const pnt &a, const pnt &b) {
    return pnt(a.x - b.x, a.y - b.y);
  }
  pnt operator*(const long long &a) { return pnt(x * a, y * a); }
  pnt operator/(const long long &a) { return pnt(x / a, y / a); }
  long long operator*(const pnt &a) {
    return (long long)x * a.y - (long long)y * a.x;
  }
  double mo() { return sqrt((double)x * x + (double)y * y); }
};
int sgn(long long x) { return x ? (x > 0 ? 1 : -1) : 0; }
int n, m;
pnt a[N];
vector<pnt> S;
pnt e[4] = {pnt(0, 0), pnt(1e5, 0), pnt(1e5, 1e5), pnt(0, 1e5)};
void wrk(pnt a, pnt b) {
  for (int i = 0; i < 4; i++) {
    pnt x = e[i], y = e[i + 1 == 4 ? 0 : i + 1];
    long long s1 = (a - x) * (b - x), s2 = (a - y) * (b - y);
    if (sgn(s1) * sgn(s2) < 0) S.push_back(x + (y - x) * s1 / (s1 + s2));
  }
}
void convex() {
  static pnt sta[N];
  int top = 0;
  sort(a + 1, a + m + 1, [](const pnt &a, const pnt &b) {
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
  });
  sta[top = 1] = a[1];
  sort(a + 2, a + m + 1, [](const pnt &a, const pnt &b) {
    long long k = (a - sta[1]) * (b - sta[1]);
    if (k) return k > 0;
    return (a - sta[1]).mo() < (b - sta[1]).mo();
  });
  for (int i = 2; i <= m; i++) {
    while (top > 1 && (a[i] - sta[top - 1]) * (sta[top] - sta[top - 1]) >= 0)
      --top;
    sta[++top] = a[i];
  }
  for (int i = 1; i <= top; i++) a[i] = sta[i];
  m = top;
}
int main() {
  scanf("%d", &n);
  for (int i = 1, x, y, v; i <= n; i++) {
    scanf("%d%d%d", &x, &y, &v);
    S.clear();
    S.push_back(pnt(x + v, y));
    S.push_back(pnt(x, y + v));
    S.push_back(pnt(x - v, y));
    S.push_back(pnt(x, y - v));
    S.push_back(e[0]);
    S.push_back(e[1]);
    S.push_back(e[2]);
    S.push_back(e[3]);
    for (int i = 0; i < 4; i++) wrk(S[i], S[i + 1 == 4 ? 0 : i + 1]);
    for (pnt t : S)
      if (abs(t.x - x) + abs(t.y - y) <= v && t.x >= 0 && t.x <= 1e5 &&
          t.y >= 0 && t.y <= 1e5)
        a[++m] = t;
  }
  convex();
  pnt A, B, C;
  double as = 0;
  for (int i = 1; i <= m; i++) {
    pnt x = a[i], y = a[(i + 1 > m ? i + 1 - m : i + 1)],
        z = a[(i + 2 > m ? i + 2 - m : i + 2)];
    double now =
        (x - y).mo() * (y - z).mo() * (z - x).mo() / fabs((y - x) * (z - x));
    if (now > as) as = now, A = x, B = y, C = z;
  }
  printf("%lld %lld\n", A.x, A.y);
  printf("%lld %lld\n", B.x, B.y);
  printf("%lld %lld\n", C.x, C.y);
  return 0;
}
