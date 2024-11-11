#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a1, i, a, ans = 0, d;
  cin >> n >> a;
  ans += a + 1;
  a1 = a;
  for (i = 2; i <= n; i++) {
    a = a1;
    cin >> a1;
    d = a - a1;
    if (d < 0) d = -d;
    ans += d + 2;
  }
  cout << ans;
}
