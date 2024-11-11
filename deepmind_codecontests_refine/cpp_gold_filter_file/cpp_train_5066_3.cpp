#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  cin >> n >> m;
  long long int a[n], b[m];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i > 0) a[i] += a[i - 1];
  }
  for (int i = 0; i < m; ++i) cin >> b[i];
  for (int i = 0; i < m; ++i) {
    int l = 0, r = n - 1;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (a[mid] == b[i]) {
        l = mid;
        break;
      } else if (a[mid] > b[i]) {
        r = mid;
      } else if (a[mid] < b[i])
        l = mid + 1;
    }
    if (r - l == 1) {
      if (a[r] >= b[i] && a[l] < b[i]) l = r;
    }
    if (l > 0) b[i] -= a[l - 1];
    cout << l + 1 << " " << b[i] << endl;
  }
  return 0;
}
