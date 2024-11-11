#include <bits/stdc++.h>
using namespace std;
long long a[101000];
int main() {
  long long n, k;
  scanf("%lld%lld", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  sort(a + 1, a + 1 + n);
  long long ans = a[n] - a[1];
  int l = 1, r = n;
  while (l <= r && ans && (k >= l || k > n - r)) {
    while (a[l] == a[l + 1] && l <= r) l++;
    while (a[r] == a[r - 1] && l <= r) r--;
    ans = a[r] - a[l];
    if (!ans) break;
    long long sum = n - r + 1;
    if (sum <= l) {
      long long z = min(a[r] - a[r - 1], k / sum);
      a[r] -= z;
      k -= sum * z;
    } else {
      long long z = min(a[l + 1] - a[l], k / l);
      a[l] += z, k -= l * z;
    }
    ans = a[r] - a[l];
  }
  cout << ans << endl;
}
