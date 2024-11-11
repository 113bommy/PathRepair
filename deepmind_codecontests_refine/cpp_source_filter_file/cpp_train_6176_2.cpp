#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
struct DDMY {
  ostringstream o;
  template <class T>
  DDMY &operator,(const T &t) {
    o << t << ",";
    return *this;
  }
  string operator*() { return o.str().substr(0, o.str().size() - 1); }
};
template <class T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "[";
  for (std::size_t i = 0; i < v.size(); i++)
    o << v[i] << (i < v.size() - 1 ? "," : "");
  return o << "]";
}
template <class T, class U>
std::ostream &operator<<(std::ostream &o, const std::pair<T, U> &v) {
  return o << v.first << ":" << v.second;
}
template <class T, class U>
std::ostream &operator<<(std::ostream &o, const std::map<T, U> &v) {
  o << "{";
  typename std::map<T, U>::const_iterator i = v.begin(), j = i;
  ++j;
  for (; i != v.end(); ++i, ++j) o << *i << (j != v.end() ? "," : "");
  return o << "}";
}
template <class T>
std::ostream &operator<<(std::ostream &o, const std::set<T> &v) {
  o << "{";
  typename std::set<T>::const_iterator i = v.begin(), j = i;
  ++j;
  for (; i != v.end(); ++i, ++j) o << *i << (j != v.end() ? "," : "");
  return o << "}";
}
long long int n, m;
long long int xcc, ycc;
long long int k;
vector<pair<long long int, long long int> > steps;
long long int solve() {
  long long int res = 0;
  long long int xc = xcc, yc = ycc;
  for (int i = 0; i < k; i++) {
    long long int dx = abs(steps[i].first), dy = abs(steps[i].second);
    long long int step;
    long long int ddx = steps[i].first, ddy = steps[i].second;
    if (ddx < 0) {
      if (ddy < 0) {
        step = min((xc - 1) / dx, (yc - 1) / dy);
      } else if (ddy == 0) {
        step = (xc - 1) / dx;
      } else {
        step = min((xc - 1) / dx, (m - yc) / dy);
      }
    } else if (ddx == 0) {
      if (ddy < 0) {
        step = (yc - 1) / dy;
      } else if (ddy == 0) {
        continue;
      } else {
        step = (m - yc) / dy;
      }
    } else {
      if (ddy < 0) {
        step = min((n - xc) / dx, (yc - 1) / dy);
      } else if (ddy == 0) {
        step = (n - xc) / dx;
      } else {
        step = min((n - xc) / dx, (m - yc) / dy);
      }
    }
    res += step;
    xc = xc + dx * step;
    yc = yc + dy * step;
  }
  return res;
}
int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  cin >> xcc >> ycc;
  cin >> k;
  for (int i = 0; i < k; i++) {
    long long int dx, dy;
    cin >> dx >> dy;
    steps.push_back(make_pair(dx, dy));
  }
  cout << solve() << endl;
  return 0;
}
