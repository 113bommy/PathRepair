#include <bits/stdc++.h>
using namespace std;
const int N = 111;
const unsigned long long Mod = (unsigned long long)(1e9 + 7);
int main() {
  unsigned long long n, f = 1, ans = 0;
  cin >> n;
  while (3 * f * (f + 1) / 2 - f <= n) {
    if ((n + f) % 3 == 0) ans++;
    f++;
  }
  cout << ans;
  return 0;
}
