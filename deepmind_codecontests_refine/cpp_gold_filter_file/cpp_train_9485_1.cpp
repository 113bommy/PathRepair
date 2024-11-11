#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5 + 7;
long long n, k;
long long a[MAXN];
void read() {
  cin >> n >> k;
  for (long long i = 0; i < n; ++i) cin >> a[i];
}
const long long INF = 1e18 + 7;
long long form(long long n) {
  if ((1 << (k - 1)) <= n)
    return n ^ ((1 << k) - 1);
  else
    return n;
}
long long ans = 0;
void solve() {
  map<long long, long long> cnt;
  cnt[0] = 1;
  long long curr = 0;
  for (long long i = 0; i < n; ++i) {
    curr ^= a[i];
    ++cnt[form(curr)];
  }
  ans = n * (n + 1) / 2;
  for (auto e : cnt) {
    long long sum = e.second;
    long long add = INF;
    for (long long t = 0; t <= sum; ++t) {
      long long a = t;
      long long b = sum - t;
      add = min(add, a * (a - 1) / 2 + b * (b - 1) / 2);
    }
    ans -= add;
  }
}
void print() { cout << ans << '\n'; }
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  read();
  solve();
  print();
  return 0;
}
