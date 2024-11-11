#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
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
ll add(ll x, ll y) {
  x += y;
  while (x >= mod) {
    x -= mod;
  }
  while (x < 0) {
    x += mod;
  }
  return x;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<ll>> c(n + 1);
    vector<ll> p(n + 1);
    for (ll i = 0; i < n; i++) {
      p[i + 1] = p[i] + (s[i] - '0');
    }
    for (ll i = 0; i < n; i++) {
      c[i].resize(i + 1);
      c[i][0] = c[i][i] = 1;
      for (ll j = 1; j < i; j++) {
        c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
      }
    }
    int ans = 1;
    for (ll i = 0; i < n; i++) {
      for (ll j = i + 1; j < n; j++) {
        ll cnt = j + 1 - i;
        ll cnt1 = p[j + 1] - p[i];
        if (cnt1 > k or p[n] < k) {
          continue;
        }
        cnt -= 2;
        if (s[i] == '0') {
          cnt1--;
        }
        if (s[j] == '0') {
          cnt1--;
        }
        if (cnt1 <= cnt and cnt1 >= 0 and cnt >= 0) {
          ans = add(ans, c[cnt][cnt1]);
        }
      }
    }
    cout << ans << "\n";
  }
}
