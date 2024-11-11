#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, cnt, i;
  cin >> n >> x;
  int a[n + 5];
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  bool b[x + 1];
  memset(b, 0, sizeof(b));
  for (i = 0; i < n; i++) {
    if (a[i] <= x) b[a[i]] = 1;
  }
  cnt = 0;
  for (i = 0; i < x; i++)
    if (!b[i]) cnt++;
  if (b[x] == 1) cnt++;
  cout << cnt;
  return 0;
}
