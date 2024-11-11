#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
template <class T>
inline int len(const T &a) {
  return a.size();
}
const double EPS = 1e-9;
const double PI = 3.14159265358979323846264338328;
const long long LINF = (long long)1e16 + 5;
template <class T>
inline int toInt(const T &t) {
  int n;
  stringstream ss;
  ss << t;
  ss >> n;
  return n;
}
template <class T>
inline string toStr(const T &t) {
  stringstream ss;
  ss << t;
  return ss.str();
}
template <class T>
inline long long toInt64(const T &t) {
  long long n;
  stringstream ss;
  ss << t;
  ss >> n;
  return n;
}
template <typename T>
int sgn(T val) {
  return (T(0) < val) - (val < T(0));
}
template <class T>
T gcd(T a, T b) {
  T r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <typename T1, typename T2>
inline std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
inline std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
  bool first = true;
  os << "[";
  for (unsigned int i = 0; i < v.size(); i++) {
    if (!first) os << ", ";
    os << v[i];
    first = false;
  }
  return os << "]";
}
template <typename T>
inline std::ostream &operator<<(std::ostream &os, const std::set<T> &S) {
  bool first = true;
  os << "set([";
  for (typename std::set<T>::const_iterator it = S.begin(); it != S.end();
       ++it) {
    if (!first) os << ", ";
    os << *it;
    first = false;
  }
  return os << "])";
}
template <typename T1, typename T2>
inline std::ostream &operator<<(std::ostream &os, const std::map<T1, T2> &d) {
  bool first = true;
  os << "{";
  for (typename std::map<T1, T2>::const_iterator it = d.begin(); it != d.end();
       ++it) {
    if (!first) os << ", ";
    os << it->first << ": " << it->second;
    first = false;
  }
  return os << "}";
}
struct debugger {
  template <typename T>
  debugger &operator,(const T v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
int main() {
  int V, E, s;
  scanf("%d %d %d", &V, &E, &s);
  long long lo = V - 1;
  long long hi = V - 1;
  long long U = (long long)V;
  U -= 2;
  hi += U * (U - 1);
  vector<int> u;
  int v = -1;
  if ((E < lo) || (E > hi)) {
    printf("-1\n");
    return 0;
  } else {
    for (int i = 1; i <= V; i++)
      if (i != s) printf("%d %d\n", s, i);
    E -= (V - 1);
    for (int i = 1; i <= V; i++) {
      if (i == s) continue;
      if (v == -1) {
        v = i;
        continue;
      }
      u.push_back(i);
    }
  }
  if (!E) return 0;
  for (int i = 0; i < len(u); i++)
    for (int j = i + 1; j < len(u); j++)
      if (E) {
        printf("%d %d\n", u[i], u[j]);
        E--;
        if (E == 0) return 0;
      }
  return 0;
}
