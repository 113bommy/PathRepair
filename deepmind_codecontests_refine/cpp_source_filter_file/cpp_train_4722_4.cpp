#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int size[100005];
int main() {
  int k, b, n, a;
  int assign, mod = 0, mods = 0;
  long long ans = 0;
  size[0] = 1;
  mp[0] = 0;
  mods++;
  cin >> k >> b >> n;
  int zero = 0, cost = 0;
  for (int i = 0; i < n; i++) {
    cin >> a;
    zero = (a) ? 0 : zero + 1;
    if (b == k - 1 || b == 0) cost += zero;
    mod = (mod + a) % (k - 1);
    if (mp.find(mod) == mp.end()) mp[mod] = mods++;
    assign = mp[mod];
    int sup = (mod + (k - 1) - b) % (k - 1);
    if (mp.find(sup) == mp.end()) {
      size[assign]++;
      continue;
    }
    sup = mp[sup];
    ans += size[sup];
    size[assign]++;
  }
  if (b == 0)
    cout << cost << endl;
  else
    cout << ans - cost << endl;
  return 0;
}
