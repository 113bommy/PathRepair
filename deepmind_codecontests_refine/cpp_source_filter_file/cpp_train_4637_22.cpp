#include <bits/stdc++.h>
using namespace std;
template <typename T>
std::ostream& operator<<(std::ostream& os, const vector<T>& v) {
  os << "[";
  int N = v.size();
  for (int i = 0; i < N; i++) {
    os << v[i];
    if (i != (N - 1)) os << ", ";
  }
  os << "]" << endl;
}
template <typename T, typename S>
std::ostream& operator<<(std::ostream& os, const std::map<T, S>& m) {
  os << "{";
  bool first = true;
  typename map<T, S>::iterator it;
  for (it = m.begin(); it != m.end(); ++it) {
    if (!first) os << ", ";
    first = false;
    os << it->first << " <= " << it->second;
  }
  os << "}" << endl;
}
typedef struct Point {
  double x, y, z;
} Point;
vector<Point> points(10002);
vector<double> times(10002);
Point start, ret;
double vp, vs;
int N;
bool check(double time) {
  vector<double>::iterator it =
      lower_bound(times.begin(), times.begin() + N, time);
  Point cur;
  if (abs(*it - time) < 10E-9) {
    cur = points[it - times.begin()];
  } else {
    if (it != times.begin()) it--;
    double t_move = time - *it;
    int i = it - times.begin();
    cur = points[i];
    Point vec;
    vec.x = points[i + 1].x - points[i].x;
    vec.y = points[i + 1].y - points[i].y;
    vec.z = points[i + 1].z - points[i].z;
    double len = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
    vec.x /= len;
    vec.y /= len;
    vec.z /= len;
    cur = points[i];
    cur.x += vec.x * vs * t_move;
    cur.y += vec.y * vs * t_move;
    cur.z += vec.z * vs * t_move;
  }
  ret = cur;
  cur.x -= start.x;
  cur.y -= start.y;
  cur.z -= start.z;
  if ((cur.x * cur.x + cur.y * cur.y + cur.z * cur.z - time * vp * time * vp) >
      10E-9) {
    return false;
  } else {
    return true;
  }
}
int main() {
  cin >> N;
  cout << setprecision(12);
  for (int i = 0; i <= N; i++) {
    cin >> points[i].x >> points[i].y >> points[i].z;
  }
  cin >> vp >> vs;
  cin >> start.x >> start.y >> start.z;
  double len = 0;
  times[0] = 0;
  for (int i = 1; i <= N; i++) {
    len +=
        sqrt((points[i].x - points[i - 1].x) * (points[i].x - points[i - 1].x) +
             (points[i].y - points[i - 1].y) * (points[i].y - points[i - 1].y) +
             (points[i].z - points[i - 1].z) * (points[i].z - points[i - 1].z));
    times[i] = len / vs;
  }
  double l = 0;
  double r = times[N];
  if (!check(r))
    cout << "NO";
  else {
    for (int i = 0; i < 700; i++) {
      double mid = (l + r) / 2;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid;
      }
    }
    cout << "YES" << endl << r / 2 << endl;
    cout << ret.x << " " << ret.y << " " << ret.z;
  }
  return 0;
}
