#include <bits/stdc++.h>
using namespace std;
const int base = 100003;
const long long MM = 1ll * 1000000007 * 1000000007;
const int maxc = 2e9;
int n;
void Solve() {
  int n, m, d;
  cin >> n >> m >> d;
  int a[n * m + 1];
  for (int i = 0; i < n * m; i++) cin >> a[i];
  n = n * m;
  sort(a, a + n);
  int ok = 0;
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      if ((a[j] - a[i]) % d != 0) {
        ok = 1;
        cout << -1;
        return;
      }
  if (ok == 1) return;
  int t = a[n / 2], ans = 0;
  for (int i = 0; i < n; i++) ans += abs(t - a[i]) / d;
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  Solve();
}
