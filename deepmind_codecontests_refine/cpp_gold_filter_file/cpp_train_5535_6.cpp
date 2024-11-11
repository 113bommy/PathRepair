#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int s, f, t;
    cin >> s >> f >> t;
    int per = (m - 1);
    int r = t / per;
    int k = t - r * per;
    if (f == s) {
      cout << t << endl;
      continue;
    }
    if (r % 2 == 0) {
      if (k >= s) {
        r++;
      }
    } else {
      if (k > m - s) {
        r++;
      }
    }
    if (r % 2 == 0) {
      if (f >= s) {
        cout << r * per + f - 1 << endl;
      } else {
        cout << r * per + per + m - f << endl;
      }
    } else {
      if (f <= s) {
        cout << r * per + m - f << endl;
      } else {
        cout << r * per + per + f - 1 << endl;
      }
    }
  }
  return 0;
}
