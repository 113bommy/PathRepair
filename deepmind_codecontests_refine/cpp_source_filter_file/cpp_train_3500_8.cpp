#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a[110000], b[110000], mx = -1100000000, m;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (mx < a[i]) {
      mx = a[i];
      m = i;
    }
    b[i] = a[i];
  }
  sort(a + 1, a + n + 1);
  if (k == 1)
    cout << a[1];
  else if (k == 2 && m < n && m > 1)
    cout << max(a[1], a[n]);
  else
    cout << a[n];
  return 0;
}
