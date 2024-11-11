#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 10;
const int M = 1e6 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int a[N], d[N * 2];
void solve() {
  int n, k;
  cin >> n >> k;
  for (long long i = 0; i < 2 * k + 10; i++) d[i] = 0;
  for (long long i = 1; i < n + 1; i++) cin >> a[i];
  int Min = 1e9 + 7, Max = 0;
  for (long long i = 1; i < n / 2 + 1; i++) {
    int sum = a[i] + a[n - i + 1];
    Min = min(a[i], a[n - i + 1]);
    Max = max(a[i], a[n - i + 1]);
    d[2] += 2;
    d[Min + 1]--;
    d[Max + k + 1]--;
    d[sum]--;
    d[sum + 1]++;
  }
  int ans = d[2];
  for (long long i = 3; i < 2 * k + 1; i++) {
    d[i] += d[i - 1];
    ans = min(ans, d[i]);
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
