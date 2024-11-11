#include <bits/stdc++.h>
using namespace std;
class Debugger {
 public:
  Debugger(const std::string& _separator = ", ")
      : first(true), separator(_separator) {}
  template <typename ObjectType>
  Debugger& operator,(const ObjectType& v) {
    if (!first) cerr << separator;
    cerr << v;
    first = false;
    return *this;
  }
  ~Debugger() { cerr << "\n"; }

 private:
  bool first;
  string separator;
};
template <typename T1, typename T2>
inline ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
inline ostream& operator<<(ostream& os, const vector<T>& v) {
  bool first = true;
  os << "[";
  for (unsigned long long i = 0; i < v.size(); i++) {
    if (!first) os << ", ";
    os << v[i];
    first = false;
  }
  return os << "]";
}
template <typename T>
inline ostream& operator<<(ostream& os, const set<T>& v) {
  bool first = true;
  os << "[";
  for (typename set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
    if (!first) os << ", ";
    os << *ii;
    first = false;
  }
  return os << "]";
}
template <typename T1, typename T2>
inline ostream& operator<<(ostream& os, const map<T1, T2>& v) {
  bool first = true;
  os << "[";
  for (typename map<T1, T2>::const_iterator ii = v.begin(); ii != v.end();
       ++ii) {
    if (!first) os << ", ";
    os << *ii;
    first = false;
  }
  return os << "]";
}
long long xx = 1000000000, yy = 1;
set<long long> grid;
long long massiv[300000];
long long n;
int main() {
  ios_base::sync_with_stdio(0);
  ;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> massiv[i];
  }
  for (long long i = 1; i < n; i++) {
    if (yy < abs(massiv[i + 1] - massiv[i])) {
      yy = abs(massiv[i + 1] - massiv[i]);
    }
  }
  for (long long i = 1; i < n; i++) {
    if ((abs(massiv[i + 1] - massiv[i]) != yy &&
         abs(massiv[i + 1] - massiv[i]) != 1) ||
        (massiv[i] % yy == 0 && massiv[i + 1] - massiv[i] == 1 && yy != 1) ||
        (massiv[i] % yy == 1 && massiv[i + 1] - massiv[i] == -1 && yy != 1)) {
      cout << "NO"
           << "\n";
      return 0;
    }
  }
  cout << "YES"
       << "\n";
  cout << xx << " " << yy << "\n";
  return 0;
}
