#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
const long long inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int n;
long long a[maxn];
long long k, st[maxn], sd[maxn];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  a[n] = 0;
  int ti = -1, di = -1;
  for (int i = 0; i < n; i++) {
    if (i == 0)
      st[i] = 0;
    else
      st[i] = st[i - 1] + i * (a[i] - a[i - 1]);
    if (st[i] <= k) ti = i;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (i == n - 1)
      sd[i] = 0;
    else
      sd[i] = sd[i + 1] + (n - i - 1) * (a[i + 1] - a[i]);
    if (sd[i] <= k) di = i;
  }
  if (ti == n - 1 || di == 0)
    cout << "0" << endl;
  else {
    long long ans = inf;
    for (int i = 0; i < n; i++) {
      long long hk = k - sd[n - 1 - i];
      if (hk < 0) break;
      while (st[ti] > hk) ti--;
      hk = (hk - st[ti]) / ti + a[ti];
      ans = min(ans, a[n - 1 - i] - hk);
    }
    for (int i = 0; i < n; i++) {
      long long hk = k - st[i];
      if (hk < 0) break;
      while (sd[di] > hk) di++;
      hk = a[di] - ((hk - sd[di]) / (n - di));
      ans = min(ans, hk - a[i]);
    }
    if (ans < 0) ans = 0;
    cout << ans << endl;
  }
  return 0;
}
