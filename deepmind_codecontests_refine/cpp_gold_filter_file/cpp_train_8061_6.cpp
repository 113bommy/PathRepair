#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e5 + 1;
const int TMXN = 1048577;
const long long INF = 1e9 + 7;
const long long INFL = 1e18;
long long n, m, all, mink = INFL, ans;
long long a[MXN], b[MXN], pref[MXN], suf[MXN];
long long l, r;
long long solve(long long x) {
  long long j, k;
  ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += max(x - a[i], 0LL);
  }
  for (int i = 1; i <= m; i++) {
    ans += max(b[i] - x, 0LL);
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
  }
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + m);
  for (int i = 1; i <= n; i++) {
    all += a[i];
    pref[i] = all;
  }
  all = 0;
  for (int i = m; i >= 1; i--) {
    all += b[i];
    suf[i] = all;
  }
  l = 0;
  r = INF;
  while (r - l > 5) {
    int mid = l + ((r - l) / 3);
    int mid1 = r - ((r - l) / 3);
    if (solve(mid) < solve(mid1)) {
      r = mid1;
    } else {
      l = mid;
    }
  }
  for (int i = l; i <= r; i++) {
    mink = min(mink + 0LL, solve(i));
  }
  cout << max(mink, 0LL);
  return 0;
}
