#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int cost;
  if (f > e) {
    int x = min(b, min(c, d));
    cost = f * x;
    if (d != x) {
      cost += e * min(a, (d - x));
    }
    cout << cost << endl;
  } else {
    int x = min(a, d);
    cost = e * x;
    if (d != x) {
      cost += f * min(b, min(c, d));
    }
    cout << cost << endl;
  }
  return 0;
}
