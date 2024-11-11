#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
ostream& operator<<(ostream& o, pair<A, B>& p) {
  return o << "(" << p.first << ", " << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& o, const vector<T>& v) {
  o << "{";
  for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
    o << *it << ", ";
  return o << "}";
}
struct debugger {
  ostream& out;
  bool first;
  void start() { first = true; }
  debugger(ostream& out) : out(out) { start(); }
  void nl() {
    out << endl;
    start();
  }
  template <class T>
  debugger& operator,(T& v) {
    if (first)
      first = false;
    else
      out << ", ";
    out << v;
    return *this;
  }
  template <class T>
  debugger& operator,(pair<T*, int> arr) {
    out << "{";
    for (typeof((arr.second) - 1) i = (0); i <= ((arr.second) - 1); i++) {
      out << arr.first[i] << ", ";
    }
    out << "}";
    return *this;
  }
} dbg(cerr);
int n, m;
vector<pair<int, int> > v;
int vis[1111][1111];
pair<double, vector<pair<int, int> > > bf(int d, int l, int x = 0, int y = 0) {
  vector<pair<int, int> > temp;
  if (d == l) return make_pair(0, temp);
  double ans = 0;
  vector<pair<int, int> > a;
  for (typeof(((int)v.size()) - 1) h = (0); h <= (((int)v.size()) - 1); h++) {
    {
      int i = v[h].first;
      int j = v[h].second;
      if (!vis[i][j]) {
        vis[i][j] = 1;
        double ret = 0;
        pair<double, vector<pair<int, int> > > z;
        if (d) ret = sqrt(abs(i - x) * abs(i - x) + abs(j - y) * abs(j - y));
        z = bf(d + 1, l, i, j);
        ret += z.first;
        vector<pair<int, int> > v = z.second;
        if (ans < ret) {
          ans = ret;
          v.push_back(pair<int, int>(i, j));
          a = v;
        }
        vis[i][j] = 0;
      }
    }
  }
  return make_pair(ans, a);
}
int main() {
  {
    cin >> n >> m;
    v.push_back(pair<int, int>(n, m));
    v.push_back(pair<int, int>(0, m));
    v.push_back(pair<int, int>(n, 0));
    v.push_back(pair<int, int>(0, 0));
    if (n - 1 >= 0) v.push_back(pair<int, int>(n - 1, m));
    if (n - 1 >= 0) v.push_back(pair<int, int>(n - 1, 0));
    if (m - 1 >= 0) v.push_back(pair<int, int>(n, m - 1));
    if (m - 1 >= 0) v.push_back(pair<int, int>(0, m - 1));
    if (n >= 1) v.push_back(pair<int, int>(1, m));
    if (n >= 1) v.push_back(pair<int, int>(1, 0));
    if (m >= 1) v.push_back(pair<int, int>(n, 1));
    if (m >= 1) v.push_back(pair<int, int>(0, 1));
    pair<double, vector<pair<int, int> > > z = bf(0, 4, 0, 0);
    for (typeof((4) - 1) i = (0); i <= ((4) - 1); i++) {
      cout << z.second[i].first << " " << z.second[i].second << endl;
    }
  }
  return 0;
}
