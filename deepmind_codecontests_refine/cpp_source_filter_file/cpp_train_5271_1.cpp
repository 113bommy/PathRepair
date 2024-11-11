#include <bits/stdc++.h>
using namespace std;
int k, n;
int a[300001], d[300001], p[300001];
int main(void) {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  if (2 * k > n) {
    cout << a[n - 1] - a[0];
    return 0;
  }
  for (int i = k - 1; i < 2 * k - 1; i++) {
    d[i] = a[i] - a[0];
    p[i] = 0;
  }
  d[2 * k - 1] = min(a[k - 1] - a[0], a[2 * k - 1] - a[k]);
  d[2 * k - 1] = k;
  for (int i = 2 * k; i < n; i++) {
    d[i] = a[i] - a[0];
    p[i] = 0;
    for (int j = p[i - 1]; j <= i - k + 1; j++) {
      if (max(d[j - 1], a[i] - a[j]) < d[i]) {
        d[i] = max(d[j - 1], a[i] - a[j]);
        p[i] = j;
      }
    }
  }
  cout << d[n - 1];
  return 0;
}
