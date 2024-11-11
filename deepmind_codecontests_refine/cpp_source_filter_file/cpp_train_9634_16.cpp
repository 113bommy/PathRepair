#include <bits/stdc++.h>
double const EPS = 3e-8;
using namespace std;
template <class T>
T gcd(T a, T b) {
  return (b != 0 ? gcd<T>(b, a % b) : a);
}
template <class T>
T lcm(T a, T b) {
  return (a / gcd<T>(a, b) * b);
}
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
long long a, b, c;
vector<int> sv;
int need(long long x) {
  int digit = 0;
  if (x == 0) return 1;
  while (x > 0) {
    x /= 7ll;
    digit += 1;
  }
  return digit;
}
int main() {
  c = 7ll;
  a = ({
    long long a;
    read(a);
    a;
  }),
  b = ({
    long long a;
    read(a);
    a;
  });
  int mxa = need(a);
  int mxb = need(b);
  int total = mxa + mxb;
  if (total > 8) {
    printf("0\n");
  } else {
    long long ans = 0;
    for (int i = 0; i < a; i++) {
      int freq[10] = {0};
      sv.clear();
      int now = i;
      int ok = 1;
      int tot = 0;
      if (now == 0) {
        freq[0] = 1;
        tot = 1;
        sv.push_back(0);
      }
      while (now > 0 && ok) {
        if (freq[now % 7ll]) {
          ok = 0;
          break;
        } else {
          freq[now % 7ll] = 1;
          sv.push_back(now % 7ll);
        }
        now /= 7ll;
        tot++;
      }
      if (mxa - tot > 1) continue;
      if (mxa - tot == 1 && freq[0] == 1)
        continue;
      else if (mxa - tot == 1) {
        freq[0] = 1;
        sv.push_back(0);
      }
      if (ok == 0) continue;
      for (int j = 0; j < b; j++) {
        int xnow = j;
        ok = 1;
        int tot = 0;
        if (xnow == 0 && freq[0])
          continue;
        else if (xnow == 0) {
          freq[0] = 1;
          tot = 1;
        }
        while (xnow > 0 && ok) {
          if (freq[xnow % 7ll]) {
            ok = 0;
            break;
          } else {
            freq[xnow % 7ll] = 1;
          }
          xnow /= 7;
          tot++;
        }
        if (mxb - tot > 1) {
          ok = 0;
        } else if (mxb - tot == 1 && freq[0] == 1) {
          ok = 0;
        }
        for (__typeof((10) - 1) k = (0); k <= (10) - 1; ++k) freq[k] = 0;
        int sz = sv.size();
        for (__typeof((sz)-1) k = (0); k <= (sz)-1; ++k) freq[sv[k]] = 1;
        if (ok) {
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
