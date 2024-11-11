#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1000000007;
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
string gh = "here";
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    long long n, m, k;
    cin >> n >> m >> k;
    long long ans = 0;
    if (n % 2 == m % 2) {
      ans += min(n, m);
      ans += max(n, m) - min(n, m);
      if (k < ans) {
        cout << -1;
        continue;
      } else {
        k -= ans;
      }
      if (k % 2) {
        ans -= 1;
        ans += k - 1;
      } else {
        ans += k;
      }
      cout << ans << '\n';
    } else {
      long long nn = n - 1, mm = m, a2 = 0;
      ans += min(nn, mm);
      ans += max(nn, mm) - min(nn, mm);
      nn = n;
      mm = m - 1;
      a2 += min(nn, mm);
      a2 += max(nn, mm) - min(nn, mm);
      ans = min(ans, a2);
      ans++;
      if (k < ans) {
        cout << -1 << '\n';
        continue;
      } else {
        k -= ans;
      }
      ans--;
      ans += k;
      cout << ans << '\n';
    }
  }
  return 0;
}
