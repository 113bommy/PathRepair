#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
using namespace std;
const long double EPS = 1e-7;
const long double PI = acos(-1);
const long long INF = 1e18;
void solve();
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  exit(0);
}
const long long P = 31, MOD = 1e18 + 447;
void init(vector<long long> &h, vector<long long> &q, int n) {
  h.resize(n + 1);
  q.resize(n + 1, 1);
  for (int i = 0; i < n; i++) {
    q[i + 1] = (q[i] * P) % MOD;
  }
}
long long get_hash(vector<long long> &h, vector<long long> &q, int l, int r) {
  return ((h[r + 1] - h[l] * q[r - l + 1]) % MOD + MOD) % MOD;
}
void solve() {
  string second;
  cin >> second;
  int n = (int)second.size();
  vector<long long> h1, h2, q;
  init(h1, q, n);
  init(h2, q, n);
  for (int i = 0; i < n; i++) {
    h1[i + 1] = (h1[i] * P + (second[i] - 'a')) % MOD;
  }
  reverse(second.begin(), second.end());
  for (int i = 0; i < n; i++) {
    h2[i + 1] = (h2[i] * P + (second[i] - 'a')) % MOD;
  }
  vector<long long> pal(n + 1, 0);
  for (int l = 0; l < n; l++) {
    for (int r = l; r < n; r++) {
      if (get_hash(h1, q, l, r) == get_hash(h2, q, n - r - 1, n - l - 1)) {
        pal[l]++;
      }
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    pal[i] += pal[i + 1];
  }
  long long ans = 0;
  for (int l = 0; l < n; l++) {
    for (int r = l; r < n; r++) {
      if (get_hash(h1, q, l, r) == get_hash(h2, q, n - r - 1, n - l - 1)) {
        ans += pal[r + 1];
      }
    }
  }
  cout << ans;
}
