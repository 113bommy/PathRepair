#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int mod = 1e9 + 10;
const int inf = 0x3f3f3f3f;
int a[maxn];
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, d, ans = 0;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) {
      if (d <= 0) break;
      if (a[i] * (i - 1) <= d) {
        a[1] += a[i];
        n -= a[i] * (i - 1);
      } else {
        a[1] += n / (i - 1);
        break;
      }
    }
    cout << a[1] << endl;
  }
  return 0;
}
