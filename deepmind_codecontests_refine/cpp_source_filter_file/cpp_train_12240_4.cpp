#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, h, n;
  while (cin >> l >> h >> n) {
    for (int i = 1; i <= l; i++) {
      if (i * 2 * h + 1 <= n && (i + 1) * 2 * h >= n) {
        int ll = i + 1;
        int yu = n - i * 2 * h;
        if (yu % 2 == 1) {
          cout << ll << " " << yu / 2 + 1 << " "
               << "L" << endl;
        } else
          cout << ll << " " << yu / 2 << " "
               << "R" << endl;
      }
    }
  }
  return 0;
}
