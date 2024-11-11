#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, n, y[1000], a1, b1, c1, a2, b2, c2, w1, w2;
  bool good = 1;
  cin >> n;
  for (i = 0; i < n; i++) cin >> y[i];
  if (n == 3) {
    if (y[2] - y[1] == y[1] - y[0])
      cout << "NO";
    else
      cout << "YES";
    return 0;
  }
  for (i = 1; i < n; i++) {
    w1 = -1;
    w2 = -1;
    a1 = y[i] - y[0];
    b1 = -i;
    c1 = (i + 1) * y[0] - y[i];
    for (j = 1; j < n; j++) {
      if (a1 * (j + 1) + b1 * y[j] + c1 != 0) {
        if (w1 == -1)
          w1 = j;
        else if (w2 == -1) {
          w2 = j;
          a2 = y[w2] - y[w1];
          b2 = w1 - w2;
          c2 = (w2 + 1) * y[w1] - (w1 + 1) * y[w2];
        }
      } else if (w1 != -1 && w2 != -1 && a2 * (j + 1) + b1 * y[j] + c2 == 0)
        break;
    }
    if (j == n && w1 != -1) {
      if (w2 == -1) {
        cout << "YES";
        return 0;
      }
      good = 1;
      for (j = 0; j < n; j++) {
        w1 = a1 * (j + 1) + b1 * y[j] + c1;
        w2 = a2 * (j + 1) + b2 * y[j] + c2;
        if (w1 == 0 && w2 == 0 || w1 != 0 && w2 != 0) good = 0;
      }
      if (!good || a1 * b2 != a2 * b1) continue;
      cout << "YES";
      return 0;
    }
  }
  a2 = y[2] - y[1];
  b2 = -1;
  c2 = 3 * y[1] - 2 * y[2];
  for (j = 3; j < n; j++)
    if (a2 * (j + 1) + b2 * y[j] + c2 != 0) break;
  if (j == n && a2 + b2 * y[0] + c2 != 0)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
