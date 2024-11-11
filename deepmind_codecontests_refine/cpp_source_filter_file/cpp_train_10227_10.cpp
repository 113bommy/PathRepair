#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long T, n, m, k, x, y, z, l, r, q, ans, a[N], b[N], vis[N], mod = 1e9 + 7;
void solve() {
  cin >> n >> k;
  cout << (n - k >= 0 && (n - k) % 2 == 0 ? "YES" : "NO") << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) solve();
}
