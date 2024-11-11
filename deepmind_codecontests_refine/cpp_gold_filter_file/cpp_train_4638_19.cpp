#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  os << "{" << p.first << ", " << p.second << "}";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& p) {
  os << "[";
  int i = 0;
  for (typename vector<T>::const_iterator it = p.begin(); it != p.end(); ++it) {
    os << (i == 0 ? "" : ", ") << *it;
    i++;
  }
  os << "]";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& p) {
  os << "[";
  int i = 0;
  for (typename set<T>::const_iterator it = p.begin(); it != p.end(); ++it) {
    os << (i == 0 ? "" : ", ") << *it;
    i++;
  }
  os << "]";
  return os;
}
template <class K, class V>
ostream& operator<<(ostream& os, const map<K, V>& p) {
  os << "[";
  int i = 0;
  for (typename map<K, V>::const_iterator it = p.begin(); it != p.end(); ++it) {
    os << (i == 0 ? "" : ", ") << *it;
    i++;
  }
  os << "]";
  return os;
}
template <class T>
string toString(const T& o) {
  stringstream ss;
  ss << o;
  string ret;
  getline(ss, ret);
  return ret;
}
ostream& operator<<(ostream& os, const string& o) {
  os << "\"" << o.c_str() << "\"";
  return os;
}
long double vp, vs;
long double px, py, pz;
double func(long double mid, long double a, long double b, long double x1,
            long double y1, long double z1, long double x2, long double y2,
            long double z2) {
  long double mn = (mid - a) / (b - a);
  long double Px = x1 + mn * (x2 - x1);
  long double Py = y1 + mn * (y2 - y1);
  long double Pz = z1 + mn * (z2 - z1);
  long double fmid =
      (Px - px) * (Px - px) + (Py - py) * (Py - py) + (Pz - pz) * (Pz - pz);
  long double dist = vp * mid;
  return fmid - dist * dist;
}
long double rx, ry, rz, rt, nt;
bool check(long double time, long double x1, long double y1, long double z1,
           long double x2, long double y2, long double z2) {
  long double dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) +
                          (z1 - z2) * (z1 - z2));
  long double a = time;
  long double b = time + dist / vs;
  long double st = a, end = b;
  nt = end;
  long double eps = 1E-10l;
  long double fb = func(b, st, end, x1, y1, z1, x2, y2, z2);
  if (fb > eps) return false;
  while (fabs(b - a) > eps) {
    long double mid = (b + a) / 2.0l;
    long double fmid = func(mid, st, end, x1, y1, z1, x2, y2, z2);
    if (fmid > 0.0l)
      a = mid;
    else
      b = mid;
  }
  rt = (b + a) / 2.0l;
  long double mn = (rt - st) / (end - st);
  rx = x1 + mn * (x2 - x1);
  ry = y1 + mn * (y2 - y1);
  rz = z1 + mn * (z2 - z1);
  return true;
}
int main() {
  int n;
  cin >> n;
  vector<long double> x(n + 1), y(n + 1), z(n + 1);
  for (int i = 0; i < n + 1; ++i) cin >> x[i] >> y[i] >> z[i];
  cin >> vp >> vs;
  cin >> px >> py >> pz;
  long double tm = 0.0l;
  for (int i = 0; i < n; ++i) {
    if (check(tm, x[i], y[i], z[i], x[i + 1], y[i + 1], z[i + 1])) {
      cout.precision(8);
      cout << "YES" << endl;
      cout << fixed << rt << endl;
      cout << fixed << rx << " ";
      cout << fixed << ry << " ";
      cout << fixed << rz << endl;
      return 0;
    }
    tm = nt;
  }
  cout << "NO" << endl;
  return 0;
}
