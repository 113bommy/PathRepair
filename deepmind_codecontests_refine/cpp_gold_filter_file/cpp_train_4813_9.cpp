#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c, mini = INT_MAX, p, q, r;
    cin >> a >> b >> c;
    for (int i = 1; i < 50007; i++) {
      for (int j = i; j < 50007; j += i)
        for (int k = j; k < 50007; k += j) {
          int ans = abs(a - i) + abs(b - j) + abs(c - k);
          if (ans < mini) {
            mini = ans;
            p = i, q = j, r = k;
          }
        }
    }
    cout << mini << endl;
    cout << p << " " << q << " " << r << endl;
  }
  return 0;
}
