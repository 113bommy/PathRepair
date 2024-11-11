#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned int n, a, b, c, cnt, i, j;
  while (cin >> n >> a >> b >> c) {
    cnt = 0;
    for (i = 0; i <= a; i++) {
      for (j = 0; j <= b; j++) {
        if ((2 * (n - i - 2 * j)) <= c) {
          cnt++;
        }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
