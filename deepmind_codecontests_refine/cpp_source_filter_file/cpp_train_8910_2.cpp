#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int N = 2e6 + 10;
const long long mod = 1e9 + 7;
const int inf = 2 * (0x3f3f3f3f);
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const double esp = 1e-10;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, ans;
  cin >> n >> k;
  ans = 2 * (n - 1) / k;
  if ((n - 1) % k >= 2)
    ans += 2;
  else
    ans += (n - 1) % k;
  cout << ans << endl;
  for (int i = 2; i <= k + 1; i++) {
    cout << 1 << " " << i << endl;
  }
  for (int j = k + 2; j <= n; j++) {
    cout << j << " " << j - k << endl;
  }
  return 0;
}
