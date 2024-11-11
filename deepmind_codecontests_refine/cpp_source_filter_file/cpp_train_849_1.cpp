#include <bits/stdc++.h>
using namespace std;
int n, ans, sum = 1, t[2];
int main() {
  cin >> n;
  t[0] = 1;
  for (int i = 1, x; i <= n; i++) {
    cin >> x;
    sum *= (x > 0) ? 1 : -1;
    ans += (sum > 0) ? t[1] : t[0];
    t[sum > 0 ? 0 : 1]++;
  }
  cout << ans << ' ' << n * (n + 1) / 2 - ans << endl;
  return 0;
}
