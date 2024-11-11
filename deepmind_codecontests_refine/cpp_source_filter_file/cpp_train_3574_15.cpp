#include <bits/stdc++.h>
using namespace std;
int n, q[505];
int x;
int main() {
  int i;
  cin >> n >> x;
  for (i = 0; i < n; i++) cin >> q[i];
  sort(q, q + n);
  for (i = 0; i < n; i++)
    if (q[i] >= x) break;
  int ans = 0;
  if (i >= n) {
    cout << n + 1 << endl;
    return 0;
  }
  int y = 0;
  if (q[i] != x) {
    y++;
    q[n++] = x;
    sort(q, q + n);
  }
  for (i = 0; i < n; i++) {
    if (q[i] == x) {
      int a = n - 1 - i;
      int b = i;
      if (a > b)
        ans = max(ans, a - b - 1);
      else
        ans = max(ans, b - a);
    }
  }
  cout << ans + y << endl;
}
