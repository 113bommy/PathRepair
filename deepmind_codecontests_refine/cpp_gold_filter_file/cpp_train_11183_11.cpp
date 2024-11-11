#include <bits/stdc++.h>
using namespace std;
int m(int x) {
  if (x < 0)
    return -1 * x;
  else
    return x;
}
int main() {
  int n, t, a[10000], ans = 1;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> t;
  sort(a, a + n);
  for (int i = 0; i < n - 1; i++) {
    int tmp = 1;
    int j = i + 1;
    while (m(a[j] - a[i]) <= t) {
      j++;
      tmp++;
      if (j == n) break;
    }
    if (tmp > ans) ans = tmp;
  }
  cout << ans;
  return 0;
}
