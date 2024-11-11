#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
long long _10pow(long long x) {
  long long cnt = 0;
  while (x) {
    cnt++;
    x /= 10;
  }
  return cnt;
}
long long ans;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n, k;
  cin >> n >> k;
  long long cnt = 0;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    if (x == 1) {
      cnt++;
    } else {
      if (cnt) {
        a.push_back(-cnt);
        cnt = 0;
      }
      a.push_back(x);
    }
  }
  if (cnt) a.push_back(-cnt);
  n = a.size();
  for (long long i = 0; i < n; i++) {
    long long p = a[i];
    long long s = a[i];
    if (s < 0) {
      p = 1;
      s = abs(s);
      if (k == 1) ans += s;
      for (long long j = i + 1; j < n; j++) {
        if (a[j] < 0) {
          if (p % k) {
            s -= a[j];
            continue;
          }
          long long sum = s += a[i];
          long long left = -a[i];
          long long right = -a[j];
          long long req_sum = p / k;
          for (long long x = 1; x <= -a[i]; x++) {
            long long y = req_sum - sum - x;
            if (y < 1 || y > right) continue;
            ans++;
          }
          s -= a[j];
        } else {
          if (_10pow(p) + _10pow(a[j]) > 16) break;
          p *= a[j];
          s += a[j];
          if (p % k == 0) {
            if (s + a[i] + 1 <= p / k && p / k <= s) {
              ans++;
            }
          }
        }
      }
    } else {
      if (k == 1) ans++;
      for (long long j = i + 1; j < n; j++) {
        if (a[j] < 0) {
          s -= a[j];
          if (p % k == 0) {
            if (s + a[j] + 1 <= p / k && p / k <= s) {
              ans++;
            }
          }
        } else {
          if (_10pow(p) + _10pow(a[j]) > 16) break;
          p *= a[j];
          s += a[j];
          if (p % s == 0 && p / s == k) {
            ans++;
          }
        }
      }
    }
  }
  cout << ans;
  return 0;
}
