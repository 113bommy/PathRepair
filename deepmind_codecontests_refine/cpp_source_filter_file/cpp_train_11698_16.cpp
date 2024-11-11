#include <bits/stdc++.h>
using namespace std;
int n, a, b, t, x, y, sa, sb;
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> t >> x >> y;
    if (x == 1) {
      a++;
      sa += x;
    } else {
      b++;
      sb += x;
    }
  }
  if (sa >= 10 * a / 2)
    cout << "LIVE" << endl;
  else
    cout << "DEAD" << endl;
  if (sb >= 10 * b / 2)
    cout << "LIVE" << endl;
  else
    cout << "DEAD" << endl;
  return 0;
}
