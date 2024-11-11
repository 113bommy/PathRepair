#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int m, n, k, s, flag = 0, ss, b;
  cin >> m >> n >> k >> s;
  for (int i = k; i <= 2 * k; i++) {
    for (int j = k + 1; j <= 2 * n; j++) {
      for (int b = j + 1; b <= 2 * m; b++) {
        if (s <= i && 2 * s >= i && 2 * s < j && 2 * s < b && j >= n &&
            b >= m) {
          flag = 1;
          cout << b << " " << j << " " << k << endl;
          break;
        }
      }
      if (flag) break;
    }
    if (flag) break;
  }
  if (!flag) cout << "-1" << endl;
  return 0;
}
