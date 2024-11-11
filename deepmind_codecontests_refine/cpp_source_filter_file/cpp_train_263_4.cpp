#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int maxx = 3e5;
const int inf = 0x3f3f3f3f;
const long long linf = 1e18;
const long long mod = 1e9 + 9;
map<long long, long long> mp;
long long n, l, r, d;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  map<long long, long long>::iterator it;
  while (n--) {
    cin >> l >> d;
    r = l + d - 1;
    it = mp.upper_bound(l);
    if (it == mp.end() || it->second > r) {
      cout << l << " " << r << endl;
      mp[r] = l;
      continue;
    }
    l = 1;
    while (1) {
      r = l + d - 1;
      it = mp.upper_bound(l);
      if (it == mp.end() || it->second > r) {
        cout << l << " " << r << endl;
        mp[r] = l;
        break;
      }
      l = it->first + 1;
    }
  }
  return 0;
}
