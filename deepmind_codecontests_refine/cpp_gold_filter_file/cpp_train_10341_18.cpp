#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long bin = 2, cur, f = 4, s = 0;
  while (n -= 2) {
    (bin <<= 1) %= 1000000009;
    cur = (bin + 1000000009 - 3) % 1000000009;
    (f *= cur) %= 1000000009;
    (s += f) %= 1000000009;
  }
  long long ans = (s * s * 2 + 8 * s + 10) % 1000000009;
  cout << ans << endl;
  return 0;
}
