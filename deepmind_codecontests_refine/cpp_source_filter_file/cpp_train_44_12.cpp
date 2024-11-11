#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, cnt, i, j;
  while (cin >> n >> a >> b >> c) {
    cnt = 0;
    for (i = 0; i <= b; i++) {
      for (j = 0; j <= c; j++) {
        if ((2 * (n - i - 2 * j)) <= a) {
          cnt++;
        }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
