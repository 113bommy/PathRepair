#include <bits/stdc++.h>
using namespace std;
long long L[4], R[4], t, n, x[100010], y[100010], z[100010];
long long ans1, ans2, ans3;
long long check(long long xs) {
  for (long long i = 0; i < 4; i++) {
    L[i] = -9e18, R[i] = 9e18;
  }
  for (long long i = 1; i <= n; i++) {
    L[0] = max(L[0], x[i] + y[i] + z[i] - xs),
    R[0] = min(R[0], x[i] + y[i] + z[i] + xs);
    L[1] = max(L[1], x[i] + y[i] - z[i] - xs),
    R[1] = min(R[1], x[i] + y[i] - z[i] + xs);
    L[2] = max(L[2], x[i] - y[i] + z[i] - xs),
    R[2] = min(R[2], x[i] - y[i] + z[i] + xs);
    L[3] = max(L[3], -x[i] + y[i] + z[i] - xs),
    R[3] = min(R[3], -x[i] + y[i] + z[i] + xs);
  }
  for (long long d = 0; d < 2; d++) {
    long long a = L[1], b = L[2], c = L[3], e = L[0], A = R[1], B = R[2],
              C = R[3], E = R[0];
    if ((a & 1) != d) ++a;
    if ((A & 1) != d) --A;
    if ((b & 1) != d) ++b;
    if ((B & 1) != d) --B;
    if ((c & 1) != d) ++c;
    if ((C & 1) != d) --C;
    if ((e & 1) != d) ++e;
    if ((E & 1) != d) --E;
    if (a > A || b > B || c > C || e > E || a + b + c > E || A + B + C < e) {
      continue;
    }
    long long cur = max(e - a - b - c, 0LL), t;
    t = min(cur, A - a);
    a += t, cur -= t;
    t = min(cur, B - b);
    b += t, cur -= t;
    t = min(cur, C - c);
    c += t, cur -= t;
    if (cur) {
      continue;
    }
    ans1 = (a + b) / 2, ans2 = (c + a) / 2, ans3 = (c + b) / 2;
    return 1;
  }
  return 0;
}
signed main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long i = 1; i <= n; i++) {
      scanf("%lld%lld%lld", &x[i], &y[i], &z[i]);
    }
    long long l = 0, r = 3e18, ans;
    while (l <= r) {
      long long mid = (l + r) >> 1;
      if (check(mid)) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << ans1 << " " << ans2 << " " << ans3 << "\n";
  }
}
