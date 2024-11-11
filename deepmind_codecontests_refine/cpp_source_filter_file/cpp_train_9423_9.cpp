#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 5;
struct BIT {
  long long N;
  vector<long long> bit;
  void init(long long n) {
    N = n;
    bit.assign(n + 1, 0);
  }
  void update(long long idx, long long val) {
    while (idx <= N) {
      bit[idx] += val;
      idx += idx & -idx;
    }
  }
  long long pref(long long idx) {
    long long ans = 0;
    while (idx > 0) {
      ans += bit[idx];
      idx -= idx & -idx;
    }
    return ans;
  }
  long long rsum(long long l, long long r) { return pref(r) - pref(l - 1); }
};
BIT normal, abnormal;
long long n, k, a, b, q;
long long day[maxn];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> k >> a >> b >> q;
  normal.init(n);
  abnormal.init(n);
  while (q--) {
    long long type, d, v;
    cin >> type;
    if (type == 1) {
      cin >> d >> v;
      long long prev = day[d];
      long long curr = prev + v;
      if (curr <= b) {
        normal.update(d, v);
        abnormal.update(d, v);
      } else if (curr > b && curr <= a) {
        normal.update(d, v);
        if (prev < b) abnormal.update(d, b - prev);
      } else if (curr > a) {
        if (prev < a) normal.update(d, a - prev);
        if (curr > b) abnormal.update(d, b - prev);
      }
      day[d] += v;
    } else {
      cin >> d;
      long long ans = abnormal.rsum(1, d - 1) + normal.rsum(d + k, n);
      cout << ans << "\n";
    }
  }
  return 0;
}
