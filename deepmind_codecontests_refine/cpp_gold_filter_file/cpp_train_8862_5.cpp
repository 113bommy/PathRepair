#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  int ans = 0;
  int l = 1, r = 1;
  while (r <= n) {
    if (a[r] - a[l] <= 5) {
      ans = max(ans, r - l + 1);
      r++;
    } else {
      l = l + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
