#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 5;
const long long linf = 1e18 + 5;
const int N = 1e5 + 5;
int n, a[N], odd, st, h[N];
bool fl(int k) {
  memset(h, 0, sizeof(h));
  int st = k, nd = k + 1;
  if (k < n + 1 >> 1) nd = n - k + 1;
  for (int i = 1; i <= st; i++) h[a[i]]++;
  for (int i = nd; i <= n; i++) h[a[i]]--;
  bool flag = *min_element(h + 1, h + n + 1) >= 0;
  for (int i = st + 1; i <= nd - 1; i++)
    flag &= a[i] == a[nd - 1 - (i - (st + 1))];
  return flag;
}
bool fr(int k) {
  memset(h, 0, sizeof(h));
  int nd = k, st = k - 1;
  if (k > n + 1 >> 1) st = n - k + 1;
  for (int i = nd; i <= n; i++) h[a[i]]++;
  for (int i = 1; i <= st; i++) h[a[i]]--;
  bool flag = *min_element(h + 1, h + n + 1) >= 0;
  for (int i = st + 1; i <= nd - 1; i++)
    flag &= a[i] == a[nd - 1 - (i - (st + 1))];
  return flag;
}
int main() {
  ios ::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    h[a[i]]++;
  }
  for (int i = 1; i <= n; i++) odd += h[i] & 1;
  if (odd != n % 2) return cout << 0 << '\n', 0;
  int st = 1;
  while (st <= n / 2 and a[st] == a[n - st + 1]) st++;
  st--;
  if (st >= n / 2) return cout << (long long)n * (n + 1) / 2 << '\n', 0;
  long long ans = 0;
  int l = 1, r = n;
  while (l < r) {
    int m = l + r >> 1;
    if (fl(m))
      r = m;
    else
      l = m + 1;
  }
  ans += (long long)(st + 1) * (n - l + 1);
  l = 1, r = n;
  while (l + 1 < r) {
    int m = l + r >> 1;
    if (fr(m))
      l = m;
    else
      r = m - 1;
  }
  if (fr(r)) l = r;
  ans += (long long)(st + 1) * l;
  ans -= (long long)(st + 1) * (st + 1);
  cout << ans << '\n';
  return 0;
}
