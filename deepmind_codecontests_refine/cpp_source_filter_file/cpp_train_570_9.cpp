#include <bits/stdc++.h>
using namespace std;
int d[500005];
int main() {
  int n, i, ans = 0, l, le, r;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &d[i]);
  }
  l = 0;
  for (i = 1; i < n; ++i) {
    if (d[i - 1] == d[i] || d[i] == d[i + 1] || i == n - 1) {
      ans = max(ans, (l + i) / 2 - l);
      le = l + 1;
      r = i - 1;
      while (le < r) {
        d[le] = d[l];
        d[r] = d[i];
        le++;
        r--;
      }
      l = i;
    }
  }
  cout << ans << endl;
  for (i = 0; i < n; ++i) printf("%d ", d[i]);
  return 0;
}
