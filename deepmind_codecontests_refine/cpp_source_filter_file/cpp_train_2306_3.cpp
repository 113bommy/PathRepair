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
long long int arr[500005];
long long int ans = 1;
void check(long long int *arr, long long int l, long long int r) {
  if (is_sorted(arr + l, arr + r)) ans = max(ans, r - l);
  if (l == r) return;
  long long int mid = (r + l) / 2;
  if ((r - l) <= 1) return;
  check(arr, l, (r + l) / 2);
  check(arr, (l + r) / 2, r);
}
int main() {
  long long int n;
  cin >> n;
  int X = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    X ^= arr[i];
  }
  int y = *min_element(arr, arr + n);
  int ans = 2 + arr[2] ^ y;
  cout << (ans) << "\n";
}
