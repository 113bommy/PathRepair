#include <bits/stdc++.h>
using namespace std;
long long ans;
void solve(long long a, long long b, long long c, long long l) {
  for (long long i = 0; i <= l; i++) {
    long long x = min(a - b - c + l, l - i);
    if (x >= 0) ans -= (x + 1) * (x + 2) / 2LL;
  }
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long a, b, c, l;
  cin >> a >> b >> c >> l;
  ans = (l + 1) * (l + 2) * (l + 3) / 6LL;
  solve(a, b, c, l);
  solve(b, a, c, l);
  solve(c, a, b, l);
  cout << ans << endl;
  return 0;
}
