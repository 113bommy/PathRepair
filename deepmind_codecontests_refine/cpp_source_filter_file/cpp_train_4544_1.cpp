#include <bits/stdc++.h>
using namespace std;
void amax(long long &a, long long b) { a = max(a, b); }
void amin(long long &a, long long b) { a = min(a, b); }
const long long INF = 5e18;
const long long inf = 5e18;
const long long N = 600001;
void solve() {
  long long n;
  cin >> n;
  long long cntone = n;
  set<pair<long long, long long> > s, bk;
  long long q;
  cin >> q;
  while (q--) {
    long long L, R, k;
    cin >> L >> R >> k;
    if (k == 1) {
      auto it = bk.lower_bound(pair<long long, long long>(L, -INF));
      long long lf = L, rf = R;
      long long pre = L;
      if (it != bk.end() && it->second < L) {
        lf = it->second;
        amax(rf, it->first);
        pre = it->first + 1;
        s.erase(pair<long long, long long>(it->second, it->first));
        bk.erase(it);
      }
      it = s.lower_bound(pair<long long, long long>(L, -inf));
      while (it != s.end()) {
        if (it->first <= R) {
          long long l = it->first, r = it->second;
          cntone -= (l - pre);
          amax(rf, r);
          pre = r + 1;
          bk.erase(pair<long long, long long>(l, r));
          s.erase(it);
          it = s.lower_bound(pair<long long, long long>(L, -inf));
        } else
          break;
      }
      if (pre <= R) {
        cntone -= (R - pre + 1);
      }
      s.insert(pair<long long, long long>(lf, rf));
      bk.insert(pair<long long, long long>(rf, lf));
    } else {
      auto it = s.lower_bound(pair<long long, long long>(L, -inf));
      while (it != s.end()) {
        if (it->first <= R) {
          long long l = it->first, r = it->second;
          bk.erase(pair<long long, long long>(r, l));
          s.erase(it);
          if (r <= R) {
            cntone += r - l + 1;
          } else {
            cntone += R - l + 1;
            s.insert(pair<long long, long long>(R + 1, r));
            bk.insert(pair<long long, long long>(r, R + 1));
          }
          it = s.lower_bound(pair<long long, long long>(L, -inf));
        } else
          break;
      }
      it = bk.lower_bound(pair<long long, long long>(L, -INF));
      if (it != bk.end() && it->second < L) {
        long long l = it->second, r = it->first;
        bk.erase(it);
        s.erase(pair<long long, long long>(l, r));
        s.insert(pair<long long, long long>(l, L - 1));
        bk.insert(pair<long long, long long>(L - 1, l));
        if (r <= R) {
          cntone += r - L + 1;
        } else {
          cntone += R - L + 1;
          s.insert(pair<long long, long long>(R + 1, r));
          bk.insert(pair<long long, long long>(r, R + 1));
        }
      }
    }
    cout << cntone << '\n';
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
}
