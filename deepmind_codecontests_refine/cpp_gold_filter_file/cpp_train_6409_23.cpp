#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  long long x, s;
  cin >> x >> s;
  vector<long long> a(m), b(m), c(k), d(k);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < k; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < k; i++) {
    cin >> d[i];
  }
  long long time = x * n;
  for (int i = 0; i < m; i++) {
    long long rem = s - b[i];
    if (rem < 0) continue;
    long long ind = -1;
    long long make = n;
    long long l = 0, r = k - 1;
    while (l <= r) {
      long long mid = l + (r - l) / 2;
      if (d[mid] <= rem) {
        ind = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    if (ind != -1) {
      make -= (c[ind]);
    }
    long long temp = make * a[i];
    time = min(temp, time);
  }
  for (int i = 0; i < k; i++) {
    if (d[i] <= s) {
      long long make = 0;
      long long rem = max(make, n - c[i]);
      long long temp = x * rem;
      time = min(time, temp);
    }
  }
  cout << time;
}
