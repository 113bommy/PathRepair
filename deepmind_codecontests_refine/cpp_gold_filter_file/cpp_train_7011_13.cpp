#include <bits/stdc++.h>
using namespace std;
int main() {
  long long m, n, t, dem = 0, j;
  cin >> m >> n;
  if (m == n) {
    if (m == 1)
      cout << 2;
    else {
      if (sqrt(4 * m + 1) == int(sqrt(4 * m + 1)))
        cout << 1;
      else
        cout << 0;
    }
  } else {
    if ((m + n) % 2 != 0)
      cout << 0;
    else {
      t = 4 * (m + n) + 2;
      for (int i = 1; i * i <= t; i += 2) {
        j = t - i * i;
        if (sqrt(j) == int(sqrt(j)) && j % 2 != 0 && j != i * i &&
            ((sqrt(j) - 1) / 2 + (i - 1) * (i - 1) / 4 == m ||
             (sqrt(j) - 1) / 2 + (i - 1) * (i - 1) / 4 == n))
          dem++;
      }
      if (dem == 0)
        cout << 0;
      else
        cout << 1;
    }
  }
}
