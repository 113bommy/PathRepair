#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) cin >> a[i];
  int m;
  cin >> m;
  int b[m];
  for (int i = 0; i < m; ++i) cin >> b[i];
  sort(a + 0, a + n);
  sort(b + 0, b + m);
  int ans = 0;
  for (int i = 0, j = 0; i < n; i++) {
    while (j < n) {
      if (abs(a[i] - b[j]) <= 1) {
        ans++;
        j++;
        break;
      } else if (abs(a[i] - b[j]) > 1) {
        break;
      } else {
        j++;
      }
    }
  }
  cout << ans;
  return 0;
}
