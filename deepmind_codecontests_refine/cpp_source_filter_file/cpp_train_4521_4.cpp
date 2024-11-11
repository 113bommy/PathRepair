#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-11;
const int MAXN = 333;
int N, K;
double first[MAXN];
struct pt {
  double x, y;
  pt() {}
  pt(double a, double b) : x(a), y(b) {}
  double cross(const pt that) const { return x * that.y - y * that.x; }
  pt operator-(const pt that) const { return pt(x - that.x, y - that.y); }
};
pt Y[MAXN][MAXN];
struct line {
  pt a, b;
  line() {}
  line(pt a, pt b) : a(a), b(b) {}
  double slope() const { return (b.y - a.y) / (b.x - a.x); }
  double at(double x) const { return a.y + slope() * (x - a.x); }
};
bool intersect(const line& a, const line& b) {
  pt x = a.b - a.a, y = b.b - a.a;
  double c1 = x.cross(y);
  y = b.a - a.a;
  double c2 = x.cross(y);
  x = b.b - b.a;
  y = a.b - b.a;
  double c3 = x.cross(y);
  y = a.a - b.a;
  double c4 = x.cross(y);
  return (c1 * c2 <= 0 && c3 * c4 <= 0);
}
double get_x(const line& a, const line& b) {
  double ma = a.slope();
  double mb = b.slope();
  double ba = -ma * a.a.x + a.a.y;
  double bb = -mb * b.a.x + b.a.y;
  return (bb - ba) / (ma - mb);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(9) << fixed;
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= K; j++) {
      Y[i][j].x = j;
      cin >> Y[i][j].y;
    }
  }
  for (int i = 0; i < K; i++) {
    vector<pt> hull;
    hull.push_back(pt(i, 0));
    hull.push_back(pt(i + 1, 0));
    for (int j = 0; j < N; j++) {
      double cur = 0;
      int over = -1, under = -1;
      line back(Y[j][i], Y[j][i + 1]);
      for (int k = 0; k + 1 < hull.size(); k++) {
        line front(hull[k], hull[k + 1]);
        if (intersect(front, back)) {
          double x = get_x(front, back);
          if (front.slope() + EPS < back.slope()) {
            cur += .5 * (front.b.x - x) *
                   (back.at(front.b.x) - front.at(front.b.x));
            over = k;
          } else if (front.slope() > back.slope() + EPS) {
            cur += .5 * (x - front.a.x) *
                   (back.at(front.a.x) - front.at(front.a.x));
            under = k;
          }
        } else {
          if (back.at((front.a.x + front.b.x) / 2) >
              front.at((front.a.x + front.b.x) / 2)) {
            cur += (front.b.x - front.a.x) * .5 *
                   ((back.at(front.a.x) + back.at(front.b.x)) -
                    (front.at(front.a.x) + front.at(front.b.x)));
          }
        }
      }
      if (cur == 0) continue;
      first[j] += cur;
      vector<pt> newhull;
      if (over != -1) {
        for (int k = 0; k <= over; k++) newhull.push_back(hull[k]);
        line front(hull[over], hull[over + 1]);
        double x = get_x(front, back);
        if (x - newhull.back().x > EPS) newhull.push_back(pt(x, front.at(x)));
        if (under != -1) {
          front = line(hull[under], hull[under + 1]);
          double x = get_x(front, back);
          if (x - newhull.back().x > EPS) newhull.push_back(pt(x, front.at(x)));
          for (int i = under + 1; i < hull.size(); i++) {
            if (hull[i].x - newhull.back().x > EPS) newhull.push_back(hull[i]);
          }
        } else {
          pt p(back.b.x, back.b.y);
          if (p.x - newhull.back().x > EPS) newhull.push_back(p);
        }
      } else if (under != -1) {
        newhull.push_back(back.a);
        line front = line(hull[under], hull[under + 1]);
        double x = get_x(front, back);
        if (x - newhull.back().x > EPS) {
          pt y(x, front.at(x));
          newhull.push_back(pt(x, front.at(x)));
        }
        for (int i = under + 1; i < hull.size(); i++) {
          if (hull[i].x - newhull.back().x > EPS) newhull.push_back(hull[i]);
        }
      } else {
        newhull.push_back(Y[j][i]);
        newhull.push_back(Y[j][i + 1]);
      }
      hull = newhull;
    }
  }
  for (int i = 0; i < N; i++) cout << first[i] << '\n';
  return 0;
}
