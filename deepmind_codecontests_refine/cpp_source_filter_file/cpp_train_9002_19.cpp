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
void c_p_c() {}
void parray(int a[], int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}
bool isodd(string s) {
  int n = s.size();
  return ((s[n - 1] - '0') % 2);
}
bool sumof(string s) {
  long long sum = 0;
  for (int i = 0; i < s.size(); ++i) {
    sum += s[i] - '0';
  }
  return (sum % 2 == 0);
}
int main() {
  int i, n, k, c = 0, sum = 0;
  c_p_c();
  int a[101][101];
  memset(a, 0, sizeof(a));
  cin >> n;
  while (n--) {
    int i1, j1, i2, j2;
    cin >> i1 >> j1 >> i2 >> j2;
    for (int i = i1; i <= i2; ++i) {
      for (int j = j1; j <= j2; ++j) {
        a[i][j]++;
      }
    }
  }
  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 100; ++j) {
      if (a[i][j] > 0) sum += a[i][j];
    }
  }
  cout << sum << "\n";
  return 0;
}
