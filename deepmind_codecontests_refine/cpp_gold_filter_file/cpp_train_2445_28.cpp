#include <bits/stdc++.h>
using namespace std;
long long A, B, n;
long long sum_1_to_n(long long r) { return r * (r + 1) / 2; }
long long sum_is(long long l, long long r) {
  return sum_1_to_n(r) - sum_1_to_n(l - 1);
}
long long maxi(long long i) { return A + (i - 1) * B; }
long long sum(long long i, long long j) {
  long long len = j - i + 1;
  return A * len + sum_is(i - 1, j - 1) * B;
}
long long l, t, m;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> A >> B >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l >> t >> m;
    if (maxi(l) > t) {
      cout << -1 << '\n';
      continue;
    }
    long long hi = 1LL << 40, lo = l;
    while (lo < hi) {
      long long mid = (lo + hi + 1) / 2;
      if (maxi(mid) <= t && sum(l, mid) <= t * m)
        lo = mid;
      else
        hi = mid - 1;
    }
    cout << lo << '\n';
  }
  return 0;
}
