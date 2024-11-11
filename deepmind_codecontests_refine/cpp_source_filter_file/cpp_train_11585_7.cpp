#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  long t, a, b, res;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    res = 0;
    cin >> a >> b;
    if (a == b) {
      cout << res;
    } else {
      if (abs(a - b) % 10 == 0) {
        res += abs(a - b) / 10;
      } else {
        res += abs(a - b) / 10 + 1;
      }
      cout << res << endl;
    }
  }
  return 0;
}
