#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7, mod = 1e9 + 7;
int a[4];
int32_t main() {
  long long sum = 0;
  for (int i = 0; i < 4; i++) cin >> a[i], sum += a[i];
  while (sum > 4) {
    bool bil = 0;
    for (int i = 0; i < 4; i++)
      if ((a[i] % 2 == a[(i + 1) % 4] % 2) && !(a[i] % 2))
        a[i] /= 2, a[(i + 1) % 4] /= 2, cout << "/" << i + 1 << '\n', bil = 1;
    for (int i = 0; i < 4; i++)
      if ((a[i] % 2 == a[(i + 1) % 4] % 2) && (a[i] % 2) &&
          !(a[i] == a[(i + 1) % 4] && a[i] == 1))
        a[i] += 1, a[(i + 1) % 4] += 1, cout << "+" << i + 1 << '\n', bil = 1;
    if (bil == 0) {
      for (int i = 0; i < 4; i++)
        if (!(a[i] == a[(i + 1) % 4] && a[i] == 1)) {
          a[i] += 1, a[(i + 1) % 4] += 1, cout << "+" << i + 1 << '\n', bil = 1;
          break;
        }
    }
    sum = 0;
    for (int i = 0; i < 4; i++) sum += a[i];
  }
}
