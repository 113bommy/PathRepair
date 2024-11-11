#include <bits/stdc++.h>
using namespace std;
int a[100010], c[100010], d[100010], cnt;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  c[cnt] = 0;
  d[cnt] = -1;
  int mxer = n + 1;
  for (int i = 0; i < n; i++) {
    if (a[i] > c[cnt]) {
      cnt++;
      c[cnt] = a[d[cnt] = i];
    } else
      mxer = min(mxer, a[i]);
  }
  if (mxer == n + 1) {
    cout << 1 << '\n';
    exit(0);
  }
  d[cnt + 1] = n;
  int mx = 1;
  for (int i = 1; i <= cnt; i++) {
    int tmp = c[i - 1], ct = 0;
    for (int j = d[i] + 1; j < d[i + 1]; j++) {
      if (a[j] > tmp) {
        tmp = a[j];
        ct++;
      }
    }
    if (ct > mx || (ct == mx && c[i] < mxer)) {
      mx = ct;
      mxer = c[i];
    }
  }
  cout << mxer << '\n';
  return 0;
}
