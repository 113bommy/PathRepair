#include <bits/stdc++.h>
using namespace std;
long long n, m, a[5000], p[5001], i, l, j, mx, ans[5000], mxi;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    mx = 0;
    for (j = i; j < n; j++) {
      p[a[j]]++;
      if (p[a[j]] > mx or (p[a[j]] == mx and a[j] < mxi)) {
        mx = p[a[j]];
        mxi = a[j];
      }
      ans[mxi]++;
    }
    for (j = i + 1; j <= n; j++) p[a[j]] = 0;
  }
  for (i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
