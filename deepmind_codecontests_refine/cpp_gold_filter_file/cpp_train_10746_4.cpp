#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  long long ans = 0;
  for (int j = 0; j < 26; j++) {
    int cal[n];
    for (int i = 0; i < n; i++) {
      cal[i] = arr[i] % (1 << (j + 1));
    }
    sort(cal, cal + n);
    int cnt = 0;
    int tmp = (1 << j);
    for (int i = 0; i < n; i++) {
      int a = tmp - cal[i];
      int c, d;
      if (a > cal[n - 1])
        c = n;
      else
        c = lower_bound(cal, cal + n, a) - cal;
      int b = 2 * tmp - cal[i];
      if (b > cal[n - 1])
        d = n;
      else
        d = lower_bound(cal, cal + n, b) - cal;
      cnt = cnt + (d - c);
      if (i >= c && i <= d - 1) cnt--;
    }
    for (int i = 0; i < n; i++) {
      int a = 3 * tmp - cal[i];
      int c, d;
      if (a > cal[n - 1])
        c = n;
      else
        c = lower_bound(cal, cal + n, a) - cal;
      int b = 4 * tmp - 1 - cal[i];
      if (b > cal[n - 1])
        d = n;
      else
        d = lower_bound(cal, cal + n, b) - cal;
      cnt = cnt + (d - c);
      if (i >= c && i <= d - 1) cnt--;
    }
    cnt /= 2;
    if (cnt % 2) ans += tmp;
  }
  cout << ans << endl;
}
