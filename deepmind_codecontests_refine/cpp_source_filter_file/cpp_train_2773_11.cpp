#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  int h, m;
  cin >> h >> m;
  if (h % 10 == 7 || m % 10 == 7) {
    cout << 0 << endl;
    return 0;
  } else {
    int i = 0;
    while (m % 10 != 7 && h % 10 != 7) {
      if (m - x < 0) {
        m = m - x + 60;
        h -= 1;
        if (h < 0) h = h + 24;
      }
      m -= x;
      i++;
      if (m % 10 == 7 || h % 10 == 7) break;
    }
    cout << i << endl;
  }
  return 0;
}
