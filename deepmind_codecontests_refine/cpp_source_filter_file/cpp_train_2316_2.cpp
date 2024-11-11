#include <bits/stdc++.h>
using namespace std;
int n, ans = 1000000000;
int main() {
  cin >> n;
  for (int i = 2; i < n; i++) {
    int a = n, b = i, kol = 0;
    while (a > 1 || b > 1) {
      if (a == b) break;
      if (a > b)
        a -= b;
      else
        b -= a;
      kol++;
    }
    if (a == 1 && b == 1) ans = min(ans, kol);
  }
  cout << ans;
}
