#include <bits/stdc++.h>
class point {
  friend std::istream& operator>>(std::istream&, point&);

 public:
  point();
  double distance(const point& other) const;
  double dot(const point& other) const;
  point& operator-=(const point& other);
  int x() const { return x_; }
  int y() const { return y_; }

 private:
  int x_, y_;
};
std::ostream& operator<<(std::ostream&, const point&);
point operator-(const point&, const point&);
class segment {
 public:
  segment(const point& a, const point& b);
  double distance(const point& p) const;

 private:
  point a_, b_;
};
using namespace std;
double circle_area(double radius);
const double pi = 2 * acos(0);
int main() {
  int vertices;
  point center;
  cout.precision(8);
  cout.setf(ios::fixed);
  while (cin >> vertices >> center) {
    double largest_radius = 0;
    double smallest_radius = 1e100;
    point first, last;
    for (int i = 0; i < vertices; i++) {
      point p;
      cin >> p;
      if (i != 0)
        smallest_radius =
            min(smallest_radius, segment(p, last).distance(center));
      else
        first = p;
      largest_radius = max(largest_radius, p.distance(center));
      last = p;
    }
    smallest_radius =
        min(smallest_radius, segment(first, last).distance(center));
    cout << circle_area(largest_radius) - circle_area(smallest_radius) << '\n';
  }
}
double circle_area(double radius) { return pi * radius * radius; }
point::point() : x_(0), y_(0) {}
std::istream& operator>>(std::istream& in, point& p) {
  return in >> p.x_ >> p.y_;
}
std::ostream& operator<<(std::ostream& out, const point& p) {
  return out << '(' << p.x() << ',' << p.y() << ')';
}
point operator-(const point& a, const point& b) {
  point p = a;
  return p -= b;
}
point& point::operator-=(const point& other) {
  x_ -= other.x_;
  y_ -= other.y_;
  return *this;
}
double square(double d) { return d * d; }
double point::distance(const point& other) const {
  return sqrt(square(x() - other.x()) + square(y() - other.y()));
}
double point::dot(const point& other) const {
  return static_cast<double>(x()) * other.x() +
         static_cast<double>(y()) * other.y();
}
segment::segment(const point& a, const point& b) : a_(a), b_(b) {}
double segment::distance(const point& p) const {
  double t = (p - a_).dot(b_ - a_) / square(a_.distance(b_));
  if (t > 0 && t < 1) {
    double mx = a_.x() + t * (b_ - a_).x();
    double my = a_.y() + t * (b_ - a_).y();
    return sqrt(square(mx - p.x()) + square(my - p.y()));
  }
  return min(b_.distance(p), a_.distance(p));
}
