#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int max(int a, int b) { return (a > b ? a : b); }
int min(int a, int b) { return (a > b ? b : a); }
void printa(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }
  cout << "\n";
}
void printv(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << ' ';
  }
  cout << "\n";
}
void printset(set<int> s) {
  for (auto x : s) {
    cout << x << " ";
  }
  cout << "\n";
}
void printmset(multiset<int> s) {
  for (auto x : s) {
    cout << x << " ";
  }
  cout << "\n";
}
void printmgset(multiset<int, greater<int>> s) {
  for (auto x : s) {
    cout << x << " ";
  }
  cout << "\n";
}
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
const long long inf = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
int fact(int n) { return (n == 1 || n == 0) ? 1 : n * fact(n - 1); }
const int N = 1e6;
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  vector<long long> ans(n + 1);
  for (long long i = 0; i < (n); ++i) {
    cin >> v[i];
  }
  for (long long i = 0; i < (n); ++i) {
    vector<long long> cnts(4001);
    long long best = v[i];
    cnts[best]++;
    ans[best]++;
    for (long long j = i + 1; j < (n); ++j) {
      cnts[v[j]]++;
      if (cnts[v[j]] > cnts[best] ||
          (cnts[v[j]] == cnts[best] && v[j] < best)) {
        best = v[j];
      }
      ans[best]++;
    }
  }
  for (long long i = 1; i < n + 1; i++) {
    cout << ans[i] << " ";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
