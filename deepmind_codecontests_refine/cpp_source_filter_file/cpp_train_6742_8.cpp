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
void eff() {
  long long n, k, l;
  scanf("%lld %lld %lld", &n, &k, &l);
  vector<long long> a(n * k);
  for (long long i = 0; i < n * k; i++) {
    scanf("%lld", &a[i]);
  }
  sort(a.begin(), a.end());
  long long u = 0;
  long long ans = 0;
  long long index = upper_bound(a.begin(), a.end(), a[0] + l) - a.begin();
  if (index < n) {
    puts("0");
    return;
  }
  for (long long i = 0; i < n; i++) {
    ans += a[u++];
    for (long long j = 0; j < k; j++) {
      if (index - u > n - i - 1) {
        u++;
      } else {
        break;
      }
    }
  }
  cout << ans << endl;
}
int main() {
  eff();
  return 0;
}
