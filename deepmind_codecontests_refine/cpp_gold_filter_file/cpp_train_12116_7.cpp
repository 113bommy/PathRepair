#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int l, r;
  cin >> l >> r;
  long long int b;
  long long int ans = 0;
  for (b = 64; b >= 1; b--) {
    if ((r & (1ll << (b - 1))) && !(l & (1ll << (b - 1)))) {
      break;
    }
  }
  for (long long int i = b; i >= 1; i--) {
    ans += (1ll << (i - 1));
  }
  cout << ans << endl;
  return 0;
}
