#include <bits/stdc++.h>
using namespace std;
int test, a, b, c;
int main() {
  cin >> test;
  while (test--) {
    cin >> a >> b >> c;
    int res = 0;
    for (int i = 0; i <= 100; i++) {
      if (a >= i && b >= i * 2) res = max(res, i + min((b - i * 2), c / 2));
    }
    cout << res * 3 << "\n";
  }
  return 0;
}
