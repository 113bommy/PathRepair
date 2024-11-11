#include <bits/stdc++.h>
using namespace std;
long long i, j, t, cur, k, n, m, a, b, c, l, r, d, y, h, f, ans,
    pos = -1, arr[300005], sum[300005];
bool check(long long m) {
  for (i = 0; i < n; i++) {
    if (i + m <= n) {
      a = sum[i + m] - sum[i];
      if (a + k >= m) {
        pos = i;
        return true;
      }
    }
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin.tie(NULL);
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sum[0] = 0;
  for (i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + arr[i];
  }
  l = 0;
  r = n;
  m = -1;
  while (m != (l + r) / 2) {
    m = (l + r) / 2;
    if (check(m)) {
      ans = m;
      l = m + 1;
    } else
      r = m;
  }
  cout << ans << endl;
  for (i = 0; i < n; i++) {
    if (pos != -1 && i >= pos && i <= (pos + ans))
      cout << 1 << " ";
    else
      cout << arr[i] << " ";
  }
  return 0;
}
