#include <bits/stdc++.h>
using namespace std;
long long n, a[500001], ans, cnt, mn = 999999999;
int main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (long long i = 1; i < n; i++) mn = min(abs(a[i + 1] - a[i]), mn);
  cout << mn << " ";
  for (long long i = 1; i < n; i++) {
    if (abs(a[i + 1] - a[i]) == mn) ans++;
  }
  cout << ans;
  return 0;
}
