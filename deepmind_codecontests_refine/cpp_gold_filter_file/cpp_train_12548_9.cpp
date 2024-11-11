#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void __print(int x) { cout << x; }
void __print(long x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned x) { cout << x; }
void __print(unsigned long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(float x) { cout << x; }
void __print(double x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << '\'' << x << '\''; }
void __print(const char *x) { cout << '\"' << x << '\"'; }
void __print(const string &x) { cout << '\"' << x << '\"'; }
void __print(bool x) { cout << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cout << '{';
  __print(x.first);
  cout << ',';
  __print(x.second);
  cout << '}';
}
template <typename T>
void __print(const T &x) {
  int first = 0;
  cout << '{';
  for (auto &i : x) cout << (first++ ? "," : ""), __print(i);
  cout << "}";
}
void _print() { cout << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cout << ", ";
  _print(v...);
}
template <class T>
void remdup(vector<T> &v) {
  sort((v).begin(), (v).end());
  v.erase(unique((v).begin(), (v).end()), end(v));
}
template <typename T>
struct cmp {
  bool operator()(const T &p1, const T &p2) { return true; }
};
const long long N = 2e5 + 100;
const long long mod = 1e9 + 7;
const long long X = 2e5 + 100;
int main() {
  long long n;
  cin >> n;
  if (n == 2) {
    cout << "-1"
         << "\n";
    return 0;
  }
  vector<long long> a(n, 2);
  a[n - 1] = 3;
  a[0] *= 607;
  a[n - 1] *= 607;
  for (long long i = (1); i < (n - 1); ++i) a[i] *= (3 * (i + 1));
  for (long long i = (0); i < (n); ++i) cout << a[i] << endl;
  return 0;
}
