#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, cnt = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    long long ans1 = (1LL << 62), ans2 = (1LL << 62), changehobena = 0,
              changehobe = 0, changehobena1 = 0, changehobe1 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i]) {
        changehobena++;
        if (a[i] == '1') changehobena1++;
      } else {
        changehobe++;
        if (a[i] == '1') changehobe1++;
      }
    }
    if ((changehobena & 1) && ((changehobena + 1) / 2) <= changehobena1)
      ans1 = changehobena;
    if ((changehobe & 1 ^ 1) && ((changehobe + 1) / 2) <= changehobe1)
      ans2 = changehobe;
    long long ans = min(ans1, ans2);
    if (ans == (1LL << 62))
      cout << -1 << '\n';
    else
      cout << ans << '\n';
  }
  return 0;
}
