#include <bits/stdc++.h>
using namespace std;
long n, m, w, a[500500], f[500500];
long long ans;
bool comp(long a, long b) { return (a < b); }
long long b_s(long h) {
  long long ans = 0, g = 0, cur = 0;
  for (int i = 0; i < n; i++) {
    cur += f[i];
    if (a[i] + cur < h) {
      g = h - (a[i] + cur);
      cur += g;
      f[i + w] -= g;
      ans += g;
    }
  }
  return (ans);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> w;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long l = 0, r = 1000100000, mid;
  long long some;
  while (l < r) {
    for (int i = 0; i < n + 1; i++) {
      f[i] = 0;
    }
    mid = (l + r) / 2;
    some = b_s(mid);
    if (some <= m) ans = max(ans, mid);
    if (some <= m) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  cout << ans;
  return 0;
}
