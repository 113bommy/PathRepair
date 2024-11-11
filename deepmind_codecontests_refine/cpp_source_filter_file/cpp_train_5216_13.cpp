#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
using vll = vector<ll>;
ll const max_size = 1024;
ll const mod = 1e9 + 7;
ll const maxn = 1e5 + 1;
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
ll testcases;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  testcases = 1;
  while (testcases--) {
    ll n;
    cin >> n;
    map<ll, ll> el;
    ll a[n];
    for (ll i1 = 0; i1 < n; i1++) cin >> a[i1];
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
      ll j = i;
      while (j + 1 < n && a[j + 1] <= a[i] * 2) j++;
      ans = max(ans, j - i + 1);
      i = j;
    }
    cout << ans << "\n";
  }
}
