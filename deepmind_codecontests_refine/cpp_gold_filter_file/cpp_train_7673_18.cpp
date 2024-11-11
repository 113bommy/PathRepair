#include <bits/stdc++.h>
using namespace std;
long long n;
pair<long long, long long> po_pr[55];
long double mem[51][51][51];
bool done[51][51][51];
long double dp(long long p = 0, long long free1 = 0, long long free2 = 0,
               long double cur_thr = 0) {
  if (p == n) return 0;
  if (p && po_pr[p].first < po_pr[p - 1].first) {
    free1 += free2;
    free2 = 0;
  }
  long double &ret = mem[p][free1][free2];
  if (done[p][free1][free2]) return ret;
  ret = cur_thr * po_pr[p].second - po_pr[p].first +
        dp(p + 1, free1, free2 + 1, cur_thr);
  if (free1) ret = max(ret, dp(p + 1, free1 - 1, free2, cur_thr));
  done[p][free1][free2] = 1;
  return ret;
}
bool solve(long double x) {
  long double comp = dp(0, 0, 0, x);
  return (comp >= 0);
}
long double BS01D(long double lo, long double hi, int it) {
  long double low = lo, mid, high = hi;
  for (int i_i = 0; i_i < it; i_i++) {
    memset(done, 0, sizeof(done));
    mid = (low + high) / 2.0;
    if (solve(mid) == 1)
      high = mid;
    else
      low = mid;
  }
  return low;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> po_pr[i].first;
  for (long long i = 0; i < n; i++) cin >> po_pr[i].second;
  sort(po_pr, po_pr + n);
  reverse(po_pr, po_pr + n);
  long double ans = ceil(1000.0 * BS01D(0, 1e12, 100));
  cout << (long long)ans;
  return 0;
}
