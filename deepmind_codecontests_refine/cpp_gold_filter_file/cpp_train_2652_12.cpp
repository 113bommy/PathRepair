#include <bits/stdc++.h>
long long mpow(long long a, long long n, long long mod) {
  long long ret = 1;
  long long b = a;
  while (n) {
    if (n & 1) ret = (ret * b) % mod;
    b = (b * b) % mod;
    n >>= 1;
  }
  return (long long)ret;
}
using namespace std;
int main() {
  int m, t, r, i, j;
  int a[301];
  map<int, int> mp;
  int sched[301], sched1[301];
  memset(sched, -1, sizeof(sched));
  memset(sched1, -1, sizeof(sched1));
  cin >> m >> t >> r;
  for (j = 0; j < m; j++) {
    cin >> a[j];
    mp[a[j]] = j + 1;
    sched1[a[j]] = 2;
  }
  int ans = 0;
  if (a[0] - r + t >= a[0]) {
    for (j = 0; j < r; j++) sched[a[0] - 1 - j + t] = 1;
    int p = r;
    ans += r;
    for (j = a[0]; j <= a[m - 1]; j++) {
      if (sched1[j] == 2) {
        if (p < r) {
          if (mp[j] > 0 && j - (r - p) + t < a[mp[j] - 1]) {
            cout << -1;
            return 0;
          }
          for (int k = 0; k < r - p; k++) {
            sched[j - 1 - k + t] = 1;
          }
          ans += (r - p);
          p = r;
        }
      }
      if (sched[j] == 1) p--;
    }
  } else {
    cout << -1 << endl;
    return 0;
  }
  cout << ans;
  return 0;
}
