#include <bits/stdc++.h>
using namespace std;
long long int s, x;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> s >> x;
  if ((s - x) % 2 != 0 || s < x) {
    printf("0");
    return 0;
  }
  long long int pc = __builtin_popcountll(x);
  long long int ans = 1ll;
  ans <<= pc;
  long long int eq = (s - x) / 2;
  for (long long int i = 0; i < 63; i++) {
    if ((eq & (1 << i)) && (x & (1 << i))) {
      printf("0");
      return 0;
    }
  }
  if (eq == 0) ans -= 2;
  cout << ans << endl;
  return 0;
}
