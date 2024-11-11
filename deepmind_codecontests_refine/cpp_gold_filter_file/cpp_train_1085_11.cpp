#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, m, y;
  cin >> n >> x >> m >> y;
  if (x > y) swap(x, y), swap(n, m);
  long long ans = 0;
  for (int i = 1; i < n + 1; i++) {
    int l = max(x + i - y, 1), r = min(y - x + i - 1, m);
    l = max(l, y - x - i + 1);
    if (l <= r)
      ans += (r - l + 1) * 2;
    else
      ans++;
  }
  int l = max(1, x + n + 1 - y), r = m;
  if (l <= r) ans += (r - l + 1);
  cout << ans + 1 << endl;
}
