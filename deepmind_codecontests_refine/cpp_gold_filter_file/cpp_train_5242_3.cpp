#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int x, a, b, c, k;
  cin >> x;
  if (x == 1) {
    cout << 1 << endl;
    return 0;
  }
  if (x == 2) {
    cout << 3 << endl;
    return 0;
  }
  for (int i = 3;; i++) {
    if (i & 1) {
      k = i / 2;
      a = k * k / 2;
      if (k & 1) a++;
      b = (((i - 1) / 2) / 2) * 2;
      c = 1;
    } else {
      k = i / 2 - 1;
      a = k * k / 2;
      b = 0;
      c = 0;
    }
    for (int aa = 0; aa <= a; aa++) {
      for (int bb = 0; bb <= b; bb++) {
        for (int cc = 0; cc <= c; cc++) {
          if ((aa * 4 + bb * 2 + cc) == x) {
            cout << i << endl;
            return 0;
          }
        }
      }
    }
  }
  return 0;
}
