#include <bits/stdc++.h>
using namespace std;
const int infinity = 2000000999 / 2;
const long long int inff = 4000000000000000999;
template <class T>
T get() {
  T a;
  cin >> a;
  return a;
}
template <class T, class U>
ostream& operator<<(ostream& out, const pair<T, U>& par) {
  out << "[" << par.first << ";" << par.second << "]";
  return out;
}
template <class T>
ostream& operator<<(ostream& out, const set<T>& cont) {
  out << "{";
  for (const auto& x : cont) out << x << ", ";
  out << "}";
  return out;
}
template <class T, class U>
ostream& operator<<(ostream& out, const map<T, U>& cont) {
  out << "{";
  for (const auto& x : cont) out << x << ", ";
  out << "}";
  return out;
}
template <class T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  for (int i = 0; i < (int)v.size(); i++) {
    if (i) out << " ";
    out << v[i];
  }
  out << endl;
  return out;
}
bool ccw(complex<long double> p, complex<long double> a,
         complex<long double> b) {
  if ((conj(a - p) * (b - p)).imag() <= 0)
    return false;
  else
    return true;
}
int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  int time_st = abs(x - y) * t1;
  int time_ele = abs(x - z) * t2 + 3 * t3 + abs(x - y) * t2;
  if (time_st < time_ele)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
