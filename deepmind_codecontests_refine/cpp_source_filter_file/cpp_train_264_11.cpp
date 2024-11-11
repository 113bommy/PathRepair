#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
const double EPS = 1e-10;
double zero(double d) { return d < EPS ? 0.0 : d; }
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << '(' << p.first << ',' << p.second << ')';
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &a) {
  os << '[';
  for (int i = 0; i < (int)(a.size()); i++) os << (i ? " " : "") << a[i];
  return os << ']';
}
string toString(int i) {
  stringstream ss;
  ss << i;
  return ss.str();
}
const int MOD = 1000000007;
long long fpow(long long a, long long k, int M) {
  long long res = 1ll;
  long long x = a;
  while (k != 0) {
    if ((k & 1) == 1) res = (res * x) % M;
    x = (x * x) % M;
    k >>= 1;
  }
  return res;
}
struct prepare {
  prepare() {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(8);
    ios_base::sync_with_stdio(false);
  }
} _prepare;
pair<int, int> cnt(string s) {
  pair<int, int> c = make_pair(0, 0);
  for (int i = 0; i < (int)(s.size()); i++) {
    if (s[i] == 'o')
      c.first++;
    else if (s[i] == 'x')
      c.second++;
  }
  return c;
}
bool solve() {
  vector<string> fi(4);
  for (int i = 0; i < (int)(4); i++) {
    cin >> fi[i];
  }
  for (int r = 0; r < (int)(4); r++) {
    for (int c = 0; c < (int)(2); c++) {
      pair<int, int> cn = cnt(fi[r].substr(c, 3));
      if (cn.first == 0 && cn.second == 2) return true;
    }
  }
  for (int c = 0; c < (int)(4); c++) {
    for (int r = 0; r < (int)(2); r++) {
      stringstream ss;
      ss << fi[r][c];
      ss << fi[r + 1][c];
      ss << fi[r + 2][c];
      pair<int, int> cn = cnt(ss.str());
      if (cn.first == 0 && cn.second == 2) return true;
    }
  }
  for (int r = 0; r < (int)(2); r++) {
    for (int c = 0; c < (int)(2); c++) {
      stringstream ss;
      ss << fi[r][c];
      ss << fi[r + 1][c + 1];
      ss << fi[r + 2][c + 2];
      pair<int, int> cn = cnt(ss.str());
      if (cn.first == 0 && cn.second == 2) return true;
    }
  }
  for (int r = 2; r < (int)(4); r++) {
    for (int c = 2; c < (int)(4); c++) {
      stringstream ss;
      ss << fi[r][c];
      ss << fi[r - 1][c - 1];
      ss << fi[r - 2][c - 2];
      pair<int, int> cn = cnt(ss.str());
      if (cn.first == 0 && cn.second == 2) return true;
    }
  }
  return false;
}
int main() {
  if (solve()) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
