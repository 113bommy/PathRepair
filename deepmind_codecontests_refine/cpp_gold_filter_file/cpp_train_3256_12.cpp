#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
bool p[2000005];
long long int binpow(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) {
      res *= a;
      res %= 1000000007;
    }
    a *= a;
    a %= 1000000007;
    b >>= 1;
  }
  return res;
}
void solve() {
  long long int n;
  cin >> n;
  for (long long int i = 1; i <= n; i++) {
    bool flag = false;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (long long int i = 2; i < 2000005 - 5; i++) {
    if (!p[i])
      for (long long int j = i * i; j < 2000005 - 5; j += i) {
        p[j] = true;
      }
  }
  map<long long int, bool> prime;
  map<long long int, bool> primesq;
  for (long long int i = 2; i < 2000005 - 5; i++) {
    if (!p[i]) {
      prime[i] = true;
      primesq[i * i] = true;
    }
  }
  vector<long long int> ans(2000005, 0);
  ans[1] = 1;
  ans[2] = 2;
  ans[3] = 3;
  ans[4] = 2;
  for (long long int i = 5; i <= 1e6 + 5; i++) {
    ans[i] = ans[i - 1];
    if (prime[i])
      ans[i]++;
    else if (primesq[i])
      ans[i]--;
  }
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    cout << ans[n] << "\n";
  }
}
