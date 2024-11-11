#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int x[maxn], n, m;
int main() {
  int ans = 0, use = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> m;
    x[m] = 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> m;
    x[m] = i;
  }
  for (int i = 1; x[i] <= n && i <= n && x[i + 1] == x[i] + 1; i++) use = i + 1;
  if (use && x[use] == n) {
    m = 0;
    for (int i = use + 1; i <= n; i++) m = max(m, x[i] - (i - use - 1));
    if (!m) {
      cout << n - use << "\n";
      return 0;
    }
  }
  if (x[1] && x[1] < n) {
    for (int i = 2; i <= n; i++) x[i] = max(0, x[i] - x[1]);
    ans += x[1];
    x[1] = 0;
  }
  if (x[1] == n) {
    m = 0;
    for (int i = 2; i <= n; i++) m = max(m, x[i] - (i - 2));
    if (m) {
      cout << ans + 2 * n << "\n";
      return 0;
    } else {
      cout << ans + n - 1 << "\n";
      return 0;
    }
  }
  m = 0;
  for (int i = 2; i <= n; i++) m = max(m, x[i] - (i - 1));
  cout << ans + m + n << "\n";
  return 0;
}
