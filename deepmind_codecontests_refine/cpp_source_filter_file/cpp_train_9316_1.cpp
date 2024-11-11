#include <bits/stdc++.h>
template <typename T>
bool Chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool Chkmin(T &x, T y) {
  return y < x ? x = y, true : false;
}
const int MAXN = 1e5 + 1e4, MAXK = 5 + 5;
const double eps = 1e-4;
int n;
int k;
std::pair<int, int> ans[MAXK];
inline int Dcmp(const double &x) {
  if (fabs(x) < eps) return 0;
  return x > 0 ? 1 : -1;
}
struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
};
struct Line {
  int A, B, C, id;
  Line() {}
  Line(int A, int B, int C, int id) : A(A), B(B), C(C), id(id) {}
  inline bool OnLine(const Point &p) {
    return Dcmp(A * p.x + B * p.y + C) == 0;
  }
} s[MAXN];
Point GetInter(Line l1, Line l2) {
  if (l2.A == 0) std::swap(l1, l2);
  double x, y;
  x = (double)(-l2.C + (double)(l2.B * l1.C) / l1.B) /
      (l2.A - (double)(l1.A * l2.B) / l1.B);
  y = (double)(-l1.C - l1.A * x) / l1.B;
  return Point(x, y);
}
bool Work(int N, int K) {
  if (N <= K) {
    printf("YES\n%d\n", k - K + N);
    for (int i = 1, _ = N; i <= _; i++) printf("%d %d\n", s[i].id, -1);
    return true;
  }
  if (K == 0) return false;
  Point p[MAXK * MAXK];
  std::pair<int, int> fr[MAXK * MAXK];
  int tot = 0;
  for (int i = 1, _ = K + 1; i <= _; i++)
    for (int j = i + 1, _ = K + 1; j <= _; j++) {
      ++tot;
      p[tot] = GetInter(s[i], s[j]);
      fr[tot] = std::make_pair(s[i].id, s[j].id);
    }
  for (int i = 1, _ = tot; i <= _; i++) {
    int newN = N;
    for (int j = 1; j <= newN; j++) {
      if (s[j].OnLine(p[i])) {
        std::swap(s[j], s[newN--]);
        j--;
      }
    }
    if (Work(newN, K - 1)) {
      printf("%d %d\n", fr[i].first, fr[i].second);
      return true;
    }
  }
  return false;
}
void Init() {
  int A, B, C;
  scanf("%d%d", &n, &k);
  for (int i = 1, _ = n; i <= _; i++) {
    scanf("%d%d%d", &A, &B, &C);
    s[i] = Line(A, B, C, i);
  }
}
int main() {
  if (fopen("D.in", "r") != NULL) {
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
  }
  Init();
  if (!Work(n, k)) printf("NO\n");
  return 0;
}
