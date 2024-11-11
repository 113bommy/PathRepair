#include <bits/stdc++.h>
using namespace std;
long long a[100000];
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  long long l = 1;
  long long r = 1000000000000000;
  long long ans = 1000000000000000;
  while (l <= r) {
    long long mid = (l + r) / 2;
    long long s = 0;
    bool f = 0;
    for (int i = 0; i < n; ++i)
      if (mid < a[i]) {
        f = 1;
        break;
      } else
        s += (mid - a[i]);
    if (s >= mid && !f) {
      r = mid - 1;
      ans = min(ans, mid);
    } else
      l = mid + 1;
  }
  cout << ans;
}
