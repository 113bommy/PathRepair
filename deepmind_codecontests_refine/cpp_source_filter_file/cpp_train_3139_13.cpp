#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, h, sm = 0;
  cin >> h >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    sm += v[i];
  }
  long long nc = n, h1 = h;
  for (long long i = 0; i < nc; i++) {
    h1 = h1 + v[i];
    if (h1 <= 0) {
      cout << i + 1;
      return 0;
    }
  }
  if (sm >= 0) {
    for (long long i = 0; i < n; i++) {
      h += v[i];
      if (h <= 0) {
        cout << i + 1;
        return 0;
      }
    }
    cout << -1;
  } else {
    long long r;
    if (h % sm == 0) {
      r = h / sm * n + 1;
    } else {
      r = (h / sm + 1) * n + 1;
    }
    long long l = 0;
    for (long long i = 0; i < 100; i++) {
      bool x = 0;
      long long mid = (l + r) / 2;
      long long cnt = mid / n * sm;
      if (h + cnt <= 0) {
        x = 1;
      }
      for (long long j = 0; j < mid % n; j++) {
        cnt += v[j];
        if (h + cnt <= 0) {
          x = 1;
          break;
        }
      }
      if (mid / n > 0) {
        long long cnt = sm * (mid / n - 1);
        if (h + cnt <= 0) {
          x = 1;
        }
        for (long long j = 0; j < n; j++) {
          cnt += v[j];
          if (h + cnt <= 0) {
            x = 1;
            break;
          }
        }
      }
      if (x) {
        r = mid;
      } else {
        l = mid;
      }
    }
    cout << r;
  }
}
