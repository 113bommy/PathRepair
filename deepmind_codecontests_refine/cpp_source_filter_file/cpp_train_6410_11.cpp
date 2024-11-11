#include <bits/stdc++.h>
using namespace std;
long long n, m, k, x, y;
int cnt[105][105];
int main() {
  cin >> n >> m >> k >> x >> y;
  long long T;
  if (n == 1) {
    T = m;
    long long maxx = k / T;
    long long minn = k / T;
    if (k % T != 0) maxx++;
    long long ans = minn;
    if (y <= k % T) ans++;
    cout << maxx << " " << minn << " " << ans << endl;
    return 0;
  } else if (n == 2) {
    T = n * m;
    long long maxx = k / T;
    long long minn = k / T;
    if (k % T != 0) maxx++;
    long long ans = minn;
    if (y + x * (n - 1) <= k % T) ans++;
    cout << maxx << " " << minn << " " << ans << endl;
    return 0;
  }
  T = (2 * n - 2) * m;
  long long mul = k / T;
  long long res = k % T;
  long long maxx = 0, minn = 0, ans = 0;
  maxx = mul * 2;
  minn = mul;
  if (x == 1 || x == n)
    ans = mul;
  else
    ans = 2 * mul;
  int mmm = 0;
  long long rrr = res;
  for (int i = 1; i <= n && res > 0; i++) {
    for (int j = 1; j <= m && res > 0; j++) {
      cnt[i][j]++;
      res--;
      if (i == x && j == y) ans++;
    }
  }
  for (int i = n - 1; i >= 2 && res > 0; i--) {
    for (int j = 1; j <= m && res > 0; j++) {
      cnt[i][j]++;
      res--;
      if (i == x && j == y) ans++;
    }
  }
  if (mul != 0) {
    if (rrr <= m)
      mmm = 0;
    else if (rrr > n * m)
      mmm = 2;
    else
      mmm = 1;
  } else {
    if (rrr <= m)
      mmm = 1;
    else if (rrr > n * m)
      mmm = 2;
    else
      mmm = 1;
  }
  maxx += mmm;
  long long min_add = 1000000000000LL;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) min_add = min(min_add, (long long)cnt[i][j]);
  }
  minn += min_add;
  cout << maxx << " " << minn << " " << ans << endl;
  return 0;
}
