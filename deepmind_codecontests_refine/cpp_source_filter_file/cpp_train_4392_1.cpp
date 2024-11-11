#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int a, b;
  cin >> a >> b;
  int n = a + b;
  int ans = 0;
  for (int i = 2; i <= n; ++i) {
    int g = n / i;
    int mia = (a) / (g + 1);
    int mxa = a / g;
    int mib = (b) / (g + 1);
    int mxb = b / g;
    int r = n / g;
    if (mia <= mxa && mib <= mxb)
      ans += max((min(mxb + mxa, r) - max(mib + mia, i)) + 1, 0);
    i = r;
  }
  cout << ans << '\n';
  return 0;
}
