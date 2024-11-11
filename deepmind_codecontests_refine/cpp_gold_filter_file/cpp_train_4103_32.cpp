#include <bits/stdc++.h>
using namespace std;
int main() {
  int sum = 0, x, y, kol = 0, n, m, k, a[20000], b[20000];
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    bool t = true;
    cin >> x >> y;
    for (int j = 0; j < kol; j++) {
      if (a[j] == x) {
        if (b[j] > y) b[j] = y;
        t = false;
      }
    }
    if (t) {
      a[kol] = x;
      b[kol] = y;
      kol++;
    }
    t = true;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i] > a[j]) {
        swap(a[i], a[j]);
        swap(b[i], b[j]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    sum += b[i];
  }
  if (sum <= k)
    cout << sum;
  else
    cout << k;
}
