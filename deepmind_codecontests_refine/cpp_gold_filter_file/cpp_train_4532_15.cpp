#include <bits/stdc++.h>
template <class A, class B, class C>
struct triple {
  A first;
  B second;
  C third;
  triple(A, B, C);
  triple();
};
template <class A, class B, class C>
triple<A, B, C>::triple(A a, B b, C c) {
  first = a;
  second = b;
  third = c;
}
template <class A, class B, class C>
triple<A, B, C>::triple() {}
template <class A, class B, class C>
triple<A, B, C> make_triple(A a, B b, C c) {
  triple<A, B, C> t(a, b, c);
  return t;
}
template <class A, class B, class C>
bool operator<(triple<A, B, C> a, triple<A, B, C> b) {
  if (a.first != b.first) return a.first < b.first;
  if (a.second != b.second) return a.second < b.second;
  if (a.third != b.third) return a.third < b.third;
}
template <class T>
T inline sqr(T a) {
  return a * a;
}
const long double PI = 3.141592653589793;
const long double E = 2.71828182845904523;
const long long LLINF = 9000000009000000099;
const long long INF = 2009000099;
const long long MOD = 1000000008;
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  long long res = 0;
  int r, c, n, k;
  cin >> r >> c >> n >> k;
  vector<pair<int, int>> alt(n);
  vector<vector<int>> d(r, vector<int>(c, 0));
  for (int i = 0; i < n; ++i) {
    cin >> alt[i].first >> alt[i].second;
    alt[i].first--;
    alt[i].second--;
    d[alt[i].first][alt[i].second]++;
  }
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      for (int i1 = i; i1 < r; ++i1)
        for (int j1 = j; j1 < c; ++j1) {
          long long cur = 0;
          for (int x = i; x <= i1; ++x)
            for (int y = j; y <= j1; ++y) cur += d[x][y];
          if (cur >= k) res++;
        }
  cout << res;
}
