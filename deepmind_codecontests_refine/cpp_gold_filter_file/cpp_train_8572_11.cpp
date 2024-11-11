#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, s, a, b, c, d, sum, ss;
  cin >> n >> m >> s;
  sum = 0;
  for (a = 1; a <= n && a <= s; a += 2)
    for (b = 1; b <= m && a * b <= s; b += 2) {
      if (a * b == s) {
        sum +=
            (n - a + 1) * (m - b + 1) * (((a + 1) / 2) * ((b + 1) / 2) * 2 - 1);
        continue;
      }
      ss = s - a * b;
      for (c = 1; c <= n; c += 2) {
        if (c < a) {
          if (ss % c != 0) continue;
          d = ss / c + b;
          if (d > m || d % 2 != 1) continue;
          sum += (n - a + 1) * (m - d + 1);
        } else if (c > a) {
          if (ss % (c - a) != 0) continue;
          d = ss / (c - a);
          if (d >= b || d % 2 != 1) continue;
          sum += (n - c + 1) * (m - b + 1);
        }
      }
    }
  cout << sum << endl;
  return 0;
}
