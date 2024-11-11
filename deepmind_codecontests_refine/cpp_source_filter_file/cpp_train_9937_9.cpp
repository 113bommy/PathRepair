#include <bits/stdc++.h>
using namespace std;
long long a[100005], b[100005];
int main() {
  int i, n, m;
  long long ans, sum, sa = 0, sb = 0;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]), sa += a[i];
  }
  for (i = 1; i <= m; i++) {
    scanf("%I64d", &b[i]), sb += b[i];
  }
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + n);
  sum = sa;
  for (i = 1; i < m; i++) sum += min(b[i], sa);
  ans = sum;
  sum = sb;
  for (i = 1; i < n; i++) sum += min(a[i], sb);
  ans = min(ans, sum);
  cout << ans << endl;
  return 0;
}
