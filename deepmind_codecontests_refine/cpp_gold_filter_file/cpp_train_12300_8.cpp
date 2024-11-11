#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int mod = 10007;
long long a[maxn], b[maxn];
int main() {
  long long n, m, ta, tb, k;
  cin >> n >> m >> ta >> tb >> k;
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]), a[i] = a[i] + ta;
  for (int i = 0; i < m; i++) scanf("%lld", &b[i]);
  int p = 0;
  int flag1 = 0;
  long long ans = 0;
  if (k >= n || k >= m) flag1 = 1;
  for (int i = 0; i < n && k >= 0; i++, k--) {
    int idx = m - (lower_bound(b, b + m, a[i]) - b);
    if (idx <= k) {
      flag1 = 1;
      break;
    } else {
      int s = lower_bound(b, b + m, a[i]) - b;
      ans = max(b[s + k] + tb, ans);
    }
  }
  if (flag1)
    cout << -1 << endl;
  else
    cout << ans << endl;
}
