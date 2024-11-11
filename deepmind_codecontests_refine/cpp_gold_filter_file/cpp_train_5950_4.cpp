#include <bits/stdc++.h>
using namespace std;
__int128 gcd(__int128 a, __int128 b) { return a ? gcd(b % a, a) : b; }
struct Frac {
  __int128 a, b;
  Frac() {
    a = 0;
    b = 1;
  }
  Frac(__int128 _a, __int128 _b) {
    __int128 g = gcd(_a, _b);
    a = _a / g;
    b = _b / g;
    if (b < 0) a = -a, b = -b;
  }
  Frac operator-() { return Frac(-a, b); }
  Frac operator+(Frac n) { return Frac(a * n.b + b * n.a, b * n.b); }
  Frac operator-(Frac n) { return Frac(a * n.b - b * n.a, b * n.b); }
  Frac operator*(Frac n) { return Frac(a * n.a, b * n.b); }
  Frac operator/(Frac n) { return Frac(a * n.b, b * n.a); }
  void operator+=(Frac n) { *this = *this + n; }
  void operator-=(Frac n) { *this = *this - n; }
  void operator*=(Frac n) { *this = *this * n; }
  void operator/=(Frac n) { *this = *this / n; }
  bool operator>(Frac n) { return a * n.b > n.a * b; }
  bool operator<(Frac n) { return a * n.b < n.a * b; }
  bool operator>=(Frac n) { return a * n.b >= n.a * b; }
  bool operator<=(Frac n) { return a * n.b <= n.a * b; }
  bool operator==(Frac n) { return a * n.b == n.a * b; }
};
int N;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(ios::badbit | ios::failbit);
  cin >> N;
  map<long long, long long> m;
  for (int i = 1; i <= N; i++) {
    long long x, y;
    cin >> x >> y;
    if (m.find(x) == m.end())
      m[x] = y;
    else
      m[x] = max(m[x], y);
  }
  vector<pair<long long, long long> > st;
  for (auto [x, y] : m) {
    while (st.size() >= 2) {
      auto [xi, yi] = st[(int)st.size() - 2];
      auto [xj, yj] = st.back();
      long long ai = yi - xi * xi;
      long long aj = yj - xj * xj;
      Frac b(ai - aj, xi - xj);
      Frac c(aj * xi - ai * xj, xi - xj);
      if (Frac(y, 1) >= Frac(x * x, 1) + b * Frac(x, 1) + c) {
        st.pop_back();
      } else {
        break;
      }
    }
    st.push_back({x, y});
  }
  int cnt = (int)st.size() - 1;
  cout << cnt << "\n";
  return 0;
}
