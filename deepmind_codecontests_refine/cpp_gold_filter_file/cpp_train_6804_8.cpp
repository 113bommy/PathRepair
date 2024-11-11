#include <bits/stdc++.h>
using namespace std;
long long int a[100005];
int main() {
  long long int n, k;
  cin >> n >> k;
  for (long long int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long int mx = 1, ans = a[0], i = 0, j = 0, cnt = 0;
  for (; j < n - 1;) {
    if (mx < j - i + 1) {
      mx = j - i + 1;
      ans = a[j];
    }
    long long int cc = a[j + 1] - a[j];
    cc *= (j - i + 1);
    if (cc + cnt <= k) {
      cnt += cc;
      j++;
    } else {
      cnt -= (a[j] - a[i]);
      i++;
    }
    if (mx < j - i + 1) {
      mx = j - i + 1;
      ans = a[j];
    }
  }
  cout << mx << " " << ans << endl;
  return 0;
}
