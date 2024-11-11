#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const long long N = 2e5 + 10;
inline long long add(long long x, long long y) {
  x += y;
  if (x >= MOD) return x - MOD;
  return x;
}
inline long long multiply(long long a, long long b) {
  a %= MOD;
  b %= MOD;
  return (a * b) % MOD;
}
void test() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n), b(k);
  vector<long long> maps(n + 10, 0), mark(n + 10, 0);
  long long c = 0;
  for (auto &e : a) {
    cin >> e;
    maps[e] = c;
    c++;
  }
  for (auto &e : b) {
    cin >> e;
    mark[e] = 1;
  }
  long long ans = 1;
  for (auto &e : b) {
    long long id = maps[e];
    c = 0;
    if (id - 1 >= 0 and !mark[a[id - 1]]) {
      c++;
    }
    if (id + 1 < n and !mark[a[id + 1]]) {
      c++;
    }
    ans = multiply(ans, c);
    mark[e] = false;
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    test();
  }
  return 0;
}
