#include <bits/stdc++.h>
using namespace std;
long long int fast_expo(long long int x, long long int p) {
  if (p == 0)
    return 1;
  else if (p % 2 == 0) {
    long long int t = fast_expo(x, p / 2) % 100000;
    return (t * t) % 100000;
  } else
    return (x * (fast_expo(x, p - 1)) % 100000) % 100000;
}
int main() {
  unsigned long long int n, ans = 1, i;
  cin >> n;
  for (i = 0; i <= 4; i++) {
    ans *= (n + i);
    if (ans % (i + 1) == 0) ans /= (i + 1);
  }
  for (i = 0; i < 2; i++) {
    ans *= (n + i);
    if (ans % (i + 1) == 0) ans /= (i + 1);
  }
  cout << ans;
}
