#include <bits/stdc++.h>
using namespace std;
const int mod = 1e6 + 3;
long long a[100004];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (i > 1) {
      if (a[i] > a[i - 1])
        ans += (a[i] - a[i - 1]) * (n - a[i] + 1);
      else if (a[i] < a[i - 1])
        ans += a[i] * (a[i - 1] - a[i]);
    }
    if (i < n) {
      if (a[i] > a[i + 1])
        ans += (a[i] - a[i + 1]) * (n - a[i] + 1);
      else if (a[i] < a[i + 1])
        ans += a[i] * (a[i + 1] - a[i]);
    }
    if (i == 1) ans += a[i] * (n - a[i] + 1);
    if (i == n) ans += a[i] * (n - a[i] + 1);
  }
  printf("%lld\n", ans / 2);
}
