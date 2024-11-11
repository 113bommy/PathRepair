#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, m, l;
  int a[50000];
  cin >> n >> m >> l;
  for (i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  for (i = 0; i <= n; i++) {
    if (l >= m) break;
    l += a[i + 1] - 1;
  }
  if (i == m + 1)
    cout << -1;
  else
    cout << i;
  return 0;
}
