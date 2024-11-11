#include <bits/stdc++.h>
using namespace std;
long long n;
long long ans;
long long a[65536 * 6];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), ans = ans + a[i] * a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) ans += a[i] * a[n + 1 - i];
  cout << ans;
  return 0;
}
