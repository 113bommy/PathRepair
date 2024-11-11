#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  long long res = 0, ans = 0;
  for (int i = 1; i <= n; ++i) {
    long long x;
    scanf("%lld", &x);
    long long r = min(res, x / 2);
    ans += r;
    x -= r * 2;
    res -= r;
    ans += x / 3;
    res += x % 3;
  }
  cout << ans << '\n';
  return 0;
}
