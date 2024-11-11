#include <bits/stdc++.h>
using namespace std;
const int INFint = 2e9;
const long long INF = 2e18;
const int MOD = 1e9 + 7;
class SegmentTree {
 public:
  int n;
  vector<int> t;
  int comb(int a, int b) { return a + b; }
  void modify(int pos, int val) {
    for (t[pos += n] += val; pos > 1; pos >>= 1)
      t[pos >> 1] = comb(t[pos], t[pos ^ 1]);
  }
  long long query(int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = comb(res, t[l++]);
      if (r & 1) res = comb(res, t[--r]);
    }
    return res;
  }
  SegmentTree(int n) : n(n) { t.resize(n << 1, 0); }
};
vector<long long> compr, pref;
int n;
long long can(long long mn) {
  SegmentTree sg((int)compr.size());
  long long res = 0;
  for (int i = 0; i <= n; i++) {
    long long r = pref[i] - mn;
    int pos =
        (int)(upper_bound(compr.begin(), compr.end(), r) - compr.begin()) - 1;
    res += sg.query(0, pos + 1);
    pos =
        (int)(lower_bound(compr.begin(), compr.end(), pref[i]) - compr.begin());
    sg.modify(pos, 1);
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  long long k;
  cin >> n >> k;
  vector<int> a(n + 1);
  pref.resize(n + 1);
  compr = {0};
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
    compr.push_back(pref[i]);
  }
  sort(compr.begin(), compr.end());
  compr.resize(unique(compr.begin(), compr.end()) - compr.begin());
  long long l = -INF, r = INF;
  long long ans = 0;
  while (l <= r) {
    long long md = (l + r) / 2;
    if (can(md) >= k) {
      ans = md;
      l = md + 1;
    } else {
      r = md - 1;
    }
  }
  cout << ans;
  fprintf(stderr, "\nTIME = %lf\n", 1.0 * clock() / CLOCKS_PER_SEC);
  ;
  return 0;
}
