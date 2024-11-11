#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  set<pair<int, int> > slen;
  set<pair<int, int> > slef;
  int l = 0, r = 0;
  for (; r < n; r++) {
    if (r == n - 1 || a[r + 1] != a[r]) {
      slef.insert({l, r - l + 1});
      slen.insert({-(r - l + 1), l});
      l = r + 1;
    }
  }
  int ans = 0;
  while ((int)slen.size()) {
    pair<int, int> f = *slen.begin();
    int len = -1 * (f.first), idx = f.second;
    set<pair<int, int> >::iterator it = slef.lower_bound({idx, len}), ir, iz;
    pair<int, int> toleft = {-1, -1}, toright = {-1, -1};
    ir = iz = it;
    if (it != slef.end()) {
      ir++;
      toright = *ir;
    }
    if (it != slef.begin()) {
      iz--;
      toleft = *iz;
    }
    slef.erase({idx, len});
    slen.erase({-len, idx});
    int llen = toleft.second, lidx = toleft.first, rlen = toright.second,
        ridx = toright.first;
    if (lidx >= 0 && ridx >= 0 && a[ridx] == a[lidx]) {
      slef.erase(toright);
      slef.erase(toleft);
      slef.insert({lidx, rlen + llen});
      slen.erase({-rlen, ridx});
      slen.erase({-llen, lidx});
      slen.insert({-rlen - llen, lidx});
    }
    ans++;
  }
  printf("%d\n", ans);
}
