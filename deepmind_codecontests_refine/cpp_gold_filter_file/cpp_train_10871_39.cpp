#include <bits/stdc++.h>
using namespace std;
int n, a[1010], mn = 1e9, step, mx, start, st;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  step = 40000 / n;
  for (int i = 0; i <= step; i++) {
    for (int j = -20000; j <= 20000; j++) {
      int x = j;
      mx = 0;
      for (int k = 0; k < n; k++) {
        mx = max(mx, abs(a[k] - x));
        if (mx > mn) break;
        x += i;
      }
      if (mx < mn) {
        mn = mx;
        start = j;
        st = i;
      }
    }
  }
  cout << mn << endl << start << " " << st << endl;
  return 0;
}
