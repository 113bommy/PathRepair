#include <bits/stdc++.h>
using namespace std;
bool endline = false;
template <class T>
istream& operator>>(istream& inp, vector<T>& v) {
  for (auto& it : v) inp >> it;
  return inp;
}
template <class T>
ostream& operator<<(ostream& out, vector<T>& v) {
  for (auto& it : v) out << it << (endline ? "\n" : " ");
  return out;
}
template <class T, class U>
istream& operator>>(istream& inp, pair<T, U>& v) {
  inp >> v.first >> v.second;
  return inp;
}
template <class T, class U>
ostream& operator<<(ostream& out, pair<T, U>& v) {
  out << v.first << ' ' << v.second;
  return out;
}
const int mod1 = 998244353, mod = 1e9 + 7;
const int MAXN = 2e5 + 6, MAXM = 5e5 + 5;
const int inf = 2e9;
const long long linf = 1e18;
long long n;
vector<long long> a, b, tmp;
bool chk(vector<long long> x, vector<long long> y) {
  reverse(x.begin(), x.end());
  reverse(y.begin(), y.end());
  for (long long i = 0; i < y.size(); i++) {
    if (abs(x[i] + y[i]) > 1) return false;
  }
  return true;
}
void g(vector<long long>& x, vector<long long> y) {
  x.push_back(0);
  if (chk(x, y)) {
    for (long long i = y.size() - 1; i >= 0; i--) {
      x[i + x.size() - y.size()] += y[i];
    }
  } else {
    for (long long i = y.size() - 1; i >= 0; i--) {
      x[i + x.size() - y.size()] -= y[i];
    }
  }
}
void build(long long n) {
  if (n == 0) {
    a.assign(1, 1);
    b.assign(1, 0);
    return;
  }
  build(n - 1);
  tmp = a;
  g(a, b);
  b = tmp;
}
void Solve() {
  cin >> n;
  build(n);
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  cout << a.size() - 1 << endl << a << endl;
  cout << b.size() - 1 << endl << b << endl;
}
signed main() {
  if (fopen(""
            ".inp",
            "r")) {
    freopen(
        ""
        ".inp",
        "r", stdin);
    freopen(
        ""
        ".out",
        "w", stdout);
  };
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long TC = 1;
  while (TC--) Solve();
  return 0;
}
