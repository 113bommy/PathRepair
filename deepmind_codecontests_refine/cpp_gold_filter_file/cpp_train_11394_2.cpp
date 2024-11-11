#include <bits/stdc++.h>
using namespace std;
template <typename T>
T Abs(T first) {
  return (first < 0 ? -first : first);
}
template <typename T>
T Sqr(T first) {
  return (first * first);
}
string plural(string s) {
  return (int((s).size()) && s[int((s).size()) - 1] == 'x' ? s + "en"
                                                           : s + "s");
}
const int INF = (int)1e9;
const double EPS = 1e-9;
const long double PI = acos(-1.0);
bool Read(int &first) {
  char c, r = 0, n = 0;
  first = 0;
  for (;;) {
    c = getchar();
    if ((c < 0) && (!r)) return (0);
    if ((c == '-') && (!r))
      n = 1;
    else if ((c >= '0') && (c <= '9'))
      first = first * 10 + c - '0', r = 1;
    else if (r)
      break;
  }
  if (n) first = -first;
  return (1);
}
struct PT {
  double first, second;
  PT() {}
  PT(double first, double second) : first(first), second(second) {}
  PT(const PT &p) : first(p.first), second(p.second) {}
  PT operator+(const PT &p) const {
    return PT(first + p.first, second + p.second);
  }
  PT operator-(const PT &p) const {
    return PT(first - p.first, second - p.second);
  }
  PT operator*(double c) const { return PT(first * c, second * c); }
  PT operator/(double c) const { return PT(first / c, second / c); }
};
double dot(PT p, PT q) { return p.first * q.first + p.second * q.second; }
double dist2(PT p, PT q) { return dot(p - q, p - q); }
double cross(PT p, PT q) { return p.first * q.second - p.second * q.first; }
PT RotateCCW90(PT p) { return PT(-p.second, p.first); }
PT RotateCW90(PT p) { return PT(p.second, -p.first); }
PT RotateCCW(PT p, double t) {
  return PT(p.first * cos(t) - p.second * sin(t),
            p.first * sin(t) + p.second * cos(t));
}
PT ProjectPointLine(PT a, PT b, PT c) {
  return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}
PT ProjectPointSegment(PT a, PT b, PT c) {
  double r = dot(b - a, b - a);
  if (fabs(r) < EPS) return a;
  r = dot(c - a, b - a) / r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b - a) * r;
}
double DistancePointSegment(PT a, PT b, PT c) {
  return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}
double DistancePointPlane(double first, double second, double z, double a,
                          double b, double c, double d) {
  return fabs(a * first + b * second + c * z - d) / sqrt(a * a + b * b + c * c);
}
bool LinesParallel(PT a, PT b, PT c, PT d) {
  return fabs(cross(b - a, c - d)) < EPS;
}
bool LinesCollinear(PT a, PT b, PT c, PT d) {
  return LinesParallel(a, b, c, d) && fabs(cross(a - b, a - c)) < EPS &&
         fabs(cross(c - d, c - a)) < EPS;
}
bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
  if (LinesCollinear(a, b, c, d)) {
    if (dist2(a, c) < EPS || dist2(a, d) < EPS || dist2(b, c) < EPS ||
        dist2(b, d) < EPS)
      return true;
    if (dot(c - a, c - b) > 0 && dot(d - a, d - b) > 0 && dot(c - b, d - b) > 0)
      return false;
    return true;
  }
  if (cross(d - a, b - a) * cross(c - a, b - a) > 0) return false;
  if (cross(a - c, d - c) * cross(b - c, d - c) > 0) return false;
  return true;
}
int N;
int X[200], Y[200];
bool val[200][200];
int mem[200][200];
long long Cross(long long x1, long long y1, long long x2, long long y2) {
  return (x1 * y2 - x2 * y1);
}
int rec(int i, int d) {
  int j = (i + d) % N;
  if (!val[i][j]) return (0);
  if (N - d < 2) return (1);
  if (mem[i][d] >= 0) return (mem[i][d]);
  int v = 0, k, d2;
  int v1, v2, v3;
  for (d2 = d + 1; d2 <= N - 1; d2++) {
    k = (i + d2) % N;
    if ((!val[i][k]) || (!val[j][k])) continue;
    v2 = rec(k, N - (d2 - d));
    if (!v2) continue;
    v3 = rec(i, d2);
    if (!v3) continue;
    v = (v + (long long)v2 * v3) % 1000000007;
  }
  return (mem[i][d] = v);
}
int main() {
  if (0) freopen("in.txt", "r", stdin);
  int i, j, k, a, d;
  long long c;
  bool pos;
  double c1, c2, c3;
  long long v = 0;
  PT A, B, C, D, V1, V2, V3;
  memset(mem, -1, sizeof(mem));
  Read(N);
  for (i = 0; i < N; i++) Read(X[i]), Read(Y[i]);
  for (i = 0; i < N; i++) {
    j = (i + 1) % N;
    v += (long long)(X[j] - X[i]) * (Y[j] + Y[i]);
  }
  pos = (v > 0);
  for (i = 0; i < N; i++)
    for (d = 1; d <= N - 1; d++) {
      j = (i + d) % N;
      if ((d == 1) || (d == N - 1)) goto Good;
      for (k = 0; k < N; k++)
        if ((k != i) && (k != j)) {
          A = PT(X[i], Y[i]);
          B = PT(X[j], Y[j]);
          C = PT(X[k], Y[k]);
          if (DistancePointSegment(A, B, C) < EPS) goto Bad;
        }
      for (a = 0; a < N; a++) {
        k = (a + 1) % N;
        if ((k != i) && (k != j) && (a != i) && (a != j)) {
          A = PT(X[i], Y[i]);
          B = PT(X[j], Y[j]);
          C = PT(X[k], Y[k]);
          D = PT(X[a], Y[a]);
          if (SegmentsIntersect(A, B, C, D)) goto Bad;
        }
      }
      k = (i + 1) % N;
      a = (i - 1 + N) % N;
      V1 = PT(X[k] - X[i], Y[k] - Y[i]);
      V2 = PT(X[a] - X[i], Y[a] - Y[i]);
      V3 = PT(X[j] - X[i], Y[j] - Y[i]);
      c1 = cross(V1, V2);
      c2 = cross(V1, V3);
      c3 = cross(V3, V2);
      if (pos) c1 = -c1, c2 = -c2, c3 = -c3;
      if ((c1 > -EPS) && (c2 > -EPS) && (c3 > -EPS)) goto Good;
      if ((c1 < -EPS) && (!((c2 < -EPS) && (c3 < -EPS)))) goto Good;
      goto Bad;
    Good:;
      val[i][j] = 1;
    Bad:;
    }
  printf("%d\n", rec(0, 1));
  return (0);
}
