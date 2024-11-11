#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (x > y) {
    cout << n;
    return 0;
  }
  sort(a, a + n);
  int i = n - 1, j = 0, ans = 0;
  while (a[i] > x) {
    i--;
  }
  while (j < n && a[j] <= x) {
    ans++;
    j++;
    a[i] += y;
    if (a[i] > x) i--;
  }
  cout << ans;
  return 0;
}
