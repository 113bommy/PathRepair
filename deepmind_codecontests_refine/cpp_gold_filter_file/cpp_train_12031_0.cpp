#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
using ii = pair<int, int>;
using ll = long long;
using db = long double;
const int N = 100 + 5, M = 1e7 + 5, K = 20, MOD = 1e9 + 7, MOD2 = 998244353;
const ll MX = 1e15;
const int blkSz = 320;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  priority_queue<int> pq;
  ll ans = 0;
  for (int i = 0, a, b, c, d; i < n; i++) {
    cin >> a >> b >> c >> d;
    if (a + b < c + d)
      ans += max(0, a - d) - max(0, b - c);
    else {
      ans += a + c;
      pq.push(a + b);
      pq.push(c + d);
    }
  }
  while (!pq.empty()) {
    pq.pop();
    ans -= pq.top();
    pq.pop();
  }
  cout << ans << '\n';
  return 0;
}
