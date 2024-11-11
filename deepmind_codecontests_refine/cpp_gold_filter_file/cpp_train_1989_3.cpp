#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n == 1) {
    cout << a[0] + m << ' ' << a[0] + m << endl;
    return 0;
  }
  sort(a, a + n);
  int ans_mx = a[n - 1] + m;
  int i = -1;
  ;
  while (m > 0) {
    for (i = 0; i < n; i++) {
      if (a[i] == a[n - 1]) break;
      if (m > 0) {
        ++a[i], --m;
      }
    }
    if (i == 0 && m > 0) ++a[n - 1], --m;
  }
  int ans_mn = *max_element(a, a + n);
  cout << ans_mn << ' ' << ans_mx << endl;
  return 0;
}
