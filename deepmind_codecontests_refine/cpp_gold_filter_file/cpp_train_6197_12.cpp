#include <bits/stdc++.h>
using namespace std;
template <class T, class IT>
inline void PRINT(IT i1, IT i2) {
  cout << '[';
  copy(i1, i2, ostream_iterator<T>(cout, ", "));
  cout << "]\n";
}
template <typename T>
struct point2d {
  T x, y;
  point2d(const T& _x, const T& _y) : x(_x), y(_y) {}
  point2d() {}
  double norm2() const { return sqrt(x * x + y * y); }
  point2d<T> operator*(T v) const { return point2d<T>(x * v, y * v); }
  point2d<T> operator-(const point2d<T>& rhs) const {
    return point2d<T>(x - rhs.x, y - rhs.y);
  }
  point2d<T> operator+(const point2d<T>& rhs) const {
    return point2d<T>(x + rhs.x, y + rhs.y);
  }
};
point2d<double> inner(const point2d<long long>& a, const point2d<long long>& b,
                      double t) {
  point2d<double> result(a.x + t * (b.x - a.x), a.y + t * (b.y - a.y));
  return result;
}
template <typename T>
struct segment2d {
  T a;
  T b;
  segment2d(const T& _a, const T& _b) : a(_a), b(_b) {}
  segment2d() {}
};
point2d<double> D(const point2d<long long>& p) {
  return point2d<double>(1.0 * p.x, 1.0 * p.y);
}
inline bool ZERO(long long a) { return a == 0; }
inline bool ZERO(double a) { return fabs(a) < (1e-9); }
template <typename PointT1, typename PointT2>
double vmul(const PointT1& a, const PointT2& b) {
  return a.x * b.y - b.x * a.y;
}
bool intersect(const segment2d<point2d<long long> >& a,
               const segment2d<point2d<long long> >& b, double& t) {
  double f = vmul(b.b - a.a, b.a - a.a);
  double s = vmul(b.b - a.b, b.a - a.b);
  if ((f > 0 && s < 0) || (f < 0 && s > 0)) {
    t = f / (f - s);
    return true;
  } else {
    return false;
  }
}
bool inside(const point2d<long long>& a, const point2d<long long>& b,
            const point2d<long long>& c, const point2d<double>& p) {
  double s1 = abs(vmul(D(a) - p, D(b) - p)) + abs(vmul(D(b) - p, D(c) - p)) +
              abs(vmul(D(c) - p, D(a) - p));
  double s2 = abs(vmul(b - a, c - a));
  return ZERO(s1 - s2);
}
point2d<long long> triangle[111][3];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < (int)(n); ++i) {
    cin >> triangle[i][0].x >> triangle[i][0].y >> triangle[i][1].x >>
        triangle[i][1].y >> triangle[i][2].x >> triangle[i][2].y;
  }
  double result = 0.0;
  for (int i = 0; i < (int)(n); ++i)
    for (int k = 0; k < (int)(3); ++k) {
      segment2d<point2d<long long> > current(triangle[i][k],
                                             triangle[i][(k + 1) % 3]);
      vector<double> intersection;
      intersection.push_back(0);
      intersection.push_back(1);
      for (int j = 0; j < (int)(n); ++j)
        if (i != j)
          for (int l = 0; l < (int)(3); ++l) {
            segment2d<point2d<long long> > test(triangle[j][l],
                                                triangle[j][(l + 1) % 3]);
            double t;
            if (intersect(current, test, t)) {
              if (t != t) {
                cout << current.a.x << " " << current.a.y << " " << current.b.x
                     << " " << current.b.y << " vs. " << test.a.x << " "
                     << test.a.y << " " << test.b.x << " " << test.b.y << " : "
                     << t << endl;
              }
              intersection.push_back(t);
            }
          }
      sort(intersection.begin(), intersection.end());
      for (int j = 0; j < (int)(intersection.size() - 1); ++j) {
        double t = (intersection[j] + intersection[j + 1]) / 2;
        bool black = false;
        for (int l = 0; l < (int)(n); ++l)
          if (l != i) {
            if (inside(triangle[l][0], triangle[l][1], triangle[l][2],
                       inner(current.a, current.b, t))) {
              black = true;
            }
          }
        double qqq = (current.b - current.a).norm2() *
                     (intersection[j + 1] - intersection[j]);
        if (qqq != qqq) {
        }
        if (!black)
          result += (current.b - current.a).norm2() *
                    (intersection[j + 1] - intersection[j]);
      }
    }
  cout << setprecision(10) << result;
  return 0;
}
