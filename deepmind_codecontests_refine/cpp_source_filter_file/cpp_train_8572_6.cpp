#include <bits/stdc++.h>
using namespace std;
int main() {
  int cnt = 0;
  int n, m, s;
  cin >> n >> m >> s;
  for (int n1 = 1; n1 <= n; n1 += 2) {
    for (int m1 = 1; m1 <= m; m1 += 2) {
      if (n1 * m1 == s) {
        int amount = (n1 + 1) * (m1 + 1) / 2 - 1;
        cnt += (n - n1 + 1) * (m - m1 + 1) * amount;
      } else if (n1 * m1 > s) {
        for (int a = 1; a <= n1 / 2; ++a) {
          if ((n1 * m1 - s) % (4 * a) == 0) {
            int b = (n1 * m1 - s) / (4 * a);
            if (1 <= b && b <= m1 / 2) cnt += 2 * (n - n1 + 1) * (m - m1 + 1);
          }
        }
      }
    }
  }
  cout << cnt;
  return 0;
}
