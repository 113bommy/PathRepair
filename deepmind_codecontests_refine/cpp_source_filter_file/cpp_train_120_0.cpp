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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n = 0, m = 0, k = 0, i = 0, j = 0, p = 0, q = 0, x = 0, y = 0,
                  z = 0, ans = 0, cnt = 0, l = 0, r = 0, mid = 0, lo = 0,
                  hi = 0;
    string s;
    bool flag = false;
    cin >> x >> y >> z;
    p = min(x, y / 2);
    ans = max(ans, 3 * p + 3 * (min(z, (y - (2 * p)))));
    p = min(y, z / 2);
    ans = max(ans, 3 * p + 3 * (min(x, (y - p) / 2)));
    cout << ans << endl;
    ;
  }
  return 0;
}
