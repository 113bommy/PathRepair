#include <bits/stdc++.h>
using namespace std;
unsigned long long ans, x, k, all, now;
long long i, n, a[200010];
long long l[200010], r[200010];
int main() {
  cin >> n >> k >> x;
  for (i = 1; i <= n; i++) scanf("%d", &a[i]), l[i] = l[i - 1] | a[i];
  for (i = n; i >= 1; i--) r[i] = r[i + 1] | a[i];
  for (i = 1; i <= n; i++) {
    all = l[i - 1] | r[i + 1];
    now = a[i];
    for (int j = 1; j <= k; j++) now *= x;
    all |= now;
    ans = max(ans, all);
  }
  cout << ans << endl;
}
