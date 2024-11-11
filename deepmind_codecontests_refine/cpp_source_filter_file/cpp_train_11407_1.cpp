#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
int a[maxn];
long long ct[maxn];
int main() {
  ios::sync_with_stdio(false);
  int n, x;
  cin >> n >> x;
  memset(ct, 0, sizeof ct);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ++ct[a[i]];
  }
  sort(a + 1, a + 1 + n);
  long long ans = 0ll;
  int cnt = unique(a + 1, a + 1 + n) - a - 1;
  for (int i = 1; i <= cnt; ++i) {
    int tmp = (a[i] ^ x);
    if (tmp == a[i]) {
      ans += ct[a[i]] * (ct[a[i]] - 1);
      continue;
    }
    int t = lower_bound(a + i + 1, a + cnt + 1, tmp) - a;
    if (t > cnt) continue;
    if (a[t] == tmp) ans += ct[a[i]] * ct[tmp];
  }
  cout << ans << endl;
  return 0;
}
