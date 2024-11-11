#include <bits/stdc++.h>
using namespace std;
template <typename T>
vector<T>& operator--(vector<T>& v) {
  for (auto& i : v) --i;
  return v;
}
template <typename T>
vector<T>& operator++(vector<T>& v) {
  for (auto& i : v) ++i;
  return v;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& i : v) os << i << ' ';
  return os;
}
template <typename T, typename U>
istream& operator>>(istream& is, pair<T, U>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U>& p) {
  os << p.first << ' ' << p.second;
  return os;
}
template <typename T, typename U>
pair<T, U> operator-(pair<T, U> a, pair<T, U> b) {
  return make_pair(a.first - b.first, a.second - b.second);
}
template <typename T, typename U>
pair<T, U> operator+(pair<T, U> a, pair<T, U> b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
template <typename T, typename U>
void umin(T& a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
void umax(T& a, U b) {
  if (a < b) a = b;
}
long double p13 = 1.0l / 3;
long double p14 = 1.0l / 4;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  int x, y;
  cin >> x >> y;
  if (m == 1) {
    cout << (n - x) * 2 << '\n';
    return 0;
  }
  vector<vector<long double>> e(n, vector<long double>(m, 0));
  for (int i = n - 2; i >= 0; --i) {
    long double b = -p13 * e[i + 1][0] - 1;
    long double c1 = -1.0l + p13;
    long double c2 = p13;
    vector<pair<pair<long double, long double>, long double>> koef(m);
    koef[0] = make_pair(make_pair(c1, c2), b);
    for (int j = 1; j < m - 1; ++j) {
      long double k = -p14 / c1;
      c1 *= k;
      c2 *= k;
      b *= k;
      long double c3 = 0;
      c1 += p14;
      c2 -= (1.0l - p14);
      c3 += p14;
      b += -p14 * e[i + 1][j] - 1;
      assert(abs(c1) < 1e-9);
      c1 = c2;
      c2 = c3;
      koef[j] = make_pair(make_pair(c1, c2), b);
    }
    long double k = -p13 / c1;
    c1 *= k;
    c2 *= k;
    c1 += p13;
    assert(abs(c1) < 1e-9);
    b *= k;
    c2 -= (1.0l - p13);
    b += -p13 * e[i + 1][m - 1] - 1;
    e[i][m - 1] = b / c2;
    for (int j = m - 2; j >= 0; --j) {
      e[i][j] = (koef[j].second - koef[j].first.second * e[i][j + 1]) /
                koef[j].first.first;
    }
  }
  --x;
  --y;
  cout << fixed << setprecision(20) << e[x][y] << '\n';
  return 0;
}
