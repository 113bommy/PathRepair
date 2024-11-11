#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
template <class T>
istream &operator>>(istream &, vector<T> &);
template <class T>
ostream &operator<<(ostream &, const vector<T> &);
using ll = long long;
using vll = vector<long long>;
constexpr int INF = 0x3f3f3f3f;
constexpr ll BINF = 0x3f3f3f3f3f3f3f3fLL;
const int N = 5200;
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int getPeriod(const vector<int> &s) {
  int sz = 0, now = -1;
  for (int i = 0; i < s.size(); i++) {
    if (i > 0 && s[i] != s[i - 1]) {
      if (now == -1)
        now = sz;
      else
        now = gcd(now, sz);
      sz = 1;
    } else {
      sz++;
    }
  }
  if (now == -1)
    now = sz;
  else
    now = gcd(now, sz);
  return sz;
}
int solve() {
  int n;
  cin >> n;
  vector<string> v(n);
  cin >> v;
  vector<vi> a(n, vi(n)), b(n, vi(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (isdigit(v[i][j / 4])) {
        a[i][j] = ((v[i][j / 4] - '0') >> (3 - j % 4)) & 1;
        b[j][i] = ((v[i][j / 4] - '0') >> (3 - j % 4)) & 1;
      } else {
        a[i][j] = ((v[i][j / 4] - 'A' + 10) >> (3 - j % 4)) & 1;
        b[j][i] = ((v[i][j / 4] - 'A' + 10) >> (3 - j % 4)) & 1;
      }
    }
  vector<int> periods;
  for (int i = 0; i < n; i++) {
    periods.push_back(getPeriod(a[i]));
    periods.push_back(getPeriod(b[i]));
  }
  for (int i = 1; i < periods.size(); i++)
    periods[0] = gcd(periods[0], periods[i]);
  cout << periods[0] << endl;
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  solve();
  return 0;
}
template <class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto it = v.begin(); it != v.end(); ++it) is >> *it;
  return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (auto it = v.begin(); it != v.end();) os << *it << " \n"[++it == v.end()];
  return os;
}
