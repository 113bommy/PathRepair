#include <bits/stdc++.h>
using namespace std;
inline void Read(long long &x) {
  long long f = 1;
  char c = getchar();
  x = 0;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  x *= f;
}
const long long N = 800010, M = 100000;
long long n, ansp;
double ans;
struct P {
  long long x, y;
  P(long long _x = 0, long long _y = 0) { x = _x, y = _y; }
} p[N], st[N];
long long tot, tp;
P operator+(P A, P B) { return P(A.x + B.x, A.y + B.y); }
P operator-(P A, P B) { return P(A.x - B.x, A.y - B.y); }
long long operator*(P A, P B) { return A.x * B.y - A.y * B.x; }
inline double Dis(P A, P B) {
  return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
bool operator<(P A, P B) {
  P _A = A - p[1], _B = B - p[1];
  return _A * _B == 0 ? Dis(A, p[1]) < Dis(B, p[1]) : _A * _B > 0;
}
bool operator==(P A, P B) { return A.x == B.x && A.y == B.y; }
inline bool cmp(P A, P B) { return A.x == B.x ? A.y < B.y : A.x < B.x; }
inline void ConvexHull(long long len) {
  sort(p + 2, p + 1 + len);
  st[tp = 1] = p[1];
  for (register long long i = 2; i <= len; i++) {
    while (tp > 1 && (p[i] - st[tp - 1]) * (st[tp] - st[tp - 1]) >= 0) tp--;
    st[++tp] = p[i];
  }
  st[tp + 1] = p[1], st[tp + 2] = p[2];
}
inline double Calc(P A, P B, P C) {
  return (double)Dis(A, B) * Dis(B, C) * Dis(C, A) / ((B - A) * (C - B));
}
signed main() {
  Read(n);
  for (register long long i = 1, x, y, v; i <= n; i++) {
    Read(x), Read(y), Read(v);
    long long up = y + v, dn = y - v, rt = x + v, lt = x - v;
    if (up <= M)
      p[++tot] = P(x, up);
    else {
      p[++tot] = P(min(M, x + up - M), M);
      p[++tot] = P(max(0ll, x - up + M), M);
    }
    if (dn >= 0)
      p[++tot] = P(x, dn);
    else {
      p[++tot] = P(min(M, x - dn), 0);
      p[++tot] = P(max(0ll, x + dn), 0);
    }
    if (rt <= M)
      p[++tot] = P(rt, y);
    else {
      p[++tot] = P(M, min(M, y + rt - M));
      p[++tot] = P(M, max(0ll, y - rt + M));
    }
    if (lt >= 0)
      p[++tot] = P(lt, y);
    else {
      p[++tot] = P(0, min(M, y - lt));
      p[++tot] = P(0, max(0ll, y + lt));
    }
  }
  sort(p + 1, p + 1 + tot, cmp);
  tot = unique(p + 1, p + 1 + tot) - p - 1;
  ConvexHull(tot);
  for (register long long i = 1; i <= tp; i++) {
    double tmp = Calc(st[i], st[i + 1], st[i + 2]);
    if (tmp > ans) ans = tmp, ansp = i;
  }
  cout << st[ansp].x << " " << st[ansp].y << endl;
  cout << st[ansp + 1].x << " " << st[ansp + 1].y << endl;
  cout << st[ansp + 2].x << " " << st[ansp + 2].y << endl;
  return 0;
}
