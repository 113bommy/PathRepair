#include <bits/stdc++.h>
using namespace std;
int n, c1[101], c2[101], v1[6], v2[6], i, nr, ok, x, y;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> c1[i];
  }
  for (i = 1; i <= n; i++) {
    cin >> c2[i];
  }
  for (i = 1; i <= n; i++) {
    v1[c1[i]]++;
    v2[c2[i]]++;
  }
  for (i = 1; i <= 5; i++) {
    if (v1[i] + v2[i] % 2 == 1 && ok == 0) {
      ok = 1;
      cout << -1;
    }
  }
  if (ok == 0) {
    for (i = 1; i <= 5; i++) {
      x = max(v1[i], v2[i]);
      y = min(v1[i], v2[i]);
      nr = nr + (x - y) / 2;
    }
    cout << nr / 2;
  }
  return 0;
}
