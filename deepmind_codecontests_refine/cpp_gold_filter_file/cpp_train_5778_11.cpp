#include <bits/stdc++.h>
using namespace std;
int t, tr, br, b, bl, tl;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> t >> tr >> br >> b >> bl >> tl;
  long long ans = 0;
  int k = min(tr, tl);
  ans += (2 * t + k) * ((long long)k);
  ans += 2 * (max(tr, tl) - k) * (t + k);
  int a = min(bl, br);
  ans += (2 * b + a) * ((long long)a);
  cout << ans << endl;
  return 0;
}
