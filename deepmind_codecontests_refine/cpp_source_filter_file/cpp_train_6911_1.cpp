#include <bits/stdc++.h>
using namespace std;
int f[50], dem[60], cnt[60], a[1000005], x, n, m;
bool check(int mid) {
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i <= 31; ++i) dem[i] = f[i];
  for (int i = 1; i <= mid; ++i) cnt[a[i]]++;
  for (int i = 31; i >= 0; --i) {
    if (dem[i] < cnt[i]) return false;
    dem[i] -= cnt[i];
    if (i) dem[i - 1] += dem[i] * 2;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    for (int i = 0; i <= 31; ++i) {
      if (x & (1 << i)) f[i]++;
    }
  }
  for (int i = 1; i <= m; ++i) cin >> a[i];
  sort(a + 1, a + 1 + m);
  int L = 0, R = m + 1;
  while (R - L > 1) {
    int mid = (L + R) / 2;
    if (check(mid))
      L = mid;
    else
      R = mid;
  }
  cout << L;
  return 0;
}
