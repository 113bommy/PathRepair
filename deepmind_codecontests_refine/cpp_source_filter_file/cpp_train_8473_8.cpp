#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  long n, i, a, c[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    c[a]++;
  }
  if (c[1] != n / 3 || c[5] != 0 || c[7] != 0 || c[4] != c[2] ||
      c[3] != (c[6] - c[2] + c[4]) || c[2] != (c[4] + c[6] - c[3])) {
    cout << -1;
    return 0;
  }
  for (i = 0; i < n / 3; i++) {
    if (c[2] != 0) {
      if (c[4] != 0) {
        cout << "1 2 4\n";
        c[4]--;
      } else {
        cout << "1 2 6\n";
        c[6]--;
      }
      c[2]--;
    } else if (c[3] != 0) {
      cout << "1 3 6\n";
    }
  }
  return 0;
}
