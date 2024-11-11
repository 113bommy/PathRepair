#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, n, t, d;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    t = x % 14;
    d = abs(x / 14);
    if (d >= 1 && t >= 1 && t <= 6) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
