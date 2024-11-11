#include <bits/stdc++.h>
using namespace std;
int main() {
  int x[4], y[4], a1, a2, b1, b2, n;
  cin >> n;
  for (int i = 0; i < 4; i++) {
    cin >> a1 >> b1 >> a2 >> b2;
    x[i] = min(a1, b1);
    y[i] = min(a2, b2);
  }
  for (int i = 0; i < 4; i++)
    if (x[i] + y[i] <= n) {
      cout << i + 1 << ' ' << x[i] << ' ' << n - y[i];
      return 0;
    }
  cout << "-1";
  return 0;
}
