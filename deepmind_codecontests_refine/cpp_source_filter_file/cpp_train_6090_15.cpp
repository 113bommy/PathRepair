#include <bits/stdc++.h>
using namespace std;
const int maxn = 2E6 + 5;
const long double eps = 1E-9;
const long double inf = 1E18;
const int limit = 1000000;
int n, tot;
inline bool same(long double x, long double y) { return abs(x - y) <= eps; }
struct pt {
  long double x, y;
  pt(long double a = 0, long double b = 0) : x(a), y(b) {}
  pt operator+(const pt& A) { return pt(x + A.x, y + A.y); }
  pt operator-(const pt& A) { return pt(x - A.x, y - A.y); }
  pt operator*(const long double& d) { return pt(x * d, y * d); }
  pt operator/(const long double& d) { return pt(x / d, y / d); }
  long double operator*(const pt& A) { return x * A.y - y * A.x; }
  bool operator!=(const pt& A) { return !(same(x, A.x) && same(y, A.y)); }
} P[maxn], P2[maxn];
struct line {
  pt A, B;
  line(pt a = pt(), pt b = pt()) : A(a), B(b) {}
};
inline pt intersection(line x, line y) {
  pt A = y.B - y.A, B = x.B - x.A, C = y.A - x.A;
  if (abs(A * B) <= eps) return pt(inf, inf);
  long double d = -(B * C) / (B * A);
  return y.A + A * d;
}
inline long double dis(pt A, pt B) {
  return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}
inline line getP(pt A, pt B) {
  pt C = (A + B) / 2;
  return line(C, C + pt(A.y - B.y, B.x - A.x));
}
inline long double get(pt A, pt B, pt C) {
  pt D = intersection(getP(A, B), getP(B, C));
  return dis(A, D);
}
inline void add(int x, int y) { P[++tot] = pt(x, y); }
inline void addD(int x, int y, int d) {
  if (y - d >= 0)
    P[++tot] = pt(x, y - d);
  else {
    int len = d - y;
    P[++tot] = pt(max(0, x - len), 0);
    P[++tot] = pt(min(limit, x + len), 0);
  }
}
inline void addL(int x, int y, int d) {
  if (x - d >= 0)
    P[++tot] = pt(x - d, y);
  else {
    int len = d - x;
    P[++tot] = pt(0, max(0, y - len));
    P[++tot] = pt(0, min(limit, y + len));
  }
}
inline void addU(int x, int y, int d) {
  if (y + d <= limit)
    P[++tot] = pt(x, y + d);
  else {
    int len = y + d - limit;
    P[++tot] = pt(max(0, x - len), limit);
    P[++tot] = pt(min(limit, x + len), limit);
  }
}
inline void addR(int x, int y, int d) {
  if (x + d <= limit)
    P[++tot] = pt(x + d, y);
  else {
    int len = d + x - limit;
    P[++tot] = pt(limit, max(0, y - len));
    P[++tot] = pt(limit, min(limit, y + len));
  }
}
pt O;
bool cmp1(const pt& A, const pt& B) {
  return same(A.x, B.x) ? A.y < B.y : A.x < B.x;
}
bool cmp2(const pt& A, const pt& B) {
  long double d = pt(A.x - O.x, A.y - O.y) * pt(B.x - O.x, B.y - O.y);
  if (same(0, d)) return dis(A, O) > dis(B, O);
  return d > 0;
}
inline void solve() {
  int g = 0;
  sort(P + 1, P + tot + 1, cmp1);
  for (int i = 1; i <= tot; ++i)
    if ((i == 1) || (P[i] != P[i - 1])) P2[++g] = P[i];
  tot = g;
  for (int i = 1; i <= tot; ++i) P[i] = P2[i];
  O = P[1];
  sort(P + 2, P + tot + 1, cmp2);
  memset(P2, 0, sizeof(P2));
  g = 0;
  P2[++g] = O;
  for (int i = 2; i <= tot; ++i) {
    if (i != 2 && same(0, (P[i] - O) * (P[i - 1] - O))) continue;
    while (g >= 2 && (P2[g - 1] - P[i]) * (P2[g] - P[i]) <= eps) --g;
    P2[++g] = P[i];
  }
  pt A = P2[g], B = P2[1], C = P2[2];
  long double d = get(A, B, C);
  if (get(P2[g - 1], P2[g], P2[1]) > d)
    A = P2[g - 1], B = P2[g], C = P2[1], d = get(P2[g - 1], P2[g], P2[1]);
  for (int i = 2; i < g; ++i)
    if (get(P2[i - 1], P2[i], P2[i + 1]) > d)
      A = P2[i - 1], B = P2[i], C = P2[i + 1],
      d = get(P2[i - 1], P2[i], P2[i + 1]);
  cout << int(A.x + 0.15) << " " << int(A.y + 0.15) << endl;
  cout << int(B.x + 0.15) << " " << int(B.y + 0.15) << endl;
  cout << int(C.x + 0.15) << " " << int(C.y + 0.15) << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x, y, d;
    cin >> x >> y >> d;
    addD(x, y, d);
    addL(x, y, d);
    addU(x, y, d);
    addR(x, y, d);
  }
  solve();
  return 0;
}
