#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, w, x, c;
  cin >> a >> b >> w >> x >> c;
  long long delta = c - a;
  if (delta >= 0) {
    cout << 0 << endl;
  } else {
    double k = (1.0 * delta * x - b) / (w - x);
    long long t = ceil(delta + k);
    cout << t << endl;
  }
  return 0;
}
