#include <bits/stdc++.h>
using namespace std;
int n, a[1000000], x = 0, y = 0, z = 0, t;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      x++;
    }
    if (a[i] == 2) {
      y++;
    }
    if (a[i] == 3) {
      z++;
    }
  }
  t = max(x, y);
  if (t < z) {
    cout << (n - z);
  } else {
    cout << (n - t);
  }
}
