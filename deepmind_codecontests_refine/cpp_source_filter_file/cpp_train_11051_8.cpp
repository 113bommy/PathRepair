#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t = 1;
  while (t--) {
    long long int n, sum = 0, ct = 0, l, r, m, k, ans = 0;
    cin >> n >> m;
    long long int a[n];
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    long long int b[m];
    for (long long int i = 0; i < m; i++) cin >> b[i];
    long long int mi = *min_element(b, b + n);
    long long int ma = *max_element(a, a + n);
    if (ma > mi) {
      cout << -1 << endl;
      continue;
    }
    sort(a, a + n);
    sort(b, b + m);
    reverse(b, b + m);
    long long int ai = a[n - 2];
    for (long long int i = 0; i < m; i++) {
      if (b[i] == ma) {
        ans += sum;
        continue;
      } else if (i != m - 1) {
        long long int tmp = sum;
        tmp -= ma;
        tmp += b[i];
        ans += tmp;
      } else {
        long long int tmp = sum;
        tmp -= ai;
        tmp += b[i];
        ans += tmp;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
