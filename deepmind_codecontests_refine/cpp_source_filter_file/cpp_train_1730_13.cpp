#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)(2e6) + 2;
const int mod = (int)(1e9) + 7;
long long ans = 2e18, sum[maxn];
long long n, x, y, cnt[maxn], pref[maxn];
bool u[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> x >> y;
  for (int i = 1, z; i <= n; i++) cin >> z, cnt[z]++, sum[z] += z;
  for (int i = 1; i <= 2e6; i++) {
    pref[i] += pref[i - 1] + cnt[i];
    sum[i] += sum[i - 1];
  }
  int cur = x / y;
  int l, r;
  long long res = 0, tot = 0, part = 0;
  for (int i = 2; i <= 2e6; i++) {
    if (!u[i]) {
      res = 0;
      for (int j = i; j <= 2e6; j += i) {
        u[j] = 1;
        l = j - i + 1, r = j - 1;
        tot = pref[r] - pref[l - 1];
        l = j - cur;
        l = max(l, j - 1);
        part = pref[r] - pref[l - 1];
        res += (tot - part) * x + (part * j - (sum[r] - sum[l - 1])) * y;
      }
      ans = min(ans, res);
    }
  }
  cout << ans;
  return 0;
}
