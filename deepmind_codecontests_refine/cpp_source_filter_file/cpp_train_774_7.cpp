#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
const int N = 1e3 + 10;
const int mod = 1e9 + 7;
const long long maxll = 9223372036854775807;
const long long minll = -9223372036854775808;
long long b[maxn], g[maxn];
void solve() {
  long long n, m;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> b[i];
  cin >> m;
  for (int i = 0; i < m; i++) cin >> g[i];
  long long ans = 0;
  sort(b, b + n);
  sort(g, g + n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (abs(b[i] - g[j]) <= 1) {
        ans++;
        g[j] = minll;
        break;
      }
    }
  }
  cout << ans;
  return;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}
