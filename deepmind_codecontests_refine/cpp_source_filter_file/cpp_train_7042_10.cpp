#include <bits/stdc++.h>
using namespace std;
const int dr[] = {0, -1, 0, 1, -1, 1, 1, -1};
const int dc[] = {1, 0, -1, 0, 1, 1, -1, -1};
const double eps = 1e-9;
template <class T>
void print(const vector<T> &v) {
  ostringstream os;
  for (int i = 0; i < (int)v.size(); ++i) {
    if (i) os << ' ';
    os << v[i];
  }
  cout << os.str() << endl;
}
template <class T>
int sz(const T &c) {
  return (int)c.size();
}
template <class T>
void srt(T &c) {
  sort(c.begin(), c.end());
}
template <class T>
void checkmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
void checkmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T, class U>
T cast(U x) {
  ostringstream os;
  os << x;
  T res;
  istringstream is(os.str());
  is >> res;
  return res;
}
template <class T>
vector<T> split(string s, string x = " ") {
  vector<T> res;
  for (int i = 0; i < s.size(); i++) {
    string a;
    while (i < (int)s.size() && x.find(s[i]) == string::npos) a += s[i++];
    if (!a.empty()) res.push_back(cast<T>(a));
  }
  return res;
}
template <class T>
bool inside(T r, T c, T R, T C) {
  return r >= 0 && r < R && c >= 0 && c < C;
}
int solve(int ra, int ca, int rb, int cb, int m) {
  int res = 3;
  if (ra == rb || ca == 0 && cb == m - 1)
    res = 1;
  else if (ca == 0 || cb == m - 1 || rb - ra == 1 || ca <= cb + 1)
    res = 2;
  return res;
}
int main(int argc, char *argv[]) {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  --a;
  --b;
  int ra = a / m;
  int rb = b / m;
  int ca = a % m;
  int cb = b % m;
  int res = solve(ra, ca, rb, cb, m);
  if (b == n - 1) checkmin(res, solve(ra, ca, rb, m - 1, m));
  cout << res << endl;
  return 0;
}
