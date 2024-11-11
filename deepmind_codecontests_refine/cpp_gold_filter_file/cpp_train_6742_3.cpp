#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
  int n, k, l;
  scanf("%d%d%d", &n, &k, &l);
  for (int i = 0; i < n * k; i++) scanf("%d", &a[i]);
  sort(a, a + n * k);
  if (a[(n - 1)] - a[0] > l) {
    cout << 0 << endl;
    return 0;
  }
  int p = 0;
  for (int i = n - 1; i < n * k; i++) {
    if (a[i] - a[0] <= l) {
      p = i;
    }
  }
  int t = 0;
  long long ans = 0;
  int cnt = 0;
  int rest = n * k - (p + 1);
  for (int i = p; i >= 0; i--) {
    if (rest >= (k - 1)) {
      ans += a[i];
      rest -= (k - 1);
    } else if (rest < (k - 1) && rest != 0) {
      t = rest + 1;
      rest = 0;
    } else {
      t++;
      if (t == k) {
        t = 0;
        ans += a[i];
      }
    }
  }
  cout << ans << endl;
  return 0;
}
