#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
const long long Mod = 1000000007;
long long a[maxn];
int s1[maxn], s0[maxn], s[maxn];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  ;
  int n;
  cin >> n;
  int x;
  int cnt0 = 1, cnt1 = 1;
  int j;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    x = 0;
    for (j = 0; j <= 62; j++) {
      if (a[i] & (1ll << j)) x++;
    }
    a[i] = x;
  }
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i];
    if (s[i] % 2 == 0) {
      s0[++cnt0] = i;
    } else {
      s1[++cnt1] = i;
    }
  }
  long long pre, pos;
  long long ans = 0, r, mx;
  for (int i = 1; i <= n; i++) {
    pre = 0;
    r = min(n, i + 65);
    pre = a[i];
    mx = a[i];
    for (j = i + 1; j <= r; j++) {
      pre += a[j];
      mx = max(a[j], mx);
      if (pre % 2 == 0 && 2ll * mx <= pre) ans++;
    }
    r++;
    if (s[i] % 2 == 0) {
      pos = lower_bound(s0 + 1, s0 + cnt0 + 1, r) - s0;
      ans += 1ll * (cnt0 - pos + 1);
    } else {
      pos = lower_bound(s1 + 1, s1 + cnt1 + 1, r) - s1;
      ans += 1ll * (cnt1 - pos + 1);
    }
  }
  cout << ans << endl;
  return 0;
}
