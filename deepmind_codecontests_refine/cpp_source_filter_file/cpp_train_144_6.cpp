#include <bits/stdc++.h>
using namespace std;
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
int main() {
  vector<int> x;
  int n = ({
    int a;
    scanf("%d", &a);
    a;
  }),
      c = ({
        int a;
        scanf("%d", &a);
        a;
      });
  for (__typeof((n)-1) i = (0); i <= (n)-1; ++i)
    x.push_back(({
      int a;
      scanf("%d", &a);
      a;
    }));
  int ans = -1;
  for (__typeof((n - 1) - 1) i = (0); i <= (n - 1) - 1; ++i) {
    int tt = x[i] - x[i + 1] - c;
    if (tt > ans) ans = tt;
  }
  cout << ans << endl;
}
