#include <bits/stdc++.h>
using namespace std;
const long long int MAX = 2e5 + 2;
const long long int mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
T rand(T a, T b) {
  return uniform_int_distribution<T>(a, b)(rng);
}
template <class T>
T rand() {
  return uniform_int_distribution<T>()(rng);
}
void _print(long long int t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
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
double ncr(long long int n, long long int r) {
  if (r > n || r < 0) return 0;
  if (r == 3) return (n * (n - 1) * (n - 2)) / 6;
  if (r == 2) return (n * (n - 1)) / 2;
  if (r == 1) return n;
  return 1;
}
double cal(long long int l, long long int r, long long int i, long long int n) {
  double ans = ncr(i, l) * (ncr(n - i, r)) / ncr(n, l + r);
  return ans;
}
double frac(double l, double r) { return l / r; }
void solve() {
  long long int n;
  cin >> n;
  double k;
  cin >> k;
  double e = 1e-5;
  for (long long int i = 0; i < n + 1; i++) {
    double ans = 0, tmp, p;
    p = cal(3, 0, i, n);
    tmp = 1;
    ans += (p * tmp);
    p = cal(2, 1, i, n);
    tmp = 1;
    ans += (p * tmp);
    p = cal(1, 2, i, n);
    tmp = 0.5;
    ans += (p * tmp);
    p = cal(0, 3, i, n);
    tmp = 0;
    ans += (p * tmp);
    ;
    ;
    if (ans >= k) {
      cout << i << "\n";
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  for (long long int i = 0; i < t; i++) {
    solve();
  }
}
