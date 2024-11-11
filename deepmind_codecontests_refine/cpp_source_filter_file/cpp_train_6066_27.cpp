#include <bits/stdc++.h>
using namespace std;
std::pair<double, double> divide_by_max_coord(int x, int y) {
  double norm = std::max(x, y);
  return std::make_pair(x / norm, y / norm);
}
struct point {
  int x;
  int y;
  bool operator==(const point& other) const {
    return x == other.x && y == other.y;
  }
  point operator-(const point& other) const {
    return point{x - other.x, y - other.y};
  }
  double length() const {
    double len = sqrt(pow(x, 2) + pow(y, 2));
    return len;
  }
  int getMaxCoordAbs() const { return std::max(abs(x), abs(y)); }
  double dotNormalized(const point& other) const {
    double selfNX = double(x) / getMaxCoordAbs();
    double selfNY = double(y) / getMaxCoordAbs();
    double othNX = double(other.x) / other.getMaxCoordAbs();
    double othNY = double(other.y) / other.getMaxCoordAbs();
    return selfNX * othNX + selfNY * othNY;
  }
  bool same_angle(const point& other) {
    if (x == 0) {
      return (other.x == 0 && y * other.y > 0);
    }
    if (y == 0) {
      return (other.y == 0 && x * other.x > 0);
    }
    double prX = double(other.x) / x;
    double prY = double(other.y) / y;
    if (prX <= 0 || prY <= 0) {
      return false;
    }
    return abs(prX - prY) < 1e-6;
  }
};
struct section {
  point start;
  point end;
  void swap() { std::swap(start, end); }
  double point_place_on_segment(const point& p) const {
    auto self = to_vector();
    auto other = (p - start);
    if (self.x == 0) {
      return double(other.y) / self.y;
    }
    return double(other.x) / self.x;
  }
  bool contains_on_14(const point& p) const {
    if (p == start) return false;
    auto same_angle = (end - start).same_angle(p - start);
    auto proportion = point_place_on_segment(p);
    double epsilon = 1e-6;
    bool proportion_less = (proportion - 0.2) < -epsilon;
    bool proportion_more = (proportion - 0.8) > epsilon;
    bool inside = !proportion_less && !proportion_more;
    return inside && same_angle;
  }
  point to_vector() const { return end - start; }
};
bool have_same_point(section& s1, section& s2) {
  if (s1.start == s2.start) {
    return true;
  }
  if (s1.start == s2.end) {
    s2.swap();
    return true;
  }
  if (s1.end == s2.start) {
    s1.swap();
    return true;
  }
  if (s1.end == s2.end) {
    s1.swap();
    s2.swap();
    return true;
  }
  return false;
}
void set_same_start_point(section& s1, section& s2) {
  if (s1.start == s2.end) {
    s2.swap();
  } else if (s1.end == s2.start) {
    s1.swap();
  }
}
bool is_middle_section(const section& s1, const section& s2,
                       const section& s3) {
  if (s1.contains_on_14(s3.start) && s2.contains_on_14(s3.end)) return true;
  if (s2.contains_on_14(s3.start) && s1.contains_on_14(s3.end)) return true;
  return false;
}
bool check_a(section& s1, section& s2, section& s3) {
  if (have_same_point(s1, s2)) {
  } else if (have_same_point(s1, s3)) {
    swap(s2, s3);
  } else if (have_same_point(s2, s3)) {
    swap(s1, s3);
  } else {
    cout << "NO" << endl;
    return false;
  }
  auto dotAn = s1.to_vector().dotNormalized(s2.to_vector());
  if (dotAn < 0 || s1.to_vector().same_angle(s2.to_vector())) {
    cout << "NO" << endl;
    return false;
  }
  if (is_middle_section(s1, s2, s3)) {
    cout << "YES" << endl;
    return true;
  }
  cout << "NO" << endl;
  return true;
}
void run_all_tests() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    section s1, s2, s3;
    cin >> s1.start.x >> s1.start.y >> s1.end.x >> s1.end.y;
    cin >> s2.start.x >> s2.start.y >> s2.end.x >> s2.end.y;
    cin >> s3.start.x >> s3.start.y >> s3.end.x >> s3.end.y;
    check_a(s1, s2, s3);
  }
}
int main() {
  run_all_tests();
  return 0;
}
