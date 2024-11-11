#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const double pi = acos(-1.0);
int n, h[100011], a[100011];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", h + i);
  for (int i = 0; i < n; ++i) {
    a[i] = min(min(i + 1, n - i), h[i]);
    if (i && i < n - 1) {
      a[i] = min(a[i], min(h[i - 1], h[i + 1]) + 1);
    }
  }
  int ans = 1;
  for (int i = 1; i < n; ++i) {
    a[i] = min(a[i], a[i - 1] + 1);
  }
  for (int i = n - 2; i >= 0; --i) {
    a[i] = min(a[i], a[i + 1]);
  }
  for (int i = 0; i < n; ++i) ans = max(ans, a[i]);
  cout << ans;
  return 0;
}
