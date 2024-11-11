#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long i, j = 0;
    long long a[1001];
    for (i = 0; i < n; i++) cin >> a[i];
    long long cnt[70];
    memset(cnt, 0, sizeof(cnt));
    for (i = 0; i < n; i++) {
      j = 0;
      if (a[i] > 0) {
        while (a[i] > 0) {
          cnt[j] += (a[i] % k);
          a[i] /= k;
          j++;
        }
      }
    }
    long long f = 0;
    for (i = 0; i <= j; i++) {
      if (cnt[i] > 1) {
        f = 1;
        break;
      }
    }
    if (f == 1)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}
