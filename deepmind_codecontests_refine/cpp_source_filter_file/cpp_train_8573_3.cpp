#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  long long p(1);
  cin >> a >> b;
  while (b--) p = (p << 1ll) % 1000000007ll;
  long long ans(1);
  while (a--) {
    p--;
    if (p < 0) p += 1000000007ll;
    ans *= p;
    ans %= 1000000007;
  }
  cout << ans;
  return 0;
}
