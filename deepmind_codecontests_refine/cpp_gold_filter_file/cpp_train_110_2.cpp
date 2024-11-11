#include <bits/stdc++.h>
#pragma GCC optimize "trapv"
using namespace std;
const int INF = 1e9;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
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
void Rotate(pair<int, int> &p, vector<pair<int, int>> &v) {
  v.push_back(p);
  v.push_back({p.second, -p.first});
  v.push_back({-p.first, -p.second});
  v.push_back({-p.second, p.first});
}
void solve() {
  int x, y;
  pair<int, int> A, B, C;
  cin >> x >> y;
  A = {x, y};
  cin >> x >> y;
  B = {x, y};
  cin >> x >> y;
  vector<pair<int, int>> rotationofA;
  Rotate(A, rotationofA);
  ;
  if (x == 0 && y == 0) {
    for (auto a : rotationofA) {
      if (a.first == B.first && a.second == B.second) {
        cout << "YES" << endl;
        return;
      }
    }
    cout << "NO" << endl;
    return;
  }
  C = {x, y};
  ;
  for (auto a : rotationofA) {
    pair<int, int> req = {B.first - a.first, B.second - a.second};
    long long x = req.first * 1LL * C.first + req.second * 1LL * C.second;
    long long y = C.first * 1LL * C.first + C.second * 1LL * C.second;
    long long z = req.first * 1LL * C.second - req.second * 1LL * C.first;
    ;
    ;
    ;
    if (x % y == 0 && z % y == 0) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
