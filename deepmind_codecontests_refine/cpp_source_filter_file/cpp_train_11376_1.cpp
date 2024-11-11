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
void solve() {
  int n;
  long long l;
  cin >> n >> l;
  n += 2;
  vector<long long> a(n);
  a[0] = 0;
  a[n - 1] = l;
  for (int i = 1; i < n - 1; i++) cin >> a[i];
  long long v1 = 1, v2 = 1;
  double time = 0;
  vector<double> t1(n);
  vector<double> t2(n);
  for (int i = 1; i < n; i++) {
    t1[i] = (double)(a[i] - a[i - 1]) / v1;
    v1++;
  }
  for (int i = n - 2; i >= 0; i--) {
    t2[i] = (double)(a[i + 1] - a[i]) / v2;
    v2++;
  }
  for (int i = 1; i < n; i++) t1[i] += t1[i - 1];
  for (int i = n - 2; i >= 0; i--) t2[i] += t2[i + 1];
  int lb = 0;
  for (int i = 0; i < n; i++) {
    if (t1[i] < t2[i]) lb = i;
    if (t1[i] == t2[i]) {
      printf("%.18f\n", t1[i]);
      return;
    }
  }
  double dis = a[lb + 1] - a[lb];
  if (t1[lb] < t2[lb + 1]) {
    dis -= (t2[lb + 1] - t1[lb]) * (lb + 1);
    time += t2[lb + 1];
  } else {
    dis -= (t1[lb] - t2[lb + 1]) * (n - lb);
    time += t1[lb];
  }
  time += dis / n;
  printf("%.18f\n", time);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
