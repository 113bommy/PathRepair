#include <bits/stdc++.h>
using namespace std;
const long long infl = 1e18 + 5;
long long int m, n, push_back, x, y, k, mx = -1, mn = infl, f, val, sz, sm, cnt,
                                        ans, t = 1, i, j, ind = -1;
long long int a[300004], b, q, l;
map<long long int, long long int> mp;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (fopen("inp.txt", "r")) {
    freopen("myfile.txt", "w", stdout);
    freopen("inp.txt", "r", stdin);
  }
  cin >> b >> q >> l >> m;
  for (i = 0; i < m; i++) {
    cin >> a[i];
    mp[a[i]] = 1;
  }
  val = b;
  for (i = 0; i < 70; i++) {
    if (abs(val) > l) break;
    if (mp.find(val) == mp.end()) ans++;
    val = val * q;
  }
  if (ans == 0) {
    cout << "0";
    return 0;
  }
  if (ans >= 35) {
    cout << "inf";
  } else
    cout << ans;
  return 0;
}
