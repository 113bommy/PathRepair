#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d;
  cin >> n >> d;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) cin >> vec[i];
  long long ans = 0;
  int l, h, m;
  for (int i = 0; i <= n - 3; i++) {
    if ((vec[i + 1] - vec[i]) < d) {
      l = i + 2;
      h = n - 1;
      while (l <= h) {
        m = l + (h - l) / 2;
        if ((vec[m] - vec[i]) > d) {
          h = m - 1;
        } else {
          if (m == n - 1 || (vec[m + 1] - vec[i]) > d) {
            long long x = (m - i);
            ans += (x * (x - 1)) / 2;
            break;
          }
          l = m + 1;
        }
      }
    }
  }
  cout << ans;
}
