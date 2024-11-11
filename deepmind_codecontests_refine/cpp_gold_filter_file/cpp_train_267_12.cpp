#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int c, v0, v1, a, l;
  while (cin >> c >> v0 >> v1 >> a >> l) {
    int k = 0, sum = 0, inc = v0;
    while (true) {
      k++, sum += inc;
      if (sum >= c) break;
      sum -= l;
      inc += a;
      if (inc >= v1) inc = v1;
    }
    cout << k << endl;
  }
  return 0;
}
