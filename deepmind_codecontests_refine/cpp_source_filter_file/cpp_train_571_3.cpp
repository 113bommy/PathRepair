#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template <class A, class B>
bool maxi(A &a, const B &b) {
  return (a < b) ? (a = b, true) : false;
};
template <class A, class B>
bool mini(A &a, const B &b) {
  return (a > b) ? (a = b, true) : false;
};
const int maxN = 1e5 + 5;
const double oo = 1.0 / 0.0, eps = 1e-9, pi = atan2(1, 1) * 4;
const ll inf = 1e18;
int n;
double mn = oo, mx = -oo;
pair<int, int> P, p[maxN];
double Cross(const pair<int, int> &o, const pair<int, int> &a,
             const pair<int, int> &b) {
  return (a.first - o.first) * (double)(b.second - o.second) -
         (a.second - o.second) * (double)(b.first - o.first);
}
bool eq(const double a, const double b) { return fabs(a - b) <= eps; }
double Area(const pair<int, int> &A, const pair<int, int> &B,
            const pair<int, int> &C) {
  return fabs(Cross(A, B, C)) / 2.0;
}
double Square(const double x) { return x * x; }
double Distance(const pair<int, int> &a, const pair<int, int> &b) {
  return sqrt(Square(a.first - b.first) + Square(a.second - b.second));
}
double Distance(const pair<int, int> &O, const pair<int, int> &A,
                const pair<int, int> &B) {
  const double AB = Distance(A, B), OH = Area(O, A, B) / AB,
               OA = Distance(O, A), OB = Distance(O, B),
               HA = sqrt(Square(OA) - Square(OH)),
               HB = sqrt(Square(OB) - Square(OH));
  if (eq(AB, HA + HB)) return OH;
  return min(OA, OB);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> P.first >> P.second;
  for (int i = (0), _b = (n); i < _b; ++i) {
    cin >> p[i].first >> p[i].second;
    maxi(mx, Distance(P, p[i]));
  }
  for (int i = (0), _b = (n); i < _b; ++i)
    mini(mn, Distance(P, p[i], p[(i + 1) % n]));
  cout << setprecision(12) << fixed << pi * (Square(mx) - Square(mn)) << '\n';
  return 0;
}
