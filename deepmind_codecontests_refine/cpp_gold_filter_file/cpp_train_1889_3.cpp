#include <bits/stdc++.h>
using namespace std;
long long n, shengyu, ans, a, now;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    now = min(shengyu, a / 2);
    shengyu -= now;
    a -= 2 * now;
    ans += now + a / 3;
    shengyu += a % 3;
  }
  cout << ans;
  return 0;
}
