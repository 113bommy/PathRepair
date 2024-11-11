#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int x, y, m = 0;
  cin >> x >> y;
  for (int i = 1; i <= x; i++) {
    for (int j = 1; j <= y;) {
      if ((j + i) % 5 == 0) {
        m += ((y - j) / 5) + 1;
        break;
      } else
        j++;
    }
  }
  cout << m << '\n';
}
