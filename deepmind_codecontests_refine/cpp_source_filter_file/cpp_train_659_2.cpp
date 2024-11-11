#include <bits/stdc++.h>
using namespace std;
int main() {
  long int y, n, k, t = 0;
  int s = 0;
  cin >> y >> k >> n;
  while (t <= n) {
    if (t - y > 0) {
      cout << t - y << " ";
      s = 1;
    }
    t += k;
  }
  if (s == 1) {
    cout << -1;
  }
  return 0;
}
