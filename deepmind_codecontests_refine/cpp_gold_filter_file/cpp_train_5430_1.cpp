#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  long long l = 0, h = m;
  long long mid;
  while (l <= h) {
    mid = (l + h) >> 1;
    bool flag = false;
    long long mx = 0;
    for (long long i = 0; i < n; i++) {
      long long t = v[i];
      if (t + mid >= m + mx)
        t = mx;
      else if (t + mid < mx) {
        flag = true;
        break;
      }
      mx = max(mx, t);
    }
    if (l == h) break;
    if (flag)
      l = mid + 1;
    else
      h = mid;
  }
  cout << mid;
}
