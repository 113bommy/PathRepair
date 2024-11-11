#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
const int INF = 1000000;
int n, x, y, a[N], b[N];
int main() {
  cin >> n;
  fill(a + 1, a + 1001, INF);
  fill(b + 1, b + 1001, INF);
  for (int i = 0; i < 100; i++) {
    for (int j = 1000; j >= 4; j--) {
      a[j] = min(a[j], 1 + a[j - 4]);
    }
    for (int j = 1000; j >= 9; j--) {
      a[j] = min(a[j], 1 + a[j - 9]);
    }
    for (int j = 1000; j >= 49; j--) {
      a[j] = min(a[j], 1 + a[j - 49]);
    }
    for (int j = 1000; j >= 49; j--) {
      b[j] = min(b[j], 1 + b[j - 49]);
    }
    for (int j = 1000; j >= 45; j--) {
      b[j] = min(b[j], 1 + b[j - 45]);
    }
    for (int j = 1000; j >= 40; j--) {
      b[j] = min(b[j], 1 + b[j - 40]);
    }
  }
  if (n <= 20) {
    int ans = 0;
    for (int i = 0; i <= 1000; i++) {
      ans += a[i] <= n;
    }
    cout << ans << '\n';
  } else {
    long long ans = 49LL * n + 1;
    for (int i = 0; i <= 1000; i++) {
      ans -= a[i] == INF;
      ans -= b[i] == INF;
    }
    cout << ans << '\n';
  }
  return 0;
}
