#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, i, j, cnt = 0;
  cin >> n >> a >> b >> c;
  for (i = 0; i <= a; i++) {
    for (j = 0; j <= c; j++) {
      if (n - (i / 2) - (2 * j) <= b && n - (i / 2) - (2 * j) >= 0) {
        cnt += 1;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
