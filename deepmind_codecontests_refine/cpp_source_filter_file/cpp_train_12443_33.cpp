#include <bits/stdc++.h>
double eps = 1e-9;
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  long long s, x;
  cin >> s >> x;
  long long a = s - x;
  if (x > s) {
    cout << 0;
    return 0;
  }
  long long ans = __builtin_popcount(x);
  ans = (1ll << ans);
  if (a == 0) {
    ans -= 2;
  }
  if (a % 2 == 1) {
    cout << 0;
    return 0;
  }
  for (int i = 50; i >= 1; i--) {
    if ((a & (1ll << i)) && (x & (1ll << (i - 1)))) {
      ans = 0;
    }
  }
  cout << ans;
  return 0;
}
