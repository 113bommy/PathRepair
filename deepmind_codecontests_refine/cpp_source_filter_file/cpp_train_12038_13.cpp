#include <bits/stdc++.h>
using namespace std;
const long double mini = -1e18;
const long double maxi = 1e18;
vector<pair<long double, long double> > intervals;
struct vec2D {
  long double x;
  long double y;
  vec2D(long double x = 0, long double y = 0) : x(x), y(y) {}
  vec2D operator-(const vec2D& v) const { return vec2D(x - v.x, y - v.y); }
  vec2D operator+(const vec2D& v) const { return vec2D(x + v.x, y + v.y); }
  vec2D scale(long double s) { return vec2D(this->x * s, this->y * s); }
  long double length() { return sqrt(this->x * this->x + this->y * this->y); }
  vec2D normal() { return vec2D(-this->y, this->x).scale(1 / length()); }
};
struct sphere2D {
  vec2D center;
  long double r;
  sphere2D(vec2D center, long double r) {
    this->center = center;
    this->r = r;
  }
};
vec2D normi, middle, a, b;
void process_sphere(sphere2D s) {
  vec2D possible_center, pos_cent;
  long double begin, end, a1, a2, act, radius_l, rad_l;
  begin = mini;
  end = maxi;
  for (int i = 0; i < 200; i++) {
    act = (begin + end) / 2;
    possible_center = (normi.scale(act) + middle);
    radius_l = (b - possible_center).length();
    pos_cent = (normi.scale(end) + middle);
    rad_l = (b - pos_cent).length();
    if ((s.center - possible_center).length() - s.r >= radius_l) {
      if ((s.center - pos_cent).length() - s.r >= rad_l)
        end = act;
      else
        begin = act;
    } else {
      if ((s.center - pos_cent).length() - s.r < rad_l)
        end = act;
      else
        begin = act;
    }
  }
  a1 = act;
  begin = mini;
  end = maxi;
  for (int i = 0; i < 200; i++) {
    act = (begin + end) / 2;
    possible_center = (normi.scale(act) + middle);
    radius_l = (b - possible_center).length();
    pos_cent = (normi.scale(end) + middle);
    rad_l = (b - pos_cent).length();
    if ((s.center - possible_center).length() + s.r >= radius_l) {
      if ((s.center - pos_cent).length() + s.r >= rad_l)
        end = act;
      else
        begin = act;
    } else {
      if ((s.center - pos_cent).length() + s.r < rad_l)
        end = act;
      else
        begin = act;
    }
  }
  a2 = act;
  if (a1 > a2) swap(a1, a2);
  intervals.push_back(make_pair(a1, a2));
}
int main() {
  long double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  a = vec2D(x1, y1);
  b = vec2D(x2, y2);
  middle = (a + b).scale(0.5);
  normi = (b - a).normal();
  vector<sphere2D> v;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long double a, b, c;
    cin >> a >> b >> c;
    v.push_back(sphere2D(vec2D(a, b), c));
  }
  for (int i = 0; i < n; i++) process_sphere(v[i]);
  long double minix = 1e18;
  intervals.push_back(make_pair(0, 0));
  sort(intervals.begin(), intervals.end());
  long double q = intervals[0].first - 1e-2;
  for (int i = 0; i < n + 1; i++) {
    if (q <= intervals[i].first) {
      if (minix > (b - (middle + normi.scale(intervals[i].first))).length()) {
        minix = (b - (middle + normi.scale(intervals[i].first))).length();
      }
      if (minix > (b - (middle + normi.scale(q))).length()) {
        minix = (b - (middle + normi.scale(q))).length();
      }
    }
    q = max(q, intervals[i].second);
  }
  if (minix > (b - (middle + normi.scale(q))).length()) {
    minix = (b - (middle + normi.scale(q))).length();
  }
  cout << fixed << setprecision(12) << minix << endl;
}
