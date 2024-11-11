#include <bits/stdc++.h>
using namespace std;
const int mxn = 2e5 + 5, mod = 1e9 + 7;
int main(void) {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  };
  long long int s, x, i, j;
  cin >> s >> x;
  long long int d = (s - x) / 2;
  if ((s - x) & 1) {
    cout << 0;
    return 0;
  }
  for (i = 50; i >= 0; i--) {
    if (s >> i & 1) break;
  }
  long long int ans = 1, cnt = 0;
  for (j = 0; j <= i; j++) {
    if (x >> j & 1) {
      if (!(d >> j & 1))
        ans *= 2ll;
      else
        ans = 0;
    }
  }
  if (d == 0) ans -= 2;
  cout << ans;
}
