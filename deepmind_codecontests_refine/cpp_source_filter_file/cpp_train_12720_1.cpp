#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10, mod = 1e9 + 7;
const long long inf = 1e18;
int sm[maxn];
int cnt(int l, int r) { return sm[r] - sm[l - 1]; }
long long f(int m) {
  long long ans = 0;
  for (int i = m; i < maxn; i += m) {
    int l = i, r = min(maxn - 1, i + m - 1);
    ans += 1ll * cnt(l, r) * (i / m);
  }
  return ans;
}
long long g(int m, int xlim, int mlim) {
  long long ans = 0;
  for (int i = m; i < maxn; i += m) {
    int l = max(xlim, i + mlim), r = min(maxn - 1, i + m - 1);
    if (l <= r) ans += cnt(l, r);
  }
  return ans;
}
bool ok1(int x, int y, long long tot) {
  tot = tot - x - ((2 * x) / y);
  if (tot < 0) return 0;
  if (tot > 0) return 2 * x < maxn && cnt(2 * x, maxn - 1) > 0;
  return g(y, 2 * x, (2 * x) % y) > 0;
}
bool ok2(int x, int y, long long tot) {
  tot = tot - x - 2 * (x / y);
  if (tot < 0) return 0;
  if (tot > 1) return cnt(x, maxn - 1) > 1;
  if (tot == 1) return cnt(x, maxn - 1) > 1 && g(y, x, x % y) > 0;
  return g(y, x, x % y) > 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    sm[x]++;
  }
  for (int i = 1; i < maxn; i++) {
    sm[i] += sm[i - 1];
  }
  long long ans = 0;
  long long x = maxn - 3;
  for (int y = 2; y < maxn; y++) {
    long long num = f(y);
    int L = 0, R = x + 1;
    while (R - L > 1) {
      int mid = (L + R) >> 1;
      if (ok1(mid, y, num) || ok2(mid, y, num))
        L = mid;
      else
        R = mid;
    }
    if (L < 2) break;
    x = L;
    ans = max(ans, 1ll * x * y);
  }
  return cout << ans << endl, 0;
}
