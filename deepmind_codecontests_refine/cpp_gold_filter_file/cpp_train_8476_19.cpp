#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979323846;
const double E = 2.7182818284590452354;
const struct _ {
  ios_base::Init i;
  int s;
  _() : s(ios_base::xalloc()) {
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  }
} _;
inline ostream& operator<<(ostream& o, const struct _&) {
  o.iword(_.s) = 0;
  return o << '\n';
}
template <class T>
inline ostream& operator,(ostream& o, const T& x) {
  if (o.iword(_.s))
    o << ' ';
  else
    o.iword(_.s) = 1;
  return o << x;
}
template <>
inline ostream& operator, <struct _>(ostream& o, const struct _&) {
  return o << _;
}
template <class I>
inline void in(I A, I B) {
  while (A != B) {
    cin >> *A;
    ++A;
  }
}
template <class I>
inline void out(I A, I B, char D = ' ') {
  if (A != B) {
    cout << *A;
    while (++A != B) {
      cout << D << *A;
    }
  }
  cout << _;
}
template <class T>
inline T sq(const T& X) {
  return X * X;
}
template <class T>
inline T power(T X, int Y) {
  assert(Y >= 0 && !(X == 0 && Y == 0));
  T R = (Y & 1) ? X : 1;
  while (Y >>= 1) {
    X *= X;
    if (Y & 1) R *= X;
  }
  return R;
}
long double eps = 1e-5;
int main() {
  long double x;
  cin >> x;
  for (int a = 1; a <= 10; a++) {
    for (int h = 1; h <= 10; h++) {
      long double s1 = sq(a / 2.0L) - sq(x);
      long double s2 = sq(h) - sq(x);
      long double s12 = sq(a / 2.0L) + sq(h);
      if (s1 <= eps || s2 <= eps) continue;
      if (fabsl((sqrtl(s1) + sqrtl(s2)) - sqrtl(s12)) < eps) {
        cout, a, h, _;
        return 0;
      }
    }
  }
}
