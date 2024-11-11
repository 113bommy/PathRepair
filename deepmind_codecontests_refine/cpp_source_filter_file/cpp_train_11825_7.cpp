#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e2 + 5;
const int mod = 1e9 + 7;
const int INF = 1e8 + 5;
const long long inf = 1e15 + 5;
const double eps = 1e-8;
const long long hp = 2333;
const long long base = 1e9 + 13;
long long n, l, r;
long long cal(long long x) {
  if (x <= 1) return 1;
  return cal(x >> 1) * 2ll + 1;
}
long long dfs(long long x, long long cl, long long cr) {
  if (x == 0 || cr < l || cl > r) return 0;
  if (x == 1) return 1;
  long long mid = cal(x >> 1);
  return dfs(x >> 1, cl, mid) + dfs(x & 1, mid + 1, mid + 1) +
         dfs(x >> 1, mid + 2, cr);
}
void solve() {
  while (cin >> n >> l >> r) {
    long long tot = cal(n);
    long long ans = dfs(n, 1, tot);
    cout << ans << endl;
  }
}
int main() {
  int t = 1, cas = 1;
  while (t--) {
    solve();
  }
  return 0;
}
