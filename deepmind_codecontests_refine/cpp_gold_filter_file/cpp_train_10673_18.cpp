#include <bits/stdc++.h>
using namespace std;
long long n, i, j, a[5000], ans[5000], p[5000], fl, h, q, l, k;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) p[a[j]] = 0;
    for (j = i; j <= n; j++) {
      p[a[j]]++;
      if (p[a[j]] > q || p[a[j]] == q && a[j] < l) {
        q = p[a[j]];
        l = a[j];
      }
      ans[l]++;
    }
    l = 0;
    q = 0;
  }
  cout << ans[1] << " ";
  for (i = 2; i <= n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
