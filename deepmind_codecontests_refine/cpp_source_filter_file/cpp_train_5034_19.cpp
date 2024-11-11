#include <bits/stdc++.h>
using namespace std;
int a[100000];
int main() {
  unsigned long long n, sum = 0, cnt = 0, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
  if (sum % 3) return cout << 0, 0;
  sum /= 3;
  int k = 0;
  for (int i = 0; i < n - 1; i++) {
    k += a[i];
    if (k == 2 * sum) ans += cnt;
    if (k == sum) cnt++;
  }
  cout << ans;
  return 0;
}
