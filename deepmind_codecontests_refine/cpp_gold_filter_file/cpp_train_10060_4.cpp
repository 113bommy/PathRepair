#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int N = 100 * 1000 + 228;
int a[N], good[N], cnt[N];
struct Fenwick {
  vector<int> t;
  int n;
  Fenwick(int _n) {
    n = _n;
    t.resize(n);
  }
  inline void upd(int i) {
    --i;
    for (; i < n; i = (i | (i + 1))) ++t[i];
  }
  inline int getPref(int i) {
    --i;
    int res = 0;
    while (i >= 0) {
      res += t[i];
      i = (i & (i + 1)) - 1;
    }
    return res;
  }
  inline int get(int l, int r) { return getPref(r) - getPref(l - 1); }
};
signed main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  int was = 0;
  Fenwick fir = Fenwick(n);
  int cur_mx = a[1];
  for (int i = 1; i <= n; ++i) {
    cnt[i] = fir.get(a[i], n);
    fir.upd(a[i]);
    cur_mx = max(cur_mx, a[i]);
    if (a[i] == cur_mx) {
      ++was;
      good[i] = 1;
    }
  }
  int res = 0, ans = n;
  Fenwick f = Fenwick(n);
  for (int i = n; i >= 1; --i) {
    int cur = was;
    if (good[i]) --cur;
    cur += f.get(1, a[i]);
    if (cur > res || (res == cur && a[i] < ans)) {
      res = cur;
      ans = a[i];
    }
    if (cnt[i] == 1) {
      f.upd(a[i]);
    }
  }
  cout << ans << "\n";
  return 0;
}
