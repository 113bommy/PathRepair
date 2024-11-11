#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007, MOD2 = 1000000009;
const int INF = 0x3f3f3f3f;
const long long BINF = 0x3f3f3f3f3f3f3f3fLL;
int n, a[105];
int prf[105], suf[105];
int solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  prf[0] = a[0] == 0;
  for (int i = 1; i < n; i++) prf[i] = prf[i - 1] + (a[i] == 0);
  suf[n - 1] = a[n - 1] == 1;
  for (int i = n - 2; ~i; i--) suf[i] = suf[i + 1] + (a[i] == 1);
  int ans = suf[0];
  for (int i = 0; i + 1 < n; i++) {
    ans = max(ans, prf[i] + suf[i + 1]);
  }
  cout << ans << endl;
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  solve();
  return 0;
}
