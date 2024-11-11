#include <bits/stdc++.h>
using namespace std;
long long sqr(long long x) { return x * x; }
struct Point {
  long long x, y;
  bool operator==(struct Point a) { return x == a.x && y == a.y; }
  struct Point operator-(struct Point a) {
    return Point{x - a.x, y - a.y};
  }
  struct Point operator+(struct Point a) {
    return Point{x + a.x, y + a.y};
  }
  long long operator^(struct Point a) { return x * a.y - a.x * y; }
  long long operator*(struct Point a) { return x * a.x + a.y * y; }
  friend double dis(struct Point a, struct Point b) {
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
  }
};
int sgn(double x) {
  if (fabs(x) <= 1e-8) return 0;
  if (x < 0) return -1;
  return 1;
}
bool check(Point a, Point b, Point c) {
  if (((b - c) ^ (c - a)) != 0) return 0;
  if (sgn(dis(a, c) + dis(c, b) - dis(a, b))) return 0;
  if (sgn(4 * min(dis(a, c), dis(c, b)) - max(dis(a, c), dis(c, b))) == -1)
    return 0;
  return 1;
}
struct Line {
  Point st, ed;
} a[5];
bool right(Point o, Point a, Point b) {
  double angle = acos(((a - o) * (b - o)) / (dis(a, o) * dis(b, o)));
  return sgn(angle) >= 0 && sgn(acos(-1) / 2 - angle) >= 0;
}
int main() {
  int T, flag;
  scanf("%d", &T);
  while (T--) {
    for (int i = 1; i <= 3; i++)
      scanf("%lld %lld %lld %lld", &a[i].st.x, &a[i].st.y, &a[i].ed.x,
            &a[i].ed.y);
    flag = 0;
    for (int i = 1; i <= 3; i++)
      for (int j = i + 1; j <= 3; j++) {
        if (a[i].st == a[j].st) {
          if (check(a[i].st, a[i].ed, a[6 - i - j].st) &&
              check(a[j].st, a[j].ed, a[6 - i - j].ed) &&
              right(a[i].st, a[i].ed, a[j].ed))
            flag = 1;
          if (check(a[j].st, a[j].ed, a[6 - i - j].st) &&
              check(a[i].st, a[i].ed, a[6 - i - j].ed) &&
              right(a[i].st, a[i].ed, a[j].ed))
            flag = 1;
        } else if (a[i].st == a[j].ed) {
          if (check(a[i].st, a[i].ed, a[6 - i - j].st) &&
              check(a[j].st, a[j].ed, a[6 - i - j].ed) &&
              right(a[i].st, a[i].ed, a[j].st))
            flag = 1;
          if (check(a[j].st, a[j].ed, a[6 - i - j].st) &&
              check(a[i].st, a[i].ed, a[6 - i - j].ed) &&
              right(a[i].st, a[i].ed, a[j].st))
            flag = 1;
        } else if (a[i].ed == a[j].st) {
          if (check(a[i].st, a[i].ed, a[6 - i - j].st) &&
              check(a[j].st, a[j].ed, a[6 - i - j].ed) &&
              right(a[i].ed, a[i].st, a[j].ed))
            flag = 1;
          if (check(a[j].st, a[j].ed, a[6 - i - j].st) &&
              check(a[i].st, a[i].ed, a[6 - i - j].ed) &&
              right(a[i].ed, a[i].st, a[j].ed))
            flag = 1;
        } else if (a[i].ed == a[j].ed) {
          if (check(a[i].st, a[i].ed, a[6 - i - j].st) &&
              check(a[j].st, a[j].ed, a[6 - i - j].ed) &&
              right(a[i].ed, a[i].st, a[j].st))
            flag = 1;
          if (check(a[j].st, a[j].ed, a[6 - i - j].st) &&
              check(a[i].st, a[i].ed, a[6 - i - j].ed) &&
              right(a[i].ed, a[i].st, a[j].st))
            flag = 1;
        }
      }
    if (flag)
      puts("YES");
    else
      puts("NO");
  }
}
