#include <bits/stdc++.h>
using namespace std;
const auto start_time = std::chrono::high_resolution_clock::now();
void timecalculater() {}
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
  int f = 0;
  cout << '{';
  for (auto &i : x) cout << (f++ ? "," : ""), __print(i);
  cout << "}";
}
void _print() { cout << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cout << ", ";
  _print(v...);
}
long long p = 1e9 + 7;
const int N = 2e5 + 5;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  ;
  int T = 1;
  while (T--) {
    long long n;
    cin >> n;
    long long ans;
    long long k = 1;
    long long j = 2;
    while (k + j < n) {
      k += j;
      j++;
    }
    n = n - k;
    ans = n;
    if (n == 0) ans = 1;
    cout << ans;
  }
  timecalculater();
  return 0;
}
