#include <bits/stdc++.h>
using namespace std;
int main() {
  double n, x, y;
  bool isEqual = false;
  set<double> s;
  cin >> n >> x >> y;
  for (int i = 0; i < n; i++) {
    double x1, y1, slope = 0;
    cin >> x1 >> y1;
    if (x == x1) {
      isEqual = true;
    } else {
      slope = ((y - y1) / (x - x1));
      s.insert(slope);
    }
  }
  if (isEqual == true)
    cout << s.size() + 1;
  else
    cout << s.size();
}
