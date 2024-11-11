#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, l;
  cin >> n >> k >> l;
  long long int a[100100], i, m;
  m = n * k;
  for (i = 1; i <= m; i++) cin >> a[i];
  sort(a + 1, a + m + 1);
  long long int s = a[1];
  for (i = 2; i <= m; i++) {
    if (a[i] - s > l) break;
  }
  i--;
  if (i < n) {
    cout << 0 << endl;
    return 0;
  }
  long long int sum = 0, j, rem;
  for (j = 1; j <= i;) {
    sum += a[j];
    j += k;
    rem = i - j + 1;
    n--;
    if (rem <= n) break;
  }
  for (j = i;; j--, rem--) {
    if (rem <= 0) break;
    sum += a[j];
  }
  cout << sum << endl;
  return 0;
}
