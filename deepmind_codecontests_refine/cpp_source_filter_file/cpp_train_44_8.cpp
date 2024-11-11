#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, i, j, cnt = 0;
  cin >> n >> a >> b >> c;
  for (i = 0; i <= a; i++) {
    for (j = 0; j <= c; j++) {
      if (n - (a / 2) - (2 * c) <= b && n - (a / 2) - (2 * c) >= 0) {
        cnt += 1;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
