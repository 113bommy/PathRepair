#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& _p) {
  return os << "(" << _p.first << "," << _p.second << ")";
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& _V) {
  bool f = true;
  os << "[";
  for (auto v : _V) {
    os << (f ? "" : ",") << v;
    f = false;
  }
  return os << "]";
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& _S) {
  bool f = true;
  os << "(";
  for (auto s : _S) {
    os << (f ? "" : ",") << s;
    f = false;
  }
  return os << ")";
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const map<T, U>& _M) {
  return os << set<pair<T, U>>(_M.begin(), _M.end());
}
const signed long long INF = 1000000100;
const long double EPS = 1e-9;
int ask(int x, int y, int xx, int yy, int rev = 0) {
  if (!rev)
    cout << "? " << x << " " << y << " " << xx << " " << yy << endl;
  else
    cout << "? " << y << " " << x << " " << yy << " " << xx << endl;
  int a;
  cin >> a;
  return a;
}
pair<int, int> foo(int x, int y, int xx, int yy, int rev = 0) {
  int st = x - 1, en = xx;
  pair<int, int> ret = make_pair(0, 0);
  int heh;
  while (st + 1 < en) {
    int shot = (st + en) / 2;
    heh = ask(x, y, shot, yy, rev);
    if (heh < 1)
      st = shot;
    else
      en = shot;
  }
  ret.second = en;
  st = x;
  en = xx + 1;
  while (st + 1 < en) {
    int shot = (st + en) / 2;
    heh = ask(shot, y, xx, yy, rev);
    if (heh == 1)
      st = shot;
    else
      en = shot;
  }
  ret.first = st;
  return ret;
}
void printheh(pair<pair<int, int>, pair<int, int>> a) {
  cout << a.first.first << " " << a.second.first << " " << a.first.second << " "
       << a.second.second << " ";
}
pair<pair<int, int>, pair<int, int>> solve_one(int x, int y, int xx, int yy) {
  pair<int, int> xs = foo(x, y, xx, yy);
  pair<int, int> ys = foo(y, x, yy, xx, 1);
  pair<pair<int, int>, pair<int, int>> ret = make_pair(xs, ys);
  return ret;
}
int check(pair<pair<int, int>, pair<int, int>> a) {
  if (a.first.first > a.first.second || a.second.first > a.second.second)
    return 0;
  cout << "? " << a.first.first << " " << a.second.first << " "
       << a.first.second << " " << a.second.second << endl;
  int r;
  cin >> r;
  return (r == 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  int st = 0, en = n;
  int heh;
  while (st + 1 < en) {
    int shot = (st + en) / 2;
    heh = ask(1, 1, n, shot);
    if (heh < 1)
      st = shot;
    else
      en = shot;
  }
  if (st > 0 && ask(1, 1, n, en) == 1 && ask(1, en + 1, n, n) == 1) {
    auto aa = solve_one(1, 1, n, en);
    auto bb = solve_one(1, en + 1, n, n);
    cout << "! ";
    printheh(aa);
    printheh(bb);
    cout << endl;
    return 0;
  }
  st = 0;
  en = n;
  while (st + 1 < en) {
    int shot = (st + en) / 2;
    heh = ask(1, 1, shot, n);
    if (heh < 1)
      st = shot;
    else
      en = shot;
  }
  if (42) {
    auto aa = solve_one(1, 1, en, n);
    auto bb = solve_one(en + 1, 1, n, n);
    cout << "! ";
    printheh(aa);
    printheh(bb);
    cout << endl;
    return 0;
  }
}
