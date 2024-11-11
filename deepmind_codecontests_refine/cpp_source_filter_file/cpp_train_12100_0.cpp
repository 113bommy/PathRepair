#include <bits/stdc++.h>
using namespace std;
int n, x, y, a, b;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> a >> b;
    int k = (y - x) / (a + b);
    if (((y - x) % (a + b)) != 0) {
      cout << -1 << '\n';
      continue;
    }
    cout << (k * a) << '\n';
  }
}
