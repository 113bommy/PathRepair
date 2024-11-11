#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << "\t";
    return *this;
  }
} dbg;
template <class A, class B>
ostream& operator<<(ostream& o, const pair<A, B>& p) {
  return o << "(" << p.first << ", " << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& o, const vector<T>& v) {
  o << "[";
  for (__typeof((v).end()) it = (v).begin(); it != (v).end(); ++it)
    o << *it << ", ";
  return o << "]";
}
template <class T>
ostream& operator<<(ostream& o, const set<T>& v) {
  o << "[";
  for (__typeof((v).end()) it = (v).begin(); it != (v).end(); ++it)
    o << *it << ", ";
  return o << "]";
}
template <class T>
inline void MAX(T& a, T b) {
  if (a < b) a = b;
}
template <class T>
inline void MIN(T& a, T b) {
  if (a > b) a = b;
}
template <class T>
inline bool read(T& x) {
  int c = getchar();
  int sgn = 1;
  while (~c && c < '0' || c > '9') {
    if (c == '-') sgn = -1;
    c = getchar();
  }
  for (x = 0; ~c && '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  x *= sgn;
  return ~c;
}
const int MX = 1e5 + 7;
int N, L[MX], R[MX];
int main() {
  cin >> N;
  for (__typeof(N) i = (1); i <= N; ++i) cin >> L[i] >> R[i];
  int x = MX, y = 0;
  for (__typeof(N) i = (1); i <= N; ++i) MIN(x, L[i]), MAX(y, R[i]);
  for (__typeof(N) i = (1); i <= N; ++i) {
    if (L[i] <= x and y <= R[i]) {
      cout << i << endl;
      return 0;
    }
  }
  puts("-1");
}
