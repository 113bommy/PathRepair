#include <bits/stdc++.h>
using namespace std;
void _print(long long int t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long int t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
int pow(int x, unsigned int y, int p) {
  int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int _pow(int a, int b) {
  if (!b) return 1;
  int temp = _pow(a, b / 2);
  temp = (temp * temp);
  if (b % 2) return (a * temp);
  return temp;
}
int invmod(int a, int m) { return pow(a, m - 2, m); }
int cl(int a, int x) {
  if (a % x == 0)
    return a / x;
  else
    return a / x + 1;
}
void yes() {
  cout << "YES"
       << "\n";
}
void no() {
  cout << "NO"
       << "\n";
}
void solve() {
  long long int n, a, b, c, d;
  long long int cnt = 0;
  cin >> n >> a >> b >> c >> d;
  for (int x = 1; x <= n; x++) {
    int y = x + b - c;
    int z = x + a - d;
    int w = y + a - d;
    if (y >= 1 && y <= n && w >= 1 && w <= n && z >= 1 && z <= n) {
      cnt++;
    }
  }
  cout << cnt * n;
}
int main() {
  ios_base::sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
