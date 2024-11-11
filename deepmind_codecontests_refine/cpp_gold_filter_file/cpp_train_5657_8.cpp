#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 9000000000000000000;
template <typename first, typename second>
ostream &operator<<(ostream &os, const pair<first, second> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ",";
    os << *it;
  }
  return os << "]";
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename first, typename second>
ostream &operator<<(ostream &os, const map<first, second> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << it->first << " = " << it->second;
  }
  return os << "]";
}
void faltu() { cerr << '\n'; }
template <typename T>
void faltu(T a[], int n) {
  for (int i = 0; i < n; ++i) cerr << a[i] << ' ';
  cerr << '\n';
}
template <typename T, typename... hello>
void faltu(T arg, const hello &...rest) {
  cerr << arg << ' ';
  faltu(rest...);
}
const int mx = 1e5 + 5;
double EPS = 1e-12;
struct PT {
  long long x, y;
  PT() {}
  PT(long long x, long long y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y) {}
  PT operator+(const PT &p) const { return PT(x + p.x, y + p.y); }
  PT operator-(const PT &p) const { return PT(x - p.x, y - p.y); }
  PT operator*(double c) const { return PT(x * c, y * c); }
  PT operator/(double c) const { return PT(x / c, y / c); }
  bool operator<(const PT &p) const { return x < p.x || (x == p.x && y < p.y); }
};
ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ")";
}
bool isPointsCW(PT a, PT b, PT c) {
  return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}
bool isPointsCCW(PT a, PT b, PT c) {
  return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}
bool isPointsCollinear(PT a, PT b, PT c) {
  return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) == 0;
}
void convex_hull(vector<PT> &a) {
  int a_sz = a.size();
  if (a_sz == 1) return;
  sort(a.begin(), a.end());
  PT p1 = a[0], p2 = a.back();
  vector<PT> up, down;
  up.push_back(p1);
  down.push_back(p1);
  int up_sz = 1, down_sz = 1;
  for (int i = 1; i < a_sz; i++) {
    if (i == a_sz - 1 || isPointsCW(p1, a[i], p2)) {
      while (up_sz >= 2 &&
             (!isPointsCW(up[up_sz - 2], up[up_sz - 1], a[i]) &&
              !isPointsCollinear(up[up_sz - 2], up[up_sz - 1], a[i]))) {
        up.pop_back();
        --up_sz;
      }
      up.push_back(a[i]);
      ++up_sz;
    }
    if (i == a_sz - 1 || isPointsCCW(p1, a[i], p2)) {
      while (down_sz >= 2 &&
             (!isPointsCCW(down[down_sz - 2], down[down_sz - 1], a[i]) &&
              !isPointsCollinear(down[down_sz - 2], down[down_sz - 1], a[i]))) {
        down.pop_back();
        --down_sz;
      }
      down.push_back(a[i]);
      ++down_sz;
    }
  }
  a.clear();
  for (int i = 0; i < up_sz; i++) a.push_back(up[i]);
  for (int i = down_sz - 2; i > 0; i--) a.push_back(down[i]);
}
vector<PT> vec;
set<PT> st;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, m;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    vec.push_back(PT(x, y));
  }
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    vec.push_back(PT(x, y));
    st.insert(PT(x, y));
  }
  convex_hull(vec);
  for (auto x : vec) {
    if (st.lower_bound(x) != st.upper_bound(x)) {
      cout << "NO" << '\n';
      ;
      return 0;
    }
  }
  cout << "YES" << '\n';
}
