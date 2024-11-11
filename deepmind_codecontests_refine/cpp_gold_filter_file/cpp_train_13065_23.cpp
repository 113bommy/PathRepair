#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, c, d, i, ans = 0;
  cin >> n >> m;
  while (n--) {
    for (i = 0; i < m; i++) {
      cin >> c >> d;
      if (c == 1 || d == 1) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
