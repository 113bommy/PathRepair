#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
int ctoi(char c) { return c - '0'; }
int slen(string s) { return s.length(); }
int vsize(vi a) { return (int)a.size(); }
int in() {
  int x;
  cin >> x;
  return x;
}
void solve() {
  ll n, T;
  cin >> n;
  ll a[n];
  bool f = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll mini1 = min(a[0], a[n - 1]), mini2 = 1e9;
  for (ll i = 0; i < n - 1; i += 2) {
    mini1 = min(mini1, max(a[i + 1], a[i]));
  }
  cout << mini1;
}
int main() {
  ll t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
