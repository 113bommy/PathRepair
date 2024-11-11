#include <bits/stdc++.h>
using namespace std;
const long long INF = 100000000;
const long long MAXN = 20100;
int n, a[MAXN], ans;
int main() {
  ans = -INF;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int k = 1; k <= n; k++) {
    if (n % k == 0) {
      for (int j = 1; j <= k; j++) {
        long long sum = 0, cnt = 0;
        for (int i = j; i <= n; i += k) {
          cnt++;
          sum += a[i];
        }
        if (sum > ans && cnt >= 3) {
          ans = sum;
        }
      }
    }
  }
  cout << ans;
  return 0;
}
