#include <bits/stdc++.h>
using namespace std;
struct point {
  point(long long int _x = 0LL, long long int _y = 0LL) : x(_x), y(_y) {}
  long long int x, y;
  inline bool operator<(const point &b) const {
    return x == b.x ? y < b.y : x < b.x;
  }
  inline long long int length() const { return x * 1LL * x + y * 1LL * y; }
  void print() const { printf("%lld %lld\n", x, y); }
};
int N, M;
vector<point> V, H;
point v1, v2, v3;
long double Ans;
inline point operator-(const point &a, const point &b) {
  return point(a.x - b.x, a.y - b.y);
}
inline long long int cross(const point &p1, const point &p2, const point &p3) {
  return (p2.x - p1.x) * 1LL * (p3.y - p1.y) -
         (p3.x - p1.x) * 1LL * (p2.y - p1.y);
}
void build_Convex() {
  sort(V.begin(), V.end());
  for (int iter = 0, rec; iter <= 1; ++iter) {
    rec = H.size();
    for (int i = 0; i < V.size(); ++i) {
      while (H.size() > rec + 1 &&
             cross(H[H.size() - 2], H[H.size() - 1], V[i]) <= 0LL)
        H.pop_back();
      H.push_back(V[i]);
    }
    H.pop_back(), reverse(V.begin(), V.end());
  }
}
inline long long int det(const point &a, const point &b) {
  return a.x * 1LL * b.y - a.y * 1LL * b.x;
}
inline long double js(long double a, long double b) { return a * a + b * b; }
inline void update(const point &a, const point &b, const point &c) {
  point bb = b - a, cc = c - a;
  long long int db = bb.length(), dc = cc.length(), d = 2LL * det(bb, cc);
  long double temp = js((bb.y * dc - cc.y * db) / (d * 1.0),
                        (cc.x * db - bb.x * dc) / (d * 1.0));
  if (temp > Ans) Ans = temp, v1 = a, v2 = b, v3 = c;
}
int main() {
  scanf("%d", &N), M = 100000;
  for (int x, y, v; N--;) {
    scanf("%d%d%d", &x, &y, &v);
    if (x - v >= 0)
      V.push_back(point(x - v, y));
    else
      V.push_back(point(0, min(y + v - x, M))),
          V.push_back(point(0, max(y - v + x, 0)));
    if (x + v <= M)
      V.push_back(point(x + v, y));
    else
      V.push_back(point(M, min(y + (v + x - M), M))),
          V.push_back(point(M, max(y - (v + x - M), 0)));
    if (y - v >= 0)
      V.push_back(point(x, y - v));
    else
      V.push_back(point(min(x + (v - y), M), 0)),
          V.push_back(point(max(x - (v - y), 0), 0));
    if (y + v <= M)
      V.push_back(point(x, y + v));
    else
      V.push_back(point(min(x + (v + y - M), M), M)),
          V.push_back(point(max(x - (v + y - M), 0), M));
  }
  build_Convex();
  for (int a = 0, b, c; a < H.size(); ++a) {
    b = (a + 1) % H.size();
    c = (b + 1) % H.size();
    update(H[a], H[b], H[c]);
  }
  v1.print(), v2.print(), v3.print();
  return 0;
}
