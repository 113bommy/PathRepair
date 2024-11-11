#include <bits/stdc++.h>
using namespace std;
int n, k, x, y;
void go() {
  cin >> n;
  vector<int> a(n + 1);
  for (int(i) = (1); (i) < (n + 1); (i)++) cin >> a[i];
  int sum_even = 0;
  int sum_odd = 0;
  vector<int> pe(n + 1, 0), se(n + 1, 0), po(n + 1, 0), so(n + 1, -1);
  for (int(i) = (1); (i) < (n + 1); (i)++) {
    if (i % 2 == 0) {
      pe[i] = sum_even;
      sum_even += a[i];
      if (i + 1 <= n) pe[i + 1] = sum_even;
    } else {
      po[i] = sum_odd;
      sum_odd += a[i];
      if (i + 1 <= n) po[i + 1] = sum_odd;
    }
  }
  sum_odd = sum_even = 0;
  for (int i = n; i >= 1; i--) {
    if (i % 2 == 0) {
      se[i] = sum_even;
      sum_even += a[i];
      if (i - 1 >= 0) se[i - 1] = sum_even;
    } else {
      so[i] = sum_odd;
      sum_odd += a[i];
      if (i - 1 >= 0) so[i - 1] = sum_odd;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if ((pe[i] + so[i]) == (po[i] + se[i])) ans++;
  }
  cout << ans;
}
int main() {
  int tc = 1;
  while (tc--) {
    go();
  }
  return 0;
}
