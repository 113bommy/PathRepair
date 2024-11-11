#include <bits/stdc++.h>
using namespace std;
int a[1000010];
long long trakm[1000010];
long long tr(int x) {
  if (x < 0) return 0;
  return trakm[x];
}
int main() {
  int n;
  while (cin >> n) {
    long long ans = 0;
    int cnt = 0;
    vector<long long> v;
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
      if (a[i] == 1) {
        v.push_back(i);
      }
    }
    int sz = v.size();
    trakm[0] = v[0];
    for (int i = 1; i < sz; ++i) {
      trakm[i] = trakm[i - 1] + v[i];
    }
    long long st, md, nd;
    ans = 1e18;
    for (int i = 2; i <= sz; ++i) {
      long long tmp = 0;
      if (sz % i) continue;
      for (int j = 0; j < sz / i; ++j) {
        st = i * j;
        nd = i * j + i - 1;
        md = (st + nd) / 2;
        tmp += (tr(nd) - tr(md)) - (nd - md) * tr(md);
        tmp += (-tr(md - 1) + tr(st - 1)) + (md - st) * tr(md);
      }
      ans = min(tmp, ans);
    }
    if (sz == 1)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
