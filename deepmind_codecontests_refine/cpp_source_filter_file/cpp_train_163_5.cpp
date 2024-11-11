#include <bits/stdc++.h>
using namespace std;
const int N = 1005, M = 2005;
int a[N], b[M];
int main() {
  ios::sync_with_stdio(false);
  int n, k, p;
  cin >> n >> k >> p;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= k; i++) {
    cin >> b[i];
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  int ans = 1e9;
  for (int i = 1; i <= k - n; i++) {
    int t = 0;
    for (int j = 1; j <= n; j++)
      t = max(t, abs(a[j] - b[i + j]) + abs(p - b[i + j]));
    ans = min(ans, t);
  }
  cout << ans << endl;
  return 0;
}
