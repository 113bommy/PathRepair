#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x0, y0;
  cin >> n >> x0 >> y0;
  int k = 0;
  set<double> s;
  int x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    if (x != x0) {
      s.insert((double)(y - y0) / (x - x0));
    } else {
      k = 1;
    }
  }
  cout << s.size() + k;
}
