#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
double pi = acos(-1.0), eps = 1e-9;
int n, q, x, y, p1, p2, f1[N], f2[N];
double k, wz, wn;
struct node {
  int x, y;
} e[N];
long long dis[N];
inline bool cmp(int a, int b) {
  if (e[a].y == e[b].y) return e[a].x < e[b].x;
  return e[a].y < e[b].y;
}
inline bool sol(double v) {
  if (-eps <= v && v <= eps) return 1;
  return 0;
}
inline long long getans(node a, node b, node c) {
  int f1 = a.x - c.x, f2 = a.y - c.y, f3 = b.x - c.x, f4 = b.y - c.y;
  return abs(1ll * f1 * f4 - 1ll * f2 * f3);
}
inline double getx(node a, node b, node c, double k) {
  if (a.x == b.x) return a.x;
  if (-eps + pi / 2 <= wz && wz <= eps + pi / 2) {
    return c.x;
  }
  double q = 1.0 * (b.y - a.y) / (b.x - a.x);
  return (a.y - c.y + c.x * k - a.x * q) / (k - q);
}
inline double gety(node a, node b, node c, double k) {
  if (-eps + pi / 2 <= wz && wz <= eps + pi / 2) {
    double q = 1.0 * (b.y - a.y) / (b.x - a.x);
    return (getx(a, b, c, k) - a.x) * q + a.y;
  }
  return (getx(a, b, c, k) - c.x) * k + c.y;
}
inline double getval(double f1, double f2, double f3, double f4, double f5,
                     double f6) {
  f1 -= f5, f2 -= f6, f3 -= f5, f4 -= f6;
  return f1 * f4 - f2 * f3;
}
inline double getvas(double f1, double f2, double f3, double f4, double f5,
                     double f6) {
  return f1 * f4 - f2 * f3;
}
inline bool fucku_questions_setter(double b, double a) {
  double w;
  if (pi / 2 - eps <= wz && wz <= pi / 2 + eps)
    w = getvas(a, b, 0, 1, 0, 0);
  else
    w = getvas(a, b, 1, k, 0, 0);
  return (w >= eps);
}
inline int solve(node a, double f1, double f2) {
  double s1 = getval(a.x, a.y, x, y, f1, f2);
  double s2 = getval(e[1].x, e[1].y, x, y, f1, f2);
  if (sol(s1)) return 2;
  s1 += eps, s2 += eps;
  if (s1 >= 0 && s2 >= 0) return 1;
  if (s1 <= 0 && s2 <= 0) return 1;
  return 0;
}
inline double getsum(int l, int r) {
  while (r - l >= n) r -= n;
  while (l > r) l -= n;
  while (r < n + 1) l += n, r += n;
  while (l > n + 1) l -= n, r -= n;
  if (l <= n + 1 && n + 1 <= r) {
    if (l == n + 1) return dis[r - n];
    return dis[n] - dis[l] + dis[r - n] + getans(e[1], e[l], e[r - n]);
  } else
    return getsum(r, l);
}
inline double getans(double w) {
  k = tan(w), wz = w;
  double a = w, b = -w;
  int l = p1, r = p2 - 1, ch[3] = {0, 0, 0};
  while (l <= r) {
    int d = (l + r) >> 1;
    if (fucku_questions_setter(e[d].y - y - eps, e[d].x - x) ^
        fucku_questions_setter(e[d + 1].y - y - eps, e[d + 1].x - x)) {
      if (!ch[1])
        ch[1] = d;
      else
        ch[2] = d;
      break;
    }
    if (fucku_questions_setter(e[d].y - y - eps, e[d].x - x) ==
        fucku_questions_setter(e[p1].y - y - eps, e[p1].x - x))
      l = d + 1;
    else
      r = d - 1;
  }
  l = p2 + 1, r = p1 - 2;
  while (r - l >= n) r -= n;
  while (l > r) l -= n;
  while (r < n + 1) l += n, r += n;
  while (l > n + 1) l -= n, r -= n;
  while (l <= r) {
    int d = (l + r) >> 1;
    if (fucku_questions_setter(e[d].y - y - eps, e[d].x - x) ^
        fucku_questions_setter(e[d + 1].y - y - eps, e[d + 1].x - x)) {
      if (!ch[1])
        ch[1] = d;
      else
        ch[2] = d;
      break;
    }
    if (fucku_questions_setter(e[d].y - y - eps, e[d].x - x) ==
        fucku_questions_setter(e[p2 + 1].y - y - eps, e[p2 + 1].x - x))
      l = d + 1;
    else
      r = d - 1;
  }
  if (fucku_questions_setter(e[p1 - 1].y - y - eps, e[p1 - 1].x - x) ^
      fucku_questions_setter(e[p1].y - y - eps, e[p1].x - x)) {
    if (ch[1] % n == (p1 % n - 1 + n) % n && ch[1] > 0)
      ;
    else {
      if (!ch[1])
        ch[1] = p1 % n - 1 + n;
      else
        ch[2] = p1 % n - 1 + n;
    }
  }
  if (fucku_questions_setter(e[p2].y - y - eps, e[p2].x - x) ^
      fucku_questions_setter(e[p2 + 1].y - y - eps, e[p2 + 1].x - x)) {
    if (ch[1] % n == p2 % n && ch[1] > 0)
      ;
    else {
      if (!ch[1])
        ch[1] = p2;
      else
        ch[2] = p2;
    }
  }
  node p;
  p.x = x, p.y = y;
  double xa = getx(e[ch[1]], e[ch[1] + 1], p, k),
         xb = getx(e[ch[2]], e[ch[2] + 1], p, k);
  double ya = gety(e[ch[1]], e[ch[1] + 1], p, k),
         yb = gety(e[ch[2]], e[ch[2] + 1], p, k);
  if (solve(e[ch[1]], xa, ya) && solve(e[ch[1] + 1], xa, ya) != 2)
    l = ch[1];
  else
    l = ch[1] + 1;
  if (solve(e[ch[2]], xa, ya) && solve(e[ch[2] + 1], xa, ya) != 2)
    r = ch[2];
  else
    r = ch[2] + 1;
  double vas = abs(getval(e[l].x, e[l].y, e[r].x, e[r].y, xa, ya)) +
               abs(getval(e[r].x, e[r].y, xb, yb, xa, ya));
  if (!solve(e[l + 1], xa, ya) && (l == 1 || l == n + 1)) swap(l, r);
  if (!solve(e[r - 1], xa, ya) && (r == 1 || r == n + 1)) swap(l, r);
  vas += getsum(l, r);
  if (w > wn + eps)
    return dis[n] - vas * 2;
  else
    return 2 * vas - dis[n];
}
inline void write(double w) {
  double ans = w;
  printf("%.12lf\n", ans);
}
int main() {
  cin >> n >> q;
  int l, r;
  for (int i = 1; i <= n; i++) scanf("%d%d", &e[i].x, &e[i].y), e[i + n] = e[i];
  for (int i = 1; i <= n; i++) swap(e[i], e[2 * n - i + 1]);
  e[0] = e[n], e[2 * n + 1] = e[1];
  for (int i = 3; i <= n + n; i++)
    dis[i] = dis[i - 1] + getans(e[i], e[i - 1], e[1]);
  for (int i = 1; i <= n; i++)
    if (e[i].y <= e[i + 1].y) f1[++f1[0]] = i;
  sort(f1 + 1, f1 + f1[0] + 1, cmp);
  for (int i = 1; i <= n; i++)
    if (e[i].y >= e[i + 1].y) f2[++f2[0]] = i;
  sort(f2 + 1, f2 + f2[0] + 1, cmp);
  int og = 0;
  while (q--) {
    scanf("%d%d", &x, &y), og++;
    l = 1, r = f1[0];
    while (l <= r) {
      int d = (l + r) >> 1;
      if (e[f1[d]].y <= y && y <= e[f1[d] + 1].y) {
        p1 = f1[d];
        break;
      }
      if (e[f1[d]].y <= y)
        l = d + 1;
      else
        r = d - 1;
    }
    l = 1, r = f2[0];
    while (l <= r) {
      int d = (l + r) >> 1;
      if (e[f2[d]].y >= y && y >= e[f2[d] + 1].y) {
        p2 = f2[d] + 1;
        break;
      }
      if (e[f2[d]].y <= y)
        l = d + 1;
      else
        r = d - 1;
    }
    swap(p1, p2);
    if (p1 > p2) p2 += n;
    while (p1 - 1 > 0 && e[p1 - 1].y <= y) p1--;
    while (p2 + 1 <= 2 * n && e[p2 + 1].y <= y) p2++;
    wn = atan2(e[1].y - y, e[1].x - x);
    if (wn < 0) wn = pi + wn;
    double lt = 0, rt = pi;
    double s1 = getans(lt), s2 = getans(rt);
    if (sol(s1)) {
      write(lt);
      continue;
    }
    if (sol(s2)) {
      write(rt);
      continue;
    }
    double f1 = 1e9 + 7, f2 = 0;
    for (int i = 1; i <= 50; i++) {
      double d = (lt + rt) / 2, w = getans(d);
      if (abs(f1) - abs(w) > 0) {
        f1 = w, f2 = d;
      }
      if (s1 * w < 0)
        s2 = w, rt = d;
      else
        s1 = w, lt = d;
    }
    double ans = f2;
    printf("%.12lf\n", ans);
  }
  return 0;
}
