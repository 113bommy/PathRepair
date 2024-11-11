#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  bool ish;
  cin >> n;
  for (int i = 4; i <= n; i++) {
    int t = i;
    ish = true;
    while (t > 0) {
      int m = t % 10;
      if (m != 4 && m != 7) {
        ish = false;
        break;
      }
      t = (t - m) / 10;
    }
    if (ish && n % i == 0) {
      cout << "YES\n";
      break;
    }
  }
  if (!ish) cout << "NO\n";
  return 0;
}
