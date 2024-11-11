#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long s, x;
  cin >> s >> x;
  if ((s - x) % 2 != 0) {
    cout << 0 << endl;
    return 0;
  }
  long long AandB = (s - x) / 2;
  if (AandB < 0 || (AandB & x) != 0) {
    cout << 0 << endl;
    return 0;
  }
  long long ones = 0;
  while (x > 0) {
    x = x & (x - 1);
    ones++;
  }
  long long ans = 1;
  ans <<= ones;
  if (AandB == 0) ans -= 2;
  cout << ans << endl;
  return 0;
}
