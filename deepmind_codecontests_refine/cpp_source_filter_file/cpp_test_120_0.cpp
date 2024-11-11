#include <bits/stdc++.h>
using namespace std;
template <class T, class V>
T power(T t, V v) {
  T second = 1;
  while (v--) second *= t;
  return second;
}
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
  cerr << " ";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  int n = v.size();
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    n--;
    cerr << (n ? ", " : " ");
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
  int n = v.size();
  cerr << "{ ";
  for (auto p : v) {
    cerr << "[";
    _print(p.first);
    cerr << "]=";
    _print(p.second);
    n--;
    cerr << (n ? ", " : " ");
  }
  cerr << "}";
}
vector<long long> p(25);
void go() {
  long long l, r;
  cin >> l >> r;
  long long ans = 0;
  for (int i = 0; i < 24; i++) {
    long long temp = 0;
    long long a = 0;
    if (l >= p[i]) {
      a = l / p[i];
      if (a % 2 == 1) {
        long long z = l - a * p[i];
        a = (a / 2) * p[i] + z;
      } else {
        a = (a / 2) * p[i];
      }
    }
    long long b = 0;
    if (r >= p[i]) {
      b = r / p[i];
      if (b % 2 == 1) {
        long long z = r - b * p[i];
        b = (b / 2) * p[i] + z;
      } else {
        b = (b / 2) * p[i];
      }
    }
    ans = max(ans, b - a);
  }
  cout << (r - l + 1) - ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  p[0] = 1;
  for (int i = 1; i < 25; i++) {
    p[i] = p[i - 1] * 2;
  }
  cerr << "p"
       << ": ";
  _print(p);
  cerr << "\n";
  ;
  while (t--) {
    go();
  }
  return 0;
}
