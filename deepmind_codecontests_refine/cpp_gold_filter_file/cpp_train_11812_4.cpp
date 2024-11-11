#include <bits/stdc++.h>
using namespace std;
long long n, a[400000];
int main() {
  long long ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n == 1) {
    cout << a[0];
    return 0;
  }
  sort(a, a + n);
  for (int i = 0; i < n - 1; i++) ans += a[i] * (i + 2);
  ans += a[n - 1] * n;
  cout << ans;
}
