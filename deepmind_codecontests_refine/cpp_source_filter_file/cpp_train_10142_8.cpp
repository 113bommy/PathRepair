#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
template <class T>
string i2s(T x) {
  ostringstream o;
  o << x;
  return o.str();
}
vector<string> splt(string s, char c = ' ') {
  vector<string> rv;
  int p = 0, np;
  while (np = s.find(c, p), np >= 0) {
    if (np != p) rv.push_back(s.substr(p, np - p));
    p = np + 1;
  }
  if (p < int((s).size())) rv.push_back(s.substr(p));
  return rv;
}
void print(vector<int> v, int sz = -1) {
  if (sz == -1) sz = int((v).size());
  cerr << "[";
  if (sz) cerr << v[0];
  for (int i = (1), _b = (sz); i < _b; ++i) cerr << ", " << v[i];
  cerr << "]" << endl;
}
void print(vector<double> v, int sz = -1) {
  if (sz == -1) sz = int((v).size());
  cerr << "[";
  if (sz) cerr << v[0];
  for (int i = (1), _b = (sz); i < _b; ++i) cerr << ", " << v[i];
  cerr << "]" << endl;
}
void print(vector<string> v, int sz = -1) {
  if (sz == -1) sz = int((v).size());
  cerr << "[";
  if (sz) cerr << v[0];
  for (int i = (1), _b = (sz); i < _b; ++i) cerr << ", " << v[i];
  cerr << "]" << endl;
}
void print(pair<int, int> v) {
  cerr << "{ " << v.first << ", " << v.second << " }";
}
void print(vector<pair<int, int> > v, int sz = -1) {
  if (sz == -1) sz = int((v).size());
  cerr << "[ ";
  if (sz) print(v[0]);
  for (int i = (1), _b = (sz); i < _b; ++i) {
    cerr << ", ";
    print(v[i]);
  }
  cerr << "]" << endl;
}
void print(vector<vector<int> > v, int sz1 = -1, int sz2 = -1) {
  if (sz1 == -1) sz1 = int((v).size());
  if (sz2 == -1) sz2 = int((v[0]).size());
  cerr << "[ ---" << endl;
  if (sz1) cerr << " ", print(v[0], sz2);
  for (int i = (1), _b = (sz1); i < _b; ++i) cerr << " ", print(v[i], sz2);
  cerr << "--- ]\n";
}
const double EPS = 1e-9;
const int MOD = int(1e9) + 7;
const double PI = acos(-1.0);
void pre() {}
int main() {
  pre();
  int a, b;
  cin >> a >> b;
  if (a == b) {
    cout << "0 6 0" << endl;
    return 0;
  }
  int ans1, d, ans2;
  int a1 = a, b1 = b;
  if (a > b) swap(a, b);
  ans1 = a + (b - a - 1) / 2;
  if ((b - a) % 2 == 0) d = 1;
  ans2 = 6 - ans1 - d;
  if (a1 == a)
    cout << ans1 << " " << d << " " << ans2 << endl;
  else
    cout << ans2 << " " << d << " " << ans1 << endl;
  return 0;
}
