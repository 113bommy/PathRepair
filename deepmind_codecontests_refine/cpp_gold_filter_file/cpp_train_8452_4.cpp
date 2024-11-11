#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, x, a, b, dist = 0;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> n >> x >> a >> b;
    if (a > b) swap(a, b);
    if (x >= a - 1 + n - b)
      dist = n - 1;
    else
      dist = b - a + x;
    cout << dist << endl;
  }
  return 0;
}
