#include <bits/stdc++.h>
using namespace std;
long long n, l, r, ans, idx;
int main() {
  cin >> n;
  while (n--) {
    ans = 0;
    cin >> l >> r;
    for (long long i = 62; i >= 0; i--)
      if ((r & (1LL << i)) == (l & (1LL << i)))
        ans += (r & (1LL << i));
      else {
        ans += (1LL << i) - 1;
        r &= ((1LL << (i + 1)) - 1);
        if (r == (1LL << (i - 1) - 1)) ans += (1LL << i);
        break;
      }
    cout << ans << '\n';
  }
  return 0;
}
