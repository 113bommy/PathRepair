#include <bits/stdc++.h>
using namespace std;
int ans[6][6];
int main() {
  ios_base::sync_with_stdio(false);
  long long n, m;
  cin >> n >> m;
  ans[1][2] = 0;
  ans[1][3] = 0;
  ans[1][4] = 2;
  ans[1][5] = 4;
  ans[2][2] = 0;
  ans[2][3] = 4;
  ans[2][4] = 8;
  ans[2][5] = 10;
  ans[3][3] = 8;
  ans[3][4] = 10;
  ans[3][5] = 14;
  ans[4][5] = 20;
  ans[5][5] = 24;
  if (n > m) swap(n, m);
  if (n < 6 && m < 6) {
    return cout << ans[n][m] << "\n", 0;
  }
  if (n == 1) {
    long long res = 6 * (m / 6);
    m %= 6;
    if (m < 4)
      cout << res << "\n";
    else {
      res += (m - 3) * 2;
      cout << res << "\n";
    }
  } else if (n == 2) {
    if (m == 7)
      cout << "12\n";
    else
      cout << (n * m) << "\n";
  } else {
    cout << 2 * ((n * m) / 2) << "\n";
  }
  return 0;
}
