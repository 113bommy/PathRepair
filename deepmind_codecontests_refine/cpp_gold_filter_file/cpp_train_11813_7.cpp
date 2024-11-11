#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cout << x; }
void __print(long x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned x) { cout << x; }
void __print(unsigned long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(float x) { cout << x; }
void __print(double x) { cout << x; }
void __print(long double x) { cerr << x; }
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
void c_p_c();
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int testcase = 1;
  while (testcase--) c_p_c();
  return 0;
}
void c_p_c() {
  long long int n, m;
  cin >> n >> m;
  vector<vector<long long int>> a(n, vector<long long int>(m, 0));
  ;
  vector<vector<long long int>> b(n, vector<long long int>(m, 1));
  ;
  for (long long int i = 0; i < n; ++i) {
    for (long long int j = 0; j < m; ++j) {
      cin >> a[i][j];
      if (!a[i][j]) {
        for (long long int k = 0; k < n; ++k) {
          b[k][j] = 0;
        }
        for (long long int k = 0; k < m; ++k) {
          b[i][k] = 0;
        }
      }
    }
  }
  for (long long int i = 0; i < n; ++i) {
    for (long long int j = 0; j < m; ++j) {
      if (a[i][j]) {
        long long int ans = 0;
        for (long long int k = 0; k < n; ++k) {
          ans += b[k][j];
        }
        for (long long int k = 0; k < m; ++k) {
          ans += b[i][k];
        }
        if ((bool)(ans) == 0) {
          cout << "NO";
          return;
        }
      }
    }
  }
  cout << "YES\n";
  for (long long int i = 0; i < n; ++i) {
    for (long long int j = 0; j < m; ++j) {
      cout << (bool)(b[i][j]) << ' ';
    }
    cout << endl;
  }
}
