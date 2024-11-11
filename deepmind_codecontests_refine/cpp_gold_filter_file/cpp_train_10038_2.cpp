#include <bits/stdc++.h>
using namespace std;
int n, m, a[3010], b[3010];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + m);
  int x, y;
  for (x = 0, y = 0; x < m && y < n; x++) {
    if (b[x] >= a[y]) y++;
  }
  cout << n - y;
}
