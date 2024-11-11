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
  int first = 0;
  cerr << '{';
  for (auto &i : x) cerr << (first++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> a(m);
  long long sum = 0;
  vector<int> c(64, 0);
  for (auto &i : a) {
    cin >> i;
    sum += i;
    for (int bit = 0; bit <= 32; bit++) {
      if (i >> bit & 1) {
        c[bit]++;
        break;
      }
    }
  }
  if (sum < n) {
    cout << -1 << endl;
    return;
  }
  int cnt = 0;
  for (int bit = 0; bit < 62; bit++) {
    if (n >> bit & 1) {
      if (c[bit] == 0) {
        int closest = bit + 1;
        while (c[closest] == 0) {
          closest++;
        }
        c[closest]--;
        closest--;
        while (closest >= bit) {
          c[closest]++;
          cnt++;
          closest--;
        }
        c[bit]++;
      }
      c[bit]--;
    }
    c[bit + 1] += c[bit] / 2;
  }
  cout << cnt << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
