#include <bits/stdc++.h>
using namespace std;
long k, b, n, t, r, ra, ans;
int main() {
  cin >> k >> b >> n >> t;
  r = 1;
  while (true) {
    r = k * r + b;
    if (r > t)
      break;
    else
      ra++;
  }
  ans = n - ra;
  if (ans < 0) ans = 0;
  cout << ans << endl;
}
