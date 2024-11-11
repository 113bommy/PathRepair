#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long power(long long base, long long exp);
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> arr(n, 0);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long adj[500][500] = {};
  for (long long i = 0; i < m; i++) {
    long long x, y;
    cin >> x >> y;
    x--;
    y--;
    cin >> adj[x][y];
    adj[y][x] = adj[x][y];
  }
  double ans = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      if (adj[i][j]) {
        double p = (1.0 * arr[i] + arr[j]) / (adj[i][j]);
        if (p > ans) {
          ans = p;
        }
      }
    }
  }
  cout << fixed << setprecision(10);
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
long long power(long long base, long long exp) {
  base %= 1000000007;
  long long result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long)result * base) % 1000000007;
    base = ((long long)base * base) % 1000000007;
    exp >>= 1;
  }
  return result;
}
