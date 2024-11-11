#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
inline int dcmp(const double &first) { return first < -eps ? -1 : first > eps; }
struct point {
  double first, second;
  point() {}
  point(const double &_x, const double &_y) : first(_x), second(_y) {}
  friend point operator+(const point &first, const point &second) {
    return point(first.first + second.first, first.second + second.second);
  }
  friend point operator-(const point &first, const point &second) {
    return point(first.first - second.first, first.second - second.second);
  }
  friend point operator*(const point &first, const double &second) {
    return point(first.first * second, first.second * second);
  }
  friend point operator/(const point &first, const double &second) {
    return point(first.first / second, first.second / second);
  }
  friend double operator*(const point &first, const point &second) {
    return first.first * second.first + first.second * second.second;
  }
  friend double operator^(const point &first, const point &second) {
    return first.first * second.second - first.second * second.first;
  }
  friend bool operator<(const point &first, const point &second) {
    if (dcmp(first.first - second.first)) return first.first < second.first;
    return dcmp(first.second - second.second) < 0;
  }
  double angle() const { return atan2(second, first); }
};
bool on_seg(const point &P, const point &u, const point &v) {
  return !dcmp((P - u) ^ (P - v)) && dcmp((P - u) * (P - v)) <= 0;
}
bool intersect(const point &P, const point &v, const point &Q, const point &w,
               point &O) {
  register double t = v ^ w;
  if (!dcmp(v ^ w)) return 0;
  point u = P - Q;
  t = (w ^ u) / t;
  O = P + v * t;
  return 1;
}
int in_rect(const point &u0, const point &v0, point *rect) {
  int cnt = 0;
  point P = (u0 + v0) / 2;
  for (int i = (0), _end_ = (4); i < _end_; ++i) {
    point u = rect[i], v = rect[(i + 1) & 3];
    if (on_seg(P, u, v)) {
      if (dcmp((v - u) * (v0 - u0)) < 0) return 0;
      return 1;
    }
    if (u.first > v.first) swap(u, v);
    if (dcmp((v - u) ^ (P - u)) > 0) {
      cnt += dcmp(u.first - P.first) < 0 && dcmp(v.first - P.first) >= 0;
    }
  }
  return cnt & 1 ? 2 : 0;
}
const int maxn = 600;
int n;
point rect[maxn + 5][4];
bool f[maxn + 5][maxn + 5];
double ans = 0, ret = 0;
void init() {
  srand(time(NULL));
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    double sum = 0;
    for (int j = (0), _end_ = (4); j < _end_; ++j)
      scanf("%lf%lf", &rect[i][j].first, &rect[i][j].second);
    for (int j = (0), _end_ = (4); j < _end_; ++j)
      sum += rect[i][j] ^ rect[i][(j + 1) & 3];
    if (!dcmp(sum)) --n, --i;
    if (sum < 0) reverse(rect[i], rect[i] + 4), sum = -sum;
    ans += sum;
  }
}
point O;
double ang[maxn * 100 + 5];
int pos[maxn * 100 + 5];
int ty[maxn * 100 + 5];
int has[maxn + 5];
inline bool cmp(const int &first, const int &second) {
  return dcmp(ang[first] - ang[second]) < 0;
}
inline bool cmp0(const int &first, const int &second) {
  return !dcmp(ang[first] - ang[second]);
}
void solve() {
  for (int i = (0), _end_ = (n); i < _end_; ++i) {
    O = point(0.0, 0.0);
    double Minx = 1e100;
    for (int a = (0), _end_ = (4); a < _end_; ++a) O = O + rect[i][a];
    O = O / 4;
    double lyc = O.second - eps;
    for (int a = (0), _end_ = (4); a < _end_; ++a) {
      if (dcmp(lyc - rect[i][a].second) *
              dcmp(lyc - rect[i][(a + 1) & 3].second) <=
          0)
        Minx =
            min(Minx, ((lyc - rect[i][a].second) * rect[i][(a + 1) & 3].first +
                       (rect[i][(a + 1) & 3].second - lyc) * rect[i][a].first) /
                          (rect[i][(a + 1) & 3].second - rect[i][a].second));
    }
    static point p[maxn * 100 + 5];
    int pn = 0;
    int posn = 0;
    for (int a = (0), _end_ = (4); a < _end_; ++a)
      ty[pn] = 0, pos[posn++] = pn, p[pn] = rect[i][a],
      ang[pn] = (p[pn] - O).angle(), ++pn;
    for (int j = (0), _end_ = (n); j < _end_; ++j) {
      if (j == i) continue;
      int lst = pn;
      int lst0 = posn;
      p[pn++] = point(Minx, O.second - eps);
      for (int a = (0), _end_ = (4); a < _end_; ++a) {
        point &u0 = rect[i][a], &v0 = rect[i][(a + 1) & 3];
        p[pn++] = rect[i][a];
        for (int b = (0), _end_ = (4); b < _end_; ++b) {
          point &u1 = rect[j][b], &v1 = rect[j][(b + 1) & 3];
          if (intersect(u0, v0 - u0, u1, v1 - u1, p[pn]) &&
              on_seg(p[pn], u0, v0) && on_seg(p[pn], u1, v1))
            ++pn;
        }
      }
      for (int k = (lst), _end_ = (pn); k < _end_; ++k)
        ang[k] = (p[k] - O).angle(), pos[posn++] = k;
      sort(pos + lst0, pos + posn, cmp);
      posn = unique(pos + lst0, pos + posn, cmp0) - pos;
      for (int k = (lst0), _end_ = (posn); k < _end_; ++k) {
        int tmp =
            in_rect(p[pos[k]], p[pos[k + 1 >= posn ? lst0 : k + 1]], rect[j]);
        if (tmp == 1) {
          if (i > j) tmp = 0;
        }
        ty[pos[k]] = tmp ? j + 1 : -j - 1;
      }
    }
    sort(pos, pos + posn, cmp);
    int cnt = 0;
    memset(has, 0, sizeof has);
    for (int j = (0), _end_ = (posn); j < _end_; ++j) {
      int &first = pos[j];
      if (ty[first] < 0) {
        if (has[-ty[first] - 1]) --cnt, has[-ty[first] - 1] = 0;
      } else if (ty[first] > 0) {
        if (!has[ty[first] - 1]) ++cnt, has[ty[first] - 1] = 1;
      }
      if (!cnt) {
        point u = p[pos[j]], v = p[pos[(j + 1) % posn]];
        ret += u ^ v;
      }
    }
  }
  ans = ans / ret;
}
void output() { printf("%.5lf\n", ans); }
int main() {
  init();
  solve();
  output();
  return 0;
}
