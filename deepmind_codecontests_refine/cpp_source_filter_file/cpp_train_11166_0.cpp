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
void _print(T &&t, V &&...v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const int MAXN = 1e6 + 100;
int t, n;
string A, B;
int cnt[26];
int solve() {
  for (int i = 0; i < (int)(n); i++) {
    if (A[i] > B[i]) return 1;
  }
  int ans = 0;
  for (int from = 0; from < (int)(20); from++) {
    int to = 1e9;
    for (int i = 0; i < (int)(n); i++) {
      if (A[i] - 'a' == from) {
        if (B[i] > A[i]) {
          to = min(to, B[i] - 'a');
        }
      }
    }
    if (to < 1e9) {
      ans++;
      for (int i = 0; i < (int)(n); i++) {
        if (A[i] - 'a' == from) {
          A[i] = 'a' + to;
        }
      }
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> A;
    cin >> B;
    cout << solve() << endl;
  }
  return 0;
}
