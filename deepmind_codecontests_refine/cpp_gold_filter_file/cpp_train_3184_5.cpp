#include <bits/stdc++.h>
using namespace std;
int a[1111111];
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  long long ts, tf, t;
  cin >> ts >> tf >> t;
  cin >> n;
  long long ansV = ts, ans = 0;
  long long total = ts;
  for (int i = 0; i <= n; i++) {
    long long x;
    if (i == n) {
      x = tf - t + 1;
    } else {
      cin >> x;
    }
    if (x - 1 >= total) {
      if (total + t <= tf) {
        ansV = 0;
        ans = total;
      }
    } else {
      if (total + t <= tf) {
        if (total - (x - 1) < ansV) {
          ansV = total - (x - 1);
          ans = x - 1;
        }
      }
    }
    total = max(total, x) + t;
  }
  cout << ans << endl;
  return 0;
}
