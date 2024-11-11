#include <bits/stdc++.h>
using namespace std;
const long long N = (1 << 18);
long long n, q, a[N + 5];
struct data_bit {
  long long bit[N + 5];
  void update(long long pos, long long val) {
    for (; pos < N + 5; pos += pos & -pos) bit[pos] += val;
  }
  long long get(long long pos) {
    long long res = 0;
    for (; pos; pos -= pos & -pos) res += bit[pos];
    return res;
  }
  long long fin(long long sum) {
    if (bit[N] < sum) return -1;
    long long s = 0, p = 0;
    for (long long i = 17; i >= 0; --i) {
      if (s + bit[p | (1 << i)] < sum) {
        s += bit[p | (1 << i)];
        p += (1 << i);
      }
    }
    return p + 1;
  }
} B;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (long long i = 1; i <= n; ++i) cin >> a[i], B.update(i, a[i]);
  while (q--) {
    long long p, x;
    cin >> p >> x;
    B.update(p, -a[p]);
    a[p] = x;
    B.update(p, a[p]);
    if (!a[1]) {
      cout << 1 << '\n';
      continue;
    }
    long long ans = -1, now = a[1];
    while (1) {
      p = B.fin(2 * now);
      if (p == -1) break;
      if (a[p] == B.get(p - 1)) {
        ans = p;
        break;
      }
      now = B.get(p);
    }
    cout << ans << '\n';
  }
  return 0;
}
