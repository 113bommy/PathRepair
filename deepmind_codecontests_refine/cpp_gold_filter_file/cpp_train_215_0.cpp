#include <bits/stdc++.h>
using namespace std;
long long n, s, ans, i, j, k, a[300000];
long long ab(long long dd) {
  if (dd < 0) return -dd;
  return dd;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> s;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  ans += ab(s - a[n / 2 + 1]);
  for (i = 1; i < n / 2 + 1; i++) {
    if (a[i] > s) ans += ab(s - a[i]);
  }
  for (i = n / 2 + 2; i <= n; i++) {
    if (a[i] < s) ans += ab(s - a[i]);
  }
  cout << ans;
  return 0;
}
