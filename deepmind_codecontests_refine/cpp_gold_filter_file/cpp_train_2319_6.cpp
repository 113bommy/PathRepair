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
const int inf = 1e9;
int main() {
  ios_base::sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> ps(1 + n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      ps[a[i]].push_back(i);
    }
    vector<int> ret(1 + n, -1);
    int it = n;
    for (int i = 1; i <= n; ++i) {
      if (ps[i].empty()) continue;
      int d = 0;
      for (int j = 1; j < ps[i].size(); ++j) {
        d = max(d, ps[i][j] - ps[i][j - 1] - 1);
      }
      d = max(d, ps[i].front());
      d = max(d, n - 1 - ps[i].back());
      for (int j = d + 1; j <= it; ++j) {
        ret[j] = i;
      }
      it = min(it, d);
    }
    for (int i = 1; i <= n; ++i) {
      cout << ret[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
