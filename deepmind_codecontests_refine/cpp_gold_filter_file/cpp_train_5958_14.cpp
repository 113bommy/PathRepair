#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k, m;
  cin >> m;
  for (k = 0; k < m; k++) {
    long long a, k = 0, d, i, j, s;
    cin >> a >> s >> d;
    if (a < s)
      cout << a << endl;
    else {
      long long m = 0, g = 0;
      long long now = 0;
      m = a / 2;
      if (a % 2 == 1) m++;
      g = m / s;
      now += g * s;
      long long otv = g * s + (g - 1) * d;
      if (now < m) {
        otv += d + m - now;
      }
      if (a > otv) otv += a - otv;
      cout << otv << endl;
    }
  }
}
