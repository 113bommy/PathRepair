#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
void __print(bool x) { cerr << (x ? "true" : "false"); }
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
void __print(const char *x) { cerr << '"' << x << '"'; }
void __print(const string &x) { cerr << '"' << x << '"'; }
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
long long int MOD = 998244353;
pair<long long int, long long int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
long long int inv(long long int a, long long int b) {
  return 1 < a ? b - inv(b % a, a) * b / a : 1;
}
vector<long long int> suffix(vector<long long int> s_) {
  vector<long long int> ss(s_.size());
  long long int m = s_.size();
  ss[m - 1] = s_[m - 1];
  for (long long int i = (m - 1 - 1); i >= (0); --i) ss[i] = ss[i + 1] + s_[i];
  return ss;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long int T;
  cin >> T;
  while (T--) {
    long long int s;
    cin >> s;
    long long int n;
    cin >> n;
    long long int x = s;
    vector<long long int> s_;
    while (x) {
      s_.push_back(x % 10);
      x /= 10;
    }
    reverse((s_).begin(), (s_).end());
    vector<long long int> suf = suffix(s_);
    long long int m = s_.size();
    for (long long int i = (m - 1 - 1); i >= (0); --i)
      suf[i] = suf[i + 1] + s_[i];
    vector<long long int> ans;
    for (long long int i = (0); i < (m); ++i) {
      x = powl(10, (m - 1) - i);
      if (n <= s_[i]) {
        for (long long int j = (0); j < (n); ++j) ans.push_back(x);
        s -= x * n;
        ans.back() += s;
        break;
      } else {
        while (s - x >= n - 1) {
          ans.push_back(x);
          n--;
          s_[i]--;
          s -= x;
        }
        s_[i + 1] += 10 * s_[i];
      }
    }
    for (auto a : ans) cout << a << ' ';
    cout << '\n';
  };
}
