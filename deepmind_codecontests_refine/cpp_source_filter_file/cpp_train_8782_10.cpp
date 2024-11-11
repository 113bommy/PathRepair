#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int main() {
  int m, q, minq = 1000000, n, a[maxn];
  cin >> m;
  for (int i = 0; i < m; i++) {
    scanf("%d", &q);
    minq = min(minq, q);
  }
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  sort(a, a + n);
  int ans = 0;
  for (int i = n - m; i >= 0; i -= (m + 2)) {
    if (i - 1 >= 0) ans += a[i - 1];
    if (i - 2 >= 0) ans += a[i - 2];
  }
  ans = sum - ans;
  cout << ans << endl;
  cin >> n;
  return 0;
}
