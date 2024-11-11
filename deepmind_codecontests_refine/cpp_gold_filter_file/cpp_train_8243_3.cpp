#include <bits/stdc++.h>
using namespace std;
long long n, s, res;
long long a[1000100], b[1000100];
void solve(long long m) {
  for (int i = 1; i <= n; ++i) b[i] = a[i] % m;
  long long w = 0;
  long long ans = 0;
  long long t = 1;
  long long mid = m / 2 + 1;
  long long p;
  for (int i = 1; i <= n; ++i) {
    if (w + b[i] >= m) {
      long long du = w + b[i] - m;
      b[i] = m - w;
      w = 0;
      for (int j = t; j <= i; ++j) {
        if (w < mid && w + b[j] >= mid) {
          p = j;
          break;
        }
        w += b[j];
      }
      for (int j = t; j <= i; ++j) ans += b[j] * abs(p - j);
      b[i] = du;
      t = i;
      w = 0;
    }
    w += b[i];
  }
  res = min(res, ans);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i], s += a[i];
  if (s == 1) {
    cout << "-1";
    return 0;
  }
  res = 1e18;
  for (int i = 2; i <= 1e6; ++i)
    if (s % i == 0) {
      solve(i);
      while (s % i == 0) s = s / i;
    }
  if (s > 1) solve(s);
  cout << res << endl;
}
