#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[302000];
long long ans;
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);
  ans = -a[n - 1];
  for (int i = n - 1; i >= 0; --i) {
    a[i] += a[i + 1];
    ans += a[i];
  }
  cout << ans + a[0];
  return 0;
}
