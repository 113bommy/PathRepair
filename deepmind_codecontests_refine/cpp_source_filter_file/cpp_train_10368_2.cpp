#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, q;
  cin >> n;
  long long a[n];
  long long am = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    am += a[i];
  }
  for (long long i = 1; i <= 40; i++) {
    long long ans = 0;
    for (long long j = 0; j < n; j++) {
      if (i * ((a[j] + i) / (i + 1)) > a[j] || a[j] < i)
        ans = 1e18;
      else
        ans += ((a[j] - 1) / (i + 1) + 1);
    }
    am = min(am, ans);
  }
  for (long long sz = 1; sz <= 40000; sz++) {
    long long i = a[0] / sz;
    if (a[0] % sz == 0) {
      long long ans = 0;
      for (long long j = 1; j < n; j++) {
        if (i * ((a[j] + i) / (i + 1)) > a[j] || a[j] < i)
          ans = 1e18;
        else
          ans += ((a[j] - 1) / (i + 1) + 1);
      }
      am = min(am, ans + sz);
      i--;
      ans = 0;
      for (long long j = 1; j < n; j++) {
        if (i * ((a[j] + i) / (i + 1)) > a[j] || a[j] < i)
          ans = 1e18;
        else
          ans += ((a[j] - 1) / (i + 1) + 1);
      }
      am = min(am, ans + sz);
      i++;
    }
    if (i != 0) {
      long long ans = 0;
      for (long long j = 1; j < n; j++) {
        if (i * ((a[j] + i) / (i + 1)) > a[j] || a[j] < i)
          ans = 1e18;
        else
          ans += ((a[j] - 1) / (i + 1) + 1);
      }
      am = min(am, ans + sz);
    }
  }
  cout << am;
  return 0;
}
