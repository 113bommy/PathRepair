#include <bits/stdc++.h>
using namespace std;
long long l, r, ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> l >> r;
  if (l == r) {
    cout << "0\n";
    return 0;
  }
  long long diff = r - l;
  long long ls;
  for (long long i = 0, j = 1; j <= diff; i++, j *= 2) {
    ls = i;
    ans += j;
  }
  ls++;
  for (long long i = ls, j = (1ll << ls); j <= r; i++, j *= 2) {
    if (((l >> i) ^ (r >> i)) & 1ll == 1ll) ans += j;
  }
  cout << ans << '\n';
  return 0;
}
