#include <bits/stdc++.h>
using namespace std;
long long a[300000], b[300000], c[300000];
int main() {
  long long n, k, i, k1, k2, ans = 0, s = 0;
  cin >> n >> k;
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  k1 = a[0];
  k2 = a[n - 1];
  for (i = 0; i < n; i++) b[a[i]]++;
  c[k2 + 1] = 0;
  for (i = k2; i >= 1; i--) c[i] = c[i + 1] + b[i];
  for (i = k2; i >= (1 + a[0]); i--) {
    if ((s + c[i]) > k) {
      ans++;
      s = 0;
      i++;
    } else
      s = s + c[i];
  }
  if (s != 0) ans++;
  cout << ans << endl;
  return 0;
}
