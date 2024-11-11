#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k = 0;
  double x, y, x1, y1;
  cin >> n >> x >> y;
  set<double> s;
  for (int i = 0; i < n; i++) {
    cin >> x1 >> y1;
    if (x1 == x) {
      k = 1;
    } else {
      s.insert((y1 - y) / (x1 - x));
    }
  }
  cout << s.size() + k;
  return 0;
}
