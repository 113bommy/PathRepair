#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, j, q = 0, t, a[1000] = {};
  cin >> n >> k;
  for (i = 0; i < n; i++) cin >> t, a[t]++;
  while (true) {
    bool ok = false;
    for (i = 1; i < k; i++)
      if (a[i]) ok = true;
    if (!ok) break;
    for (i = k - 1; i >= 1; i--)
      if (a[i]) a[i]--, a[i + 1]++;
    q++;
  }
  cout << q;
  return 0;
}
