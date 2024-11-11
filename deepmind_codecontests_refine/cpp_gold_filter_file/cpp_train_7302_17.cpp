#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  long long s = 0;
  vector<pair<long long, int> > v[64];
  for (int i = 0; i < n; ++i) {
    long long mask, val;
    scanf("%lld%lld", &val, &mask);
    s += val;
    for (int i = 63; i >= 0; --i)
      if ((mask >> i) & 1) {
        v[i].push_back({mask, val});
        break;
      }
  }
  if (s < 0) {
    for (int i = 0; i < 64; ++i)
      for (auto &x : v[i]) x.second *= -1;
  }
  long long res = 0;
  for (int i = 0; i < 64; ++i) {
    s = 0;
    for (auto &x : v[i])
      if (__builtin_popcountll(x.first & res) & 1)
        s -= x.second;
      else
        s += x.second;
    if (s > 0) res |= 1ll << i;
  }
  cout << res << endl;
  return 0;
}
