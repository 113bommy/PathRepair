#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, i;
  cin >> t;
  while (t--) {
    long long int x, y, a, b, cost = 0;
    cin >> x >> y >> a >> b;
    if (2 * a > b) {
      if (x < y) {
        cost += x * b;
        cost += abs(x - y) * a;
      } else {
        cost += y * b;
        cost += abs(x - y) * a;
      }
    } else {
      if (x < y) {
        cost += x * (2 * a);
        cost += abs(x - y) * b;
      } else {
        cost += y * (2 * a);
        cost += abs(x - y) * b;
      }
    }
    cout << cost << endl;
  }
  return 0;
}
