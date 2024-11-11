#include <bits/stdc++.h>
inline void gettime() {
  std::cerr << "L: " << 7 << " " << __FUNCTION__ << "() Var: "
            << "clock()"
            << " Val: " << clock() << "\n";
}
inline int read() {
  static char c;
  static int x;
  int flag = 1;
  while (c = getchar(), !isdigit(c))
    if (c == '-') flag = -1;
  x = c - '0';
  while (c = getchar(), isdigit(c)) x = (x << 1) + (x << 3) + c - '0';
  return x * flag;
}
inline char achar() {
  static char c;
  while (c = getchar(), !isalpha(c))
    ;
  return c;
}
const double pi = std::acos(-1);
int n, m, v;
struct WALL {
  double x, y;
  bool operator<(const WALL &rhs) const {
    return x != rhs.x ? x < rhs.x : y < rhs.y;
  }
} ws[100200];
double G = 9.8;
int INDEX = 0;
struct SHOOT {
  double a, t, x, id, ans;
  SHOOT() = default;
  SHOOT(double alpha) {
    a = alpha;
    t = 2 * v * std::sin(a) / G;
    x = v * std::cos(a) * t;
    id = ++INDEX;
  }
  double high(const double &pos) {
    double time = pos / v / std::cos(a);
    return v * std::sin(a) * time - G * time * time / 2;
  }
  bool operator<(const SHOOT &rhs) const { return x < rhs.x; }
} ns[20000];
int main() {
  n = read(), v = read();
  for (int i = 1; i <= n; ++i) {
    double alpha;
    scanf("%lf", &alpha);
    ns[i] = SHOOT(alpha);
  }
  m = read();
  for (int i = 1; i <= m; ++i) scanf("%lf %lf", &ws[i].x, &ws[i].y);
  std::sort(ws + 1, ws + 1 + m);
  ws[++m] = (WALL){1e9, 1e9};
  std::sort(ns + 1, ns + 1 + n);
  for (int l = 1, r = 1; l <= n; ++l) {
    for (; r <= m && ns[l].x > ws[r].x && ns[l].high(ws[r].x) > ws[r].y; ++r)
      ;
    if (ns[l].x <= ws[r].x)
      ns[l].ans = ns[l].x;
    else
      ns[l].ans = ws[r].x;
  }
  std::sort(ns + 1, ns + 1 + n,
            [](const SHOOT &a, const SHOOT &b) { return a.id < b.id; });
  for (int i = 1; i <= n; ++i)
    printf("%.8lf %.8lf\n", ns[i].ans, ns[i].high(ns[i].ans));
}
