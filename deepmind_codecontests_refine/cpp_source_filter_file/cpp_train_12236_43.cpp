#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, step;
  cin >> n >> a >> b;
  int ans = a;
  if (b > 0) {
    if (b + a <= n)
      ans = a + b;
    else {
      while (b > 0) {
        ans++;
        if (ans > n) ans = 1;
        b--;
      }
    }
  } else {
    if (a + b > 0)
      ans = a + b;
    else {
      while (b < 0) {
        ans--;
        if (ans < 1) ans = 6;
        b++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
