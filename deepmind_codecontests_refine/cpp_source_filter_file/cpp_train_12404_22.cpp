#include <bits/stdc++.h>
using namespace std;
int n, m, r;
int a[1010], b[1010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> r;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + m);
  int x = r / a[0], ans = r;
  ans = max(ans, r - x * a[0] + x * b[m - 1]);
  cout << ans;
  return 0;
}
