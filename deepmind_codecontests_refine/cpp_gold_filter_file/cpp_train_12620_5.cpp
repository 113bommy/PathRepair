#include <bits/stdc++.h>
using namespace std;
void _print(long long int t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(long long unsigned t) { cerr << t; }
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
template <class a>
void printarr(a arr[], int n) {
  for (int i = 0; i < n; i++) cout << arr[i] << ' ';
  cout << '\n';
}
template <class c>
void printarr(vector<c> v) {
  for (auto i : v) {
    cout << i << ' ';
  }
  cout << '\n';
}
template <class c, class d>
void printarr(vector<c> v, d i, d j) {
  for (int k = i; k < j; k++) {
    cout << v[k] << ' ';
  }
  cout << '\n';
}
template <class c>
void printarr(set<c> s) {
  for (auto i : s) {
    cout << i << ' ';
  }
  cout << '\n';
}
template <class t>
t extended_gcd(t a, t b, t &x, t &y) {
  t x1, y1;
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  t g = extended_gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return g;
}
template <class a>
a powmod(a t1, a t2, a mod) {
  a res = 1;
  t1 = t1 % mod;
  if (t1 == 0) return 0;
  while (t2) {
    if (t2 & 1) res = (res * t1) % mod;
    t1 = (t1 * t1) % mod;
    t2 = t2 >> 1;
  }
  return res;
}
template <class a>
a powmod(a t1, a t2) {
  a res = 1;
  if (t1 == 0) return 0;
  while (t2) {
    if (t2 & 1) res = (res * t1);
    t1 = (t1 * t1);
    t2 = t2 >> 1;
  }
  return res;
}
const long long int MOD = 1e9 + 7;
const int N = 1e5 + 5;
vector<long long int> ans(N), cost(N, INT_MAX);
vector<long long int> a(N);
long long int ans1 = 0;
void run() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i], cost[i] = a[i];
  for (int i = 0; i < n; i++) {
    long long int cnt = 0;
    cnt += a[i];
    cost[i] = a[i];
    for (int j = i - 1; j >= 0; j--) {
      cost[j] = min(cost[j + 1], a[j]);
      cnt += cost[j];
    }
    for (int j = i + 1; j < n; j++) {
      cost[j] = min(cost[j - 1], a[j]);
      cnt += cost[j];
    }
    if (cnt > ans1) {
      ans1 = cnt;
      for (int i = 0; i < n; i++) {
        ans[i] = cost[i];
      }
    }
  }
  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  cout << setprecision(10) << fixed;
  { run(); }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << '\n';
  return 0;
  ;
}
