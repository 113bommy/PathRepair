#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1000000000;
const ll LINF = 1001002003004005006ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
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
struct IOSetup {
  IOSetup() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
  }
} iosetup;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i = 0; i < (int)v.size(); i++)
    os << v[i] << (i + 1 == (int)v.size() ? "" : " ");
  return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &x : v) is >> x;
  return is;
}
signed main() {
  int a, ta;
  cin >> a >> ta;
  int b, tb;
  cin >> b >> tb;
  string s;
  cin >> s;
  int h = 10 * (s[0] - '0') + s[1] - '0';
  int m = 10 * (s[3] - '0') + s[4] - '0';
  int x = h * 60 + m;
  int t = 60 * 5;
  int res = 0;
  while (t < 60 * 12) {
    if (t < x + ta and x < t + tb) {
      res++;
    }
    t += b;
  }
  cout << res << endl;
  return 0;
}
