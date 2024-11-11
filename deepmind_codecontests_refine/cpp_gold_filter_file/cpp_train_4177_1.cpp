#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[300005];
long long sum[300005];
long long even[300005], odd[300005];
int main(void) {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    long long cnt = 0;
    while (a[i]) cnt += a[i] & 1, a[i] /= 2;
    a[i] = cnt;
  }
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
  for (int i = n; i >= 1; i--) {
    even[i] = even[i + 1], odd[i] = odd[i + 1];
    if (sum[i] % 2 == 0)
      even[i]++;
    else
      odd[i]++;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (sum[i] % 2)
      ans += odd[i + 1];
    else
      ans += even[i + 1];
  }
  for (int i = 1; i <= n; i++) {
    long long s = 0, m = 0;
    for (int j = 0; j < 63; j++) {
      if (i + j > n) break;
      s += a[i + j];
      m = max(m, a[i + j]);
      if (s % 2 == 0 && m > s / 2) ans--;
    }
  }
  cout << ans << endl;
  return 0;
}
