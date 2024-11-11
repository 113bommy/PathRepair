#include <bits/stdc++.h>
int IntMaxVal = (int)1e20;
int IntMinVal = (int)-1e20;
long long LongMaxVal = (long long)1e20;
long long LongMinVal = (long long)-1e20;
using namespace std;
template <typename T>
struct argument_type;
template <typename T, typename U>
struct argument_type<T(U)> {};
template <typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2>& s) {
  is >> s.first >> s.second;
  return is;
}
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  double r;
  cin >> r;
  ;
  pair<double, pair<int, int> > res = make_pair(10000.0, make_pair(1, 1));
  for (int a = 1; a < 11; ++a) {
    if (a / 2.0 < r) continue;
    double alpha = acos(r / a * 2.0);
    double h = a / tan(alpha) / 2;
    int h2 = (int)(h + 0.1);
    double eps = fabs(h2 - h);
    { res = min(res, make_pair(eps, make_pair(a, h2))); };
  }
  cout << res.second.first << ' ' << res.second.second;
}
